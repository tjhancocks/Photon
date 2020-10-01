// Copyright (c) 2020 Tom Hancocks
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "libPhoton/http/request.hpp"
#include "libPhoton/util/strings.hpp"

// MARK: - Construction

photon::http::request::request(photon::connection& conn)
    : m_response(conn)
{
    auto body = conn.read(4096);
    parse_request(body);
}

// MARK: - Accessors

auto photon::http::request::path() const -> std::string
{
    return m_path;
}

auto photon::http::request::method() const -> std::string
{
    return m_method;
}

// MARK: - Request

auto photon::http::request::parse_request(const std::string &body) -> void
{
    // Parse the request, line by line.
    std::stringstream stream { body };
    std::string line;
    std::string payload;
    int line_count = 0;
    bool headers { true };

    while (std::getline(stream, line, '\n')) {
        // If the line is empty, then we're switching from parsing headers, to consuming the
        // payload.
        line = utils::trim(utils::trim(line, ' '), '\r');

        if (line.empty() && headers) {
            headers = false;
        }
        else if (headers) {
            if (!parse_request_line(line, line_count++)) {
                // Parsing the line failed. Build an error response and send it.
                m_response.send();
            }
        }
        else {
            payload.append(line + "\n");
        }

    }
}

auto photon::http::request::parse_request_line(const std::string &line, const int& number) -> bool
{
    if (number == 0) {
        // The request information line contains the method, path and version.
        auto components = utils::split(line, " ");

        // Determine the request type - is it valid?
        for (const auto& method : method::all()) {
            if (method == components[0]) {
                m_method = method;
            }
        }
        if (m_method.empty()) {
            m_response.set_status(bad_request, "Malformed Request");
            m_response.set_header("X-Photon-Error", "Unsupported method: " + components[0]);
            return false;
        }

        // Check the version. We only support version HTTP/1.1
        if (components[2] != "HTTP/1.1") {
            m_response.set_status(http_version_not_supported, "Version Unsupported");
            m_response.set_header("X-Photon-Error", "The HTTP version used is not supported.");
            return false;
        }

        // Extract the path
        m_path = components[1];
    }
    else {
        // Determine the header name and the value.
        auto pair = utils::split(line, ":");
        auto name = utils::trim(pair[0], ' ');
        auto value = utils::trim(pair[1], ' ');

        m_headers[name] = value;
    }

    return true;
}

auto photon::http::request::response() -> photon::http::response&
{
    return m_response;
}

