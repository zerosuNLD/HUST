#include "../Router.h"

void Router::create_router_for_signup() {
    CROW_ROUTE(app, "/signup")
      .methods("POST"_method, "OPTIONS"_method)([this](const crow::request &req) {
        crow::response res;
        if (req.method == "OPTIONS"_method) {
            res.set_header("Access-Control-Allow-Origin", "*");
            res.set_header("Access-Control-Allow-Methods", "POST, OPTIONS");
            res.set_header("Access-Control-Allow-Headers", "Content-Type");
            res.code = 204;
            return res;
        }

        auto json_body = crow::json::load(req.body);
        if (!json_body) {
            res = crow::response(400, "Invalid JSON");
            res.set_header("Access-Control-Allow-Origin", "*");
            return res;
        }

        std::string username = json_body["username"].s();
        std::string password = json_body["password"].s();
        std::string request_str = "SIGNUP " + username + " " + password;
        std::string success = client.send_request(request_str);

        std::cout << "Phản hồi từ server: " << success << std::endl;
        res.set_header("Access-Control-Allow-Origin", "*");
        return res;
      });
}