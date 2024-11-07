#include "server.h"

Server::Server(int port) : port(port) {
    // Fix cứng database 
    Account admin = Account("admin", "admin", "admin", 100, "admin@gmail.com");
    Account lduy = Account("duy.nl204960", "038202016369", "Nguyen Luong Duy", 22, "duycoiomn123@gmail.com");
    account_list.addAccount(admin);
    account_list.addAccount(lduy);

    // Tạo socket cho server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        std::cerr << "Error: Không thể tạo socket\n";
        exit(1);
    }

    // Thiết lập địa chỉ server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // Xóa bộ nhớ
    server_addr.sin_family = AF_INET; // Sử dụng IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Lắng nghe trên mọi địa chỉ IP
    server_addr.sin_port = htons(port); // Cổng server

    // Gán địa chỉ cho socket
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error: Không thể gán địa chỉ cho socket\n";
        close(server_sock);
        exit(1);
    }

    // Bắt đầu lắng nghe kết nối
    if (listen(server_sock, MAX_USERS) < 0) {
        std::cerr << "Error: Không thể bắt đầu lắng nghe\n";
        close(server_sock);
        exit(1);
    }

    std::cout << "Server đang lắng nghe trên cổng " << port << "...\n";

    // Khởi tạo tất cả socket chưa có client nào kết nối đến 
    for (int i = 0; i < MAX_SOCKET; ++i) {
        sockets[i] = -1;
    }
}

Server::~Server() {
    // Đóng socket server khi destructor được gọi
    close(server_sock);
}