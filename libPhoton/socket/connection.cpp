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

#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "libPhoton/socket/connection.hpp"

// MARK: - Construction

photon::connection::connection(const int &handle)
    : m_handle(handle)
{

}

// MARK: - Destruction

photon::connection::~connection()
{
//    close();
}

// MARK: - Connection Management

auto photon::connection::close() -> void
{
    if (m_handle == -1) {
        return;
    }

    ::close(m_handle);
    m_handle = -1;
}

auto photon::connection::read(const int &length) const -> std::string
{
    auto buffer = std::vector<char>(length);
    auto bytes_read = ::read(m_handle, &buffer[0], length);
    return std::string(buffer.begin(), buffer.end());
}

auto photon::connection::write(const std::string &payload) const -> void
{
    ::send(m_handle, payload.c_str(), payload.size(), 0);
}

// MARK: - Locking

auto photon::connection::lock() -> void
{
    m_locks++;
}

auto photon::connection::unlock() -> void
{
    m_locks--;
}