#include "QueryDatabase/QueryDatabase.h"
#include "Server.h"

Server::Server(const int &port, const string &username, const string &password,
               const string &database)
    : port(port), query(username, password, database) {

  query.closeStateAllUsers();

  // Phần khởi tạo các socket như bạn đã có
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    std::cerr << "Error: Không thể tạo socket\n";
    exit(1);
  }

  // Thiết lập địa chỉ server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) <
      0) {
    std::cerr << "Error: Không thể gán địa chỉ cho socket\n";
    close(server_sock);
    exit(1);
  }

  if (listen(server_sock, MAX_SOCKET) < 0) {
    std::cerr << "Error: Không thể bắt đầu lắng nghe\n";
    close(server_sock);
    exit(1);
  }

  std::cout << "Server đang lắng nghe trên cổng " << port << "...\n";

  for (int i = 0; i < MAX_SOCKET; ++i) {
    sockets[i] = -1;
  }
}

Server::~Server() {
  // Đóng socket server khi destructor được gọi
  query.closeStateAllUsers();
  close(server_sock);
}