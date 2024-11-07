#include "../QueryDatabase.h"

// Hàm tổng quát hóa cho `setStateUser`
void QueryDatabase::setStateUser(int client_socket, int user_id) {
  std::string query =
      "UPDATE users SET client_socket = " + std::to_string(client_socket) +
      " WHERE user_id = " + std::to_string(user_id);
  executeUpdate(query);
}
