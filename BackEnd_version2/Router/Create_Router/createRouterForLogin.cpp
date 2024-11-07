#include "../Router.h"

void Router::create_router_for_login() {
  CROW_ROUTE(app, "/login")
      .methods("POST"_method,
               "OPTIONS"_method)([this](const crow::request &req) {
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
        std::string request_str = "LOGIN " + username + " " + password;
        std::string response = client.send_request(request_str);

        std::cout << "Phản hồi từ server: " << response << std::endl;

        if (response.find("SUCCESS") != std::string::npos) {
          res = crow::response(200, "{\"message\": \"Login successful\"}");
        } else {
          res = crow::response(401, "{\"message\": \"" + response + "\"}");
        }

        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Content-Type", "application/json");
        return res;
      });
}
