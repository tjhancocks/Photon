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


#include "libPhoton/http/resource.hpp"

#include <utility>

// MARK: - Construction

photon::http::resource::resource(std::string uri, std::string method)
    : m_uri_pattern(std::move(uri)), m_method(std::move(method))
{

}

// MARK: - Checks

auto photon::http::resource::will_accept(const photon::http::request& request) const -> bool
{
    // Parse through the URI and match it.
    std::map<std::string, std::string> parameters;
    std::map<std::string, std::string> query;

    std::string parameter_name;
    std::string parameter_value;

    auto in_query = false;

    for (auto i = m_uri_pattern.begin(); i != m_uri_pattern.end(); ++i) {
        if ((*i) == ':') {
            // We're at the start of a query parameter.
        }
    }

    return false;
}