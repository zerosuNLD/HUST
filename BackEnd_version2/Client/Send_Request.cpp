#include "Client.h"
#include <cstring> // Để dùng cho memset



std::string Client::send_request(const std::string& request) const {
    // Gửi chuỗi request tới server
    ssize_t bytes_sent = send(client_socket, request.c_str(), request.size(), 0);
    if (bytes_sent < 0) {
        std::cerr << "Error: Không thể gửi yêu cầu tới server\n";
        return "ERROR";
    }

    // Nhận phản hồi từ server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        std::cerr << "Error: Không thể nhận phản hồi từ server\n";
        return "ERROR";
    }

    buffer[bytes_received] = '\0';  // Đảm bảo buffer là chuỗi hợp lệ
    std::string response(buffer);

    return response;  // Trả về phản hồi từ server để client tự xử lý
}


