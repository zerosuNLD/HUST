#include "Router.h"

// Hàm thiết lập tất cả các route
void setupRoutes(crow::SimpleApp& app, Client& client, const std::string& request) {
    if (request == "Signup") {
        create_router_for_signup(app, client);
    } else if (request == "Login") {
        create_router_for_login(app, client);
    } else {
        // Xử lý trường hợp không xác định, ví dụ:
        std::cerr << "Unknown request type: " << request << std::endl;
    }
}

// Hàm tạo route cho đăng ký
void create_router_for_signup(crow::SimpleApp& app, Client& client) {
    CROW_ROUTE(app, "/signup").methods("POST"_method, "OPTIONS"_method)([&client](const crow::request& req) {
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
        cout << username << " " << password << endl;
        std::string success = client.send_request(request_str);

        cout << "Phản hồi từ server: " << success << endl;
        res.set_header("Access-Control-Allow-Origin", "*");
        return res;
    });
}

// Hàm tạo route cho đăng nhập
void create_router_for_login(crow::SimpleApp& app, Client& client) {
    CROW_ROUTE(app, "/login").methods("POST"_method, "OPTIONS"_method)([&client](const crow::request& req) {
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
        std:string success = client.send_request(request_str);

        cout << "Phản hồi từ server: " << success << endl;
        res.set_header("Access-Control-Allow-Origin", "*");
        return res;
    });
}
