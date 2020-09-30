#include <libPhoton/http/server.hpp>
#include <iostream>

auto main(int argc, const char *argv[]) -> int
{
    photon::http::server s { 8081 };
    s.start();

    return 0;
}