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
#include <iostream>
#include "libPhoton/http/resource.hpp"
#include "libPhoton/util/strings.hpp"
#include "libPhoton/http/instance.hpp"
#include "libPhoton/http/url_coding.hpp"


// MARK: - Construction

photon::http::resource::resource(std::string uri, std::string method, photon::http::resource::handler_fn handler)
    : m_uri_pattern(std::move(uri)), m_method(std::move(method)), m_handler(std::move(handler))
{

}

// MARK: - Checks

auto photon::http::resource::start_instance(const photon::http::request& request) const -> std::shared_ptr<photon::http::instance>
{
    // Parse through the URI and match it.
    std::map<std::string, std::string> parameters;
    std::map<std::string, std::string> query;
    auto in_query = false;

    auto request_path_raw = request.path();
    if (request_path_raw[0] == '/') {
        request_path_raw.erase(0, 1);
    }

    // Split the URI in to two portions. The path (before the first ?) and the query string (after the first ?).
    auto request_path = url::decode(utils::before_first(request_path_raw, '?'));
    auto pattern_path_components = utils::split(utils::before_first(m_uri_pattern, '?'), "/");
    auto request_path_components = utils::split(request_path, "/");
    auto request_query = utils::after_first(request_path_raw, '?');

    // Validate the path...
    if (pattern_path_components.size() != request_path_components.size()) {
        return nullptr;
    }

    for (auto i = 0; i < pattern_path_components.size(); ++i) {
        auto &pattern_component = pattern_path_components[i];
        const auto &uri_component = request_path_components[i];

        if (pattern_component[0] == ':') {
            pattern_component.erase(0, 1);
            parameters[pattern_component] = uri_component;
        }
        else if (pattern_component != uri_component) {
            return nullptr;
        }
    }

    // At this point the path has been validated and we can continue on to parse the query string.
    // TODO: Parse out the query string into a set of arguments.

    return std::make_shared<photon::http::instance>(parameters, m_handler);
}
