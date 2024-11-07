#ifndef ROUTER_H
#define ROUTER_H

#include "../crow_all.h"  
#include "../Client/client.h"

// Khai báo các hàm để tạo route
void setupRoutes(crow::SimpleApp& app, Client& client, const std::string& request);

// Khai báo hàm tạo route cho SIGNUP
void create_router_for_signup(crow::SimpleApp& app, Client& client);

void create_router_for_login(crow::SimpleApp& app, Client& client);


#endif // ROUTER_H
