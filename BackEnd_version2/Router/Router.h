#ifndef ROUTER_H
#define ROUTER_H

#include "../Client/Client.h"
#include "../crow_all.h"
#include "../Command_Type/Command_Type.h"
#include <string>
#include <iostream>
#include <unordered_map> // Thêm thư viện này

class Router {
private:
    Client& client;
    crow::SimpleApp app;
    int port;

    // Khai báo map để lưu trữ các client
    std::unordered_map<std::string, std::shared_ptr<Client>> clients;

public:
    Router(Client &client, int port);

    void start();
    void create_router_for_signup();
    void create_router_for_login();
};

#endif // ROUTER_H
