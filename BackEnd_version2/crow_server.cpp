#include "crow_all.h"

void start_client() {
    int ret = std::system("./client &"); // Chạy client dưới dạng nền
    if (ret != 0) {
        std::cerr << "Lỗi khi chạy client!" << std::endl;
    } else {
        std::cout << "Client đã được khởi động thành công." << std::endl;
    }
}

void start_crow_server() {
    crow::SimpleApp app;

    // Định nghĩa route khi người dùng truy cập vào localhost:3000
    CROW_ROUTE(app, "/")
    ([]() {
        start_client();
        return "Frontend is loaded. Client started!";
    });

    app.port(3002).run();
}

int main() {
    start_crow_server();  // Chạy Crow server
    return 0;
}