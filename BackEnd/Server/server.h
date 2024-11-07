#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include "../Account/account.h"
#include "../Account/AccountList.h"
#include "User/User.h"
#include <sstream> // Để sử dụng std::istringstream
#include <unordered_map>

#define BUFFER_SIZE 1024
#define MAX_USERS 100     // Số lượng client kết nối tới 1 server là 100
#define MAX_SOCKET 100
// Client sẽ kết nối thông qua cổng port và từng client sẽ trao đổi thông qua client_socket của chính mình 
class Server {
private:
    int port;
    int server_sock;
    int sockets[MAX_SOCKET];    // Socket nó sẽ được chuyển thành 1 nếu như socket được kết nối 
    User users[MAX_USERS];  // Users chỉ được gán socket khi mà đã login thành công 
    AccountList account_list;

public:
    Server(int port); // Constructor
    ~Server();

    void start();    // Hàm để tạo user mới khi có 1 kết nối tới server
    void accept_new_client();
    void process_client_request(int sd, int index);
    void reset_socket(int sd, int index);
    void close_connection(); 

    void handle_request(const int& socket, const std::string& request); // Lấy request từ client để thực hiện yêu cầu tương ứng, truyền đi socket người gửi 
    
    bool check_client_login(const int& sd);
    std::string process_signup(std::istringstream &iss);
    std::string process_login(const int &sd, std::istringstream &iss);
     // Khởi tạo phiên làm việc của user, khi có user đăng nhập thành công sẽ gắn socket để giao tiếp và gán account để có được thông tin tài khoản vừa đăng nhập
    void initialize_user_session(const int &sd, const std::string& username, const std::string& password);
    std::string create_project(const int& sd, std::istringstream &iss);
    std::string show_list_project(const int& sd);
};

#endif // SERVER_H
