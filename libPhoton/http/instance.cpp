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

#include <utility>
#include "libPhoton/http/instance.hpp"

// MARK: - Construction

photon::http::instance::instance(std::map<std::string, std::string> params, photon::http::resource::handler_fn handler)
    : m_parameters(std::move(params)), m_handler(std::move(handler))
{

}

// MARK: - Handler

auto photon::http::instance::build_response(photon::http::response& response) -> void
{
    m_handler(*this);
    response.set_body(m_body);
    response.set_status(m_status, m_status_reason);
    response.send();
}

// MARK: - Accessors

auto photon::http::instance::parameter(const std::string &name) const -> std::string
{
    return m_parameters.at(name);
}

auto photon::http::instance::set_return_status(const photon::http::status_code& status, const std::string& message) -> void
{
    m_status = status;
    m_status_reason = message;
}

auto photon::http::instance::set_body(const std::string& body) -> void
{
    m_body = body;
}
