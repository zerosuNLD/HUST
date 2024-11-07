#include "Router.h"

Router::Router(Client &client, int port) : client(client), port(port) {}

void Router::start() {
    create_router_for_login();
    create_router_for_signup();
    app.port(port).multithreaded().run();
}
