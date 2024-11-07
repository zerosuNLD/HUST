#include "../server.h"

std::string Server::process_login(const int &sd, std::istringstream &iss) {
  std::string username, password;
  iss >> username >> password;
  bool login_success = account_list.accountExists(username, password);
  if (login_success) {
    initialize_user_session(sd, username, password);
    return "Login success";
  }
  return "Login failed";
}
