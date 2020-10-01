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

#if !defined(PHOTON_INSTANCE_HPP)
#define PHOTON_INSTANCE_HPP

#include <string>
#include <map>
#include <functional>
#include "libPhoton/http/resource.hpp"
#include "libPhoton/http/response.hpp"

namespace photon::http
{

    class instance
    {
    private:
        std::map<std::string, std::string> m_parameters;
        photon::http::resource::handler_fn m_handler;
        photon::http::status_code m_status { ok };
        std::string m_status_reason { "Success" };
        std::string m_body;

    public:
        explicit instance(std::map<std::string, std::string> params, photon::http::resource::handler_fn handler);

        [[nodiscard]] auto parameter(const std::string& name) const -> std::string;

        auto set_return_status(const photon::http::status_code& status, const std::string& message) -> void;
        auto set_body(const std::string& body) -> void;

        auto build_response(photon::http::response& response) -> void;
    };

}

#endif //PHOTON_INSTANCE_HPP
