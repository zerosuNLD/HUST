#ifndef SERVER_H
#define SERVER_H

#include "QueryDatabase/QueryDatabase.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <limits>

#define BUFFER_SIZE 1024
#define MAX_SOCKET 100 // Số socket tối đa có thể kết nối cùng lúc

class Server {
private:
  int port;
  int server_sock;
  int sockets[MAX_SOCKET];
  QueryDatabase query;

public:
  Server(const int &port, const string &username, const string &password,
         const string &database); // Constructor
  ~Server();

  void start(); // Hàm để tạo user mới khi có 1 kết nối tới server
  void accept_new_client();
  void process_client_request(int sd, int index);
  void reset_socket(int sd, int index);
  
  void handle_request(const int &socket, const std::string &request);
  string login(const int &socket, std::istringstream &iss);
  string signup(const int &socket, std::istringstream &iss);
  string showListProject(const int &socket, std::istringstream &iss);
  // Kiểm tra xem người dùng đã login chưa bằng cách tìm xem trong list_user có client_socket nào = client_socket vừa gửi yêu cầu hay không
  string checkLogin(const int& socket);
  string createProject(const int& socket, std::istringstream &iss);
  string showListStudent(const int &socket, std::istringstream &iss);
  string createTask(const int& socket, std::istringstream &iss);
  string showListTasks(const int& socket, std::istringstream &iss);
  string updateStatus(const int& socket, std::istringstream &iss);
};

#endif // SERVER_H
