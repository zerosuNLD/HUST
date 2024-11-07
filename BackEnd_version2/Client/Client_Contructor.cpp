#include "Client.h"
#include <cstring> // Để dùng cho strerror

Client::Client(const std::string& ip, int port) : server_ip(ip), server_port(port), client_socket(-1) {
    // Khi khởi tạo Client thì sẽ thực hiện connect tới server luôn
    connect_to_server();
}

Client::~Client() {
    close_socket(); // Đảm bảo đóng socket khi hủy đối tượng
}

void Client::connect_to_server() {
    struct sockaddr_in server_addr;

    // Tạo socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        std::cerr << "Error: Không thể tạo socket. " << strerror(errno) << "\n";
        return;
    }

    // Thiết lập địa chỉ server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str());

    // Kết nối tới server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error: Không thể kết nối tới server. " << strerror(errno) << "\n";
        close(client_socket);
        client_socket = -1; // Đặt lại client_socket về -1 để biểu thị kết nối không thành công
        return;
    }
        
    std::cout << "Đã kết nối tới server " << server_ip << " qua cổng " << server_port << "\n";
}

void Client::close_socket() {
    if (client_socket >= 0) {
        close(client_socket);
        client_socket = -1;
        std::cout << "Đã đóng kết nối socket\n";
    }
}
