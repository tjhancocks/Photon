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


#if !defined(PHOTON_RESPONSE_HPP)
#define PHOTON_RESPONSE_HPP

#include <string>
#include <map>
#include "libPhoton/http/status_code.hpp"
#include "libPhoton/socket/connection.hpp"

namespace photon::http
{

    class response
    {
    private:
        bool m_sent { false };
        photon::connection m_connection;
        photon::http::status_code m_status { ok };
        std::string m_reason { "Success" };
        std::map<std::string, std::string> m_headers;

    public:
        explicit response(photon::connection& conn);

        auto set_status(const photon::http::status_code& code, const std::string& reason) -> void;
        auto set_header(const std::string& header, const std::string& value) -> void;

        auto send() -> void;
    };

}

#endif //PHOTON_RESPONSE_HPP
