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
#include "libPhoton/ui/html.hpp"

static int id = 0;

// MARK: - Text Node

photon::web::ui::text::text(std::string value)
    : m_value(std::move(value))
{

}

auto photon::web::ui::text::render() const -> std::string
{
    return m_value;
}

// MARK: - Tag

photon::web::ui::tag::tag(std::string name)
    : m_name(std::move(name)), m_children(), m_attributes(), m_id("N" + std::to_string(id++))
{

}

photon::web::ui::tag::tag(std::string name, std::vector<std::shared_ptr<node>> children)
    : m_name(std::move(name)), m_children(std::move(children)), m_attributes(), m_id("N" + std::to_string(id++))
{

}

photon::web::ui::tag::tag(std::string name, std::vector<std::shared_ptr<node>> children, std::map<std::string, std::string> attrs)
    : m_name(std::move(name)), m_children(std::move(children)), m_attributes(std::move(attrs)), m_id("N" + std::to_string(id++))
{

}

auto photon::web::ui::tag::render() const -> std::string
{
    std::string result { "<" + m_name + " id=\"" + m_id + "\"" };

    if (!m_attributes.empty()) {
        for (const auto& attr : m_attributes) {
            result.append(" " + attr.first + "=\"" + attr.second + "\"");
        }
    }

    if (m_children.empty()) {
        result.append("/>");
    }
    else {
        result.append(">");
        for (const auto& child : m_children) {
            result.append(child->render());
        }
        result.append("</" + m_name + ">");
    }

    return result;
}

auto photon::web::ui::tag::set_style(const std::string& field, const std::string& value) -> void
{
    m_style[field] = value;
}
