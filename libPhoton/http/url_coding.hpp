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

#if !defined(PHOTON_URL_CODING_HPP)
#define PHOTON_URL_CODING_HPP

#include <string>
#include <map>

namespace photon::http::url
{

    static inline auto encode(const std::string& url) -> std::string
    {
        return url;
    }

    static inline auto decode(const std::string& url) -> std::string
    {
        std::string result;
        for (auto i = url.begin(); i != url.end(); ++i) {
            if ((*i) == '%' && ishexnumber(*(i + 1))) {
                // We're looking at a percent escape, read out the numeric value and replace with the appropriate
                // character.
                std::string value { *++i, *++i };
                if (value == "20") {
                    result.append(" ");
                }
                else if (value == "21") {
                    result.append("!");
                }
                else if (value == "22") {
                    result.append("\"");
                }
                else if (value == "23") {
                    result.append("#");
                }
                else if (value == "24") {
                    result.append("$");
                }
                else if (value == "25") {
                    result.append("%");
                }
                else if (value == "26") {
                    result.append("&");
                }
                else if (value == "27") {
                    result.append("'");
                }
                else if (value == "28") {
                    result.append("(");
                }
                else if (value == "29") {
                    result.append(")");
                }
                else if (value == "2A") {
                    result.append("*");
                }
                else if (value == "2B") {
                    result.append("+");
                }
                else if (value == "2C") {
                    result.append(",");
                }
                else if (value == "2D") {
                    result.append("-");
                }
                else if (value == "2E") {
                    result.append(".");
                }
                else if (value == "2F") {
                    result.append("/");
                }
                else if (value == "5B") {
                    result.append("[");
                }
                else if (value == "5C") {
                    result.append("\\");
                }
                else if (value == "5D") {
                    result.append("]");
                }
                else if (value == "5E") {
                    result.append("^");
                }
                else if (value == "5F") {
                    result.append("_");
                }
                else if (value == "60") {
                    result.append("`");
                }
                else if (value == "7B") {
                    result.append("{");
                }
                else if (value == "7C") {
                    result.append("|");
                }
                else if (value == "7D") {
                    result.append("}");
                }
                else if (value == "7E") {
                    result.append("~");
                }
            }
            else {
                result += (*i);
            }
        }
        return result;
    }

}

#endif //PHOTON_URI_CODING_HPP
