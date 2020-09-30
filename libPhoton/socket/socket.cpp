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

#include <stdexcept>
#include <string>
#include <cerrno>
#include "libPhoton/socket/socket.hpp"
#include "libPhoton/socket/connection.hpp"

// MARK: - Construction

photon::socket::socket(const uint16_t &port)
    : m_addr()
{
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(port);
}

// MARK: - Destruction

photon::socket::~socket()
{
    close();
}

// MARK: - Socket functions

auto photon::socket::listen(const int& max) -> void
{
    if ((m_handle = ::socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        throw std::runtime_error("Unable to acquire new socket file descriptor");
    }

    if (::bind(m_handle, (struct sockaddr*)&m_addr, sizeof(m_addr)) < 0) {
        throw std::runtime_error("Failed to bind to port '" + std::to_string(m_addr.sin_port) + ".");
    }

    if (::listen(m_handle, max) < 0) {
        throw std::runtime_error("Failed to listen on socket. Error Number: " + std::to_string(errno) + "\n");
    }
}

auto photon::socket::accept() -> photon::connection
{
    auto address_len = sizeof(m_addr);
    auto handle = ::accept(m_handle, (struct sockaddr *)&m_addr, (socklen_t *)&address_len);

    if (handle < 0) {
        throw std::runtime_error("Failed to grab connection from socket. Error Number: " + std::to_string(errno) + ".");
    }

    return photon::connection(handle);
}

auto photon::socket::close() -> void
{
    if (m_handle == -1) {
        return;
    }

    ::close(m_handle);
    m_handle = -1;
}