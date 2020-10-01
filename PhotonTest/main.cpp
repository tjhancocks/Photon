#include <libPhoton/http/server.hpp>
#include <libPhoton/ui/page.hpp>
#include <iostream>

auto main(int argc, const char *argv[]) -> int
{
    photon::http::server s { 8080 };

    s.add_resource("hello/:name", photon::http::method::GET, [] (photon::http::instance& instance) {
        photon::web::ui::page page("Name Greeting");
        instance.set_html_node(page.render());
    });

    s.start();
    return 0;
}