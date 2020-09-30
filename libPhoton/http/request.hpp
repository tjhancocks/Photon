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


#if !defined(PHOTON_REQUEST_HPP)
#define PHOTON_REQUEST_HPP

#include <map>
#include <string>
#include <utility>
#include "libPhoton/socket/connection.hpp"
#include "libPhoton/http/method.hpp"
#include "libPhoton/http/response.hpp"

namespace photon::http
{

    struct request
    {
    private:
        photon::http::response m_response;
        std::map<std::string, std::string> m_headers {};
        std::string m_method { "" };
        std::string m_path { "" };

        auto parse_request(const std::string& line) -> void;
        auto parse_request_line(const std::string& line, const int& number) -> bool;

    public:
        explicit request(photon::connection& conn);

        auto path() const -> std::string;
        auto method() const -> std::string;

        auto response() -> photon::http::response&;

    };

}

#endif //PHOTON_REQUEST_HPP
