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


#if !defined(PHOTON_RESOURCE_HPP)
#define PHOTON_RESOURCE_HPP

#include <map>
#include <string>
#include <functional>
#include <memory>
#include <tuple>
#include "libPhoton/http/method.hpp"
#include "libPhoton/http/request.hpp"
#include "libPhoton/http/status_code.hpp"

namespace photon::http
{

    class instance;

    class resource
    {
    public:
        typedef std::function<auto(instance&)->void> handler_fn;

    private:
        std::string m_uri_pattern;
        std::string m_method;
        handler_fn m_handler;

    public:
        resource(std::string uri, std::string method, handler_fn body);

        [[nodiscard]] auto start_instance(const photon::http::request& request) const -> std::shared_ptr<photon::http::instance>;
    };

}

#endif //PHOTON_RESOURCE_HPP
