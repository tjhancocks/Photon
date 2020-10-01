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

#if !defined(PHOTON_HTML_HPP)
#define PHOTON_HTML_HPP

#include <string>
#include <vector>
#include <map>

namespace photon::web::ui
{

    struct node
    {
        [[nodiscard]] virtual auto render() const -> std::string
        {
            return "";
        };
    };


    struct text: public node
    {
    private:
        std::string m_value;

    public:
        explicit text(std::string value);

        [[nodiscard]] auto render() const -> std::string override;
    };


    struct tag: public node
    {
    private:
        std::string m_id;
        std::string m_name;
        std::map<std::string, std::string> m_style;
        std::map<std::string, std::string> m_attributes;
        std::vector<std::shared_ptr<node>> m_children;

    public:
        explicit tag(std::string name);
        tag(std::string name, std::vector<std::shared_ptr<node>> children);
        tag(std::string name, std::vector<std::shared_ptr<node>> children, std::map<std::string, std::string> attrs);

        auto set_style(const std::string& field, const std::string& value) -> void;

        [[nodiscard]] auto render() const -> std::string override;
    };

}

#endif //PHOTON_HTML_HPP
