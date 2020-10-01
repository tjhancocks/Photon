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

#include "libPhoton/ui/page.hpp"

// MARK; - Construction

photon::web::ui::page::page(std::string title)
    : m_title(std::move(title))
{

}

// MARK: - Rendering

auto photon::web::ui::page::render() const -> std::shared_ptr<node>
{
    std::vector<std::shared_ptr<node>> content;
    for (const auto& child : children()) {
        content.emplace_back(child->render());
    }

    return std::make_shared<tag>("html", std::vector<std::shared_ptr<node>>({
        std::make_shared<tag>("head", std::vector<std::shared_ptr<node>>({
            std::make_shared<tag>("title", std::vector<std::shared_ptr<node>>({
                std::make_shared<text>(m_title)
            }))
        })),
        std::make_shared<tag>("body", std::vector<std::shared_ptr<node>>(content))
    }));
}
