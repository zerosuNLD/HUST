#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <optional>
#include <functional> // Để sử dụng std::reference_wrapper
#include "../../Account/account.h"

#define BUFFER_SIZE 1024

class User {
private:
    int client_socket; // client_socket được gán khi client kết nối với server
    std::optional<std::reference_wrapper<Account>> account; // Optional reference to Account
    
public:
    explicit User() : client_socket(-1) {} // Khởi tạo với giá trị không hợp lệ

    ~User() { disconnect(); }

    void set_socket(int socket) { client_socket = socket; }
    int get_socket() const { return client_socket; }

    // Cập nhật để thiết lập tham chiếu tới Account
    void set_account(Account& acc) { 
        account = acc; 
    }

    // Trả về optional reference wrapper tới Account
    std::optional<std::reference_wrapper<Account>> get_account() const { 
        return account; 
    }
    
    void display_user() const {
        if (account.has_value()) {
            account.value().get().displayInfo();
        }
        std::cout << "Client socket: " << client_socket << std::endl;
    }
    
    void disconnect() { 
        if (client_socket != -1) {
            close(client_socket);
            client_socket = -1; // Đánh dấu socket là không hợp lệ
        }
    }
};

#endif // USER_H
