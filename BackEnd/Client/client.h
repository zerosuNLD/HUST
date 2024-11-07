#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>  // Để dùng cấu trúc sockaddr_in
#include <unistd.h>     // Để dùng hàm close()

using namespace std;

#define BUFFER_SIZE 1024

class Client {
private:
    string server_ip;
    int server_port;
    int client_socket; // Socket của client

    void report_err(const char* message); // Báo lỗi
    void connect_to_server(); // kết nối tới server

public:
    Client(const string& ip, int port);  // Constructor
    ~Client();
    std::string send_request(const std::string& request) const; // Gửi thông điệp tới cho server
    void close_socket(); // Đóng socket

};

#endif // CLIENT_H
