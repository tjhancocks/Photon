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


#if !defined(PHOTON_METHOD_HPP)
#define PHOTON_METHOD_HPP

#include <vector>
#include <string>

namespace photon::http::method
{
    constexpr const char *GET { "GET" };
    constexpr const char *POST { "POST" };
    constexpr const char *PUT { "PUT" };
    constexpr const char *PATCH { "PATCH" };
    constexpr const char *DELETE { "DELETE" };
    constexpr const char *HEAD { "HEAD" };
    constexpr const char *TRACE { "TRACE" };
    constexpr const char *OPTIONS { "OPTIONS" };

    static inline auto all() -> std::vector<std::string>
    {
        return {
            { GET }, { POST }, { PUT }, { PATCH }, { DELETE }, { HEAD }, { TRACE }, { OPTIONS }
        };
    }
}

#endif //PHOTON_METHOD_HPP
