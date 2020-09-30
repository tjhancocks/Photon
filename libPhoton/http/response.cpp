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

#include "libPhoton/http/response.hpp"

// MARK: - Construction

photon::http::response::response(photon::connection &conn)
    : m_connection(conn)
{

}

// MARK: - Headers

auto photon::http::response::set_header(const std::string &header, const std::string &value) -> void
{
    m_headers[header] = value;
}

// MARK: - Send

auto photon::http::response::send() -> void
{
    if (m_sent) {
        // TODO: Warn about multiple sends...
        return;
    }

    // Build the payload first...
    std::string payload;

    payload.append("HTTP/1.1 " + std::to_string(m_status) + " " + m_reason + "\r\n");

    for (const auto& header : m_headers) {
        payload.append(header.first + ": " + header.second + "\r\n");
    }

    payload.append("\r\n");

    // Send the payload...
    m_connection.write(payload);
    m_sent = true;
}

auto photon::http::response::set_status(const photon::http::status_code &code, const std::string &reason) -> void
{
    m_status = code;
    m_reason = reason;
}
