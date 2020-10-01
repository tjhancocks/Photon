#include <libPhoton/http/server.hpp>
#include <iostream>

auto main(int argc, const char *argv[]) -> int
{
    photon::http::server s { 8080 };

    s.add_resource("hello/:name", photon::http::method::GET, [] (photon::http::instance& instance) {
        instance.set_body("<b>Hello, " + instance.parameter("name") + "</b>");
    });

    s.start();
    return 0;
}