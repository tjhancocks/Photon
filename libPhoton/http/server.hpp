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


#if !defined(PHOTON_SERVER_HPP)
#define PHOTON_SERVER_HPP

#include <vector>
#include "libPhoton/socket/socket.hpp"
#include "libPhoton/http/resource.hpp"

namespace photon::http
{

    class server
    {
    private:
        photon::socket m_socket;
        std::vector<photon::http::resource> m_resources;
        bool m_alive { true };

        auto handle_connection(photon::connection& connection) -> void;

    public:
        explicit server(const uint16_t& port = 8081);
        ~server();

        auto start() -> void;

        auto add_resource(const photon::http::resource& resource) -> void;

    };

}

#endif //PHOTON_SERVER_HPP
