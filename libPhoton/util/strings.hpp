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

#if !defined(PHOTON_STRINGS_HPP)
#define PHOTON_STRINGS_HPP

#include <string>
#include <vector>

namespace photon::utils
{

    static inline auto trim(const std::string& str, const char& c) -> std::string
    {
        if (str.length() == 1 && str[0] == c) {
            return "";
        }

        auto first = str.find_first_not_of(c);
        if (first == std::string::npos) {
            return str;
        }
        auto last = str.find_last_not_of(c);
        return str.substr(first, (last - first + 1));
    }

    static inline auto before_first(const std::string& str, const char& c) -> std::string
    {
        if (str.length() == 1) {
            if (str[0] == c) {
                return "";
            }
            else {
                return str;
            }
        }

        auto first = str.find_first_of(c);
        if (first == std::string::npos) {
            return str;
        }

        return str.substr(0, first);
    }

    static inline auto after_first(const std::string& str, const char& c) -> std::string
    {
        if (str.length() == 1) {
            return "";
        }

        auto first = str.find_first_of(c);
        if (first == std::string::npos) {
            return "";
        }

        return str.substr(first + 1, str.length() - first);
    }

    static inline auto split(const std::string& str, const std::string& delimiter) -> std::vector<std::string>
    {
        auto s = str;
        std::size_t pos = 0;
        std::vector<std::string> v;

        while ((pos = s.find(delimiter)) != std::string::npos) {
            v.emplace_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.length());
        }
        v.emplace_back(s);

        return v;
    }
}

#endif //PHOTON_STRINGS_HPP
