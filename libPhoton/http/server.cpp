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

#include <iostream>
#include "libPhoton/http/server.hpp"
#include "libPhoton/socket/connection.hpp"
#include "libPhoton/http/request.hpp"

// MARK: - Construction

photon::http::server::server(const uint16_t &port)
    : m_socket(port)
{
}

// MARK: - Destruction

photon::http::server::~server()
{
    m_socket.close();
}

// MARK: - Connection Management

auto photon::http::server::start() -> void
{
    m_socket.listen();
    while (m_alive) {
        auto request = m_socket.accept();
        handle_connection(request);
    }
}

auto photon::http::server::handle_connection(photon::connection &connection) -> void
{
    // Request
    auto request = photon::http::request(connection);

    // Find a resource to handle this request.
    for (const auto& resource : m_resources) {
        if (resource.will_accept(request)) {
            // tell the resource to handle the request
            return;
        }
    }

    // 404 Response. No resource to handle the request
    auto& response = request.response();
    response.set_status(not_found, "Resource not found");
    response.send();

    // Finish
    connection.close();
}

// MARK: - Resources

auto photon::http::server::add_resource(const photon::http::resource &resource) -> void
{
    m_resources.emplace_back(resource);
}

