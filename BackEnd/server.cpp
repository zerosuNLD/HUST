#include "Server/server.h"
#include <csignal>
#include <unistd.h> 

// Biến toàn cục cho server
Server* global_server = nullptr;

// Hàm xử lý tín hiệu SIGINT
void handle_sigint(int signum) {
    std::cout << "\nĐang đóng server...\n";
    if (global_server) {
        delete global_server; // Giải phóng tài nguyên của server
    }
    exit(0); // Thoát chương trình
}


#define PORT 8080


int main() {
    // Đăng ký hàm xử lý tín hiệu SIGINT
    signal(SIGINT, handle_sigint);
    Server server(PORT);
    server.start();
    server.close_connection();
    return 0;
}