#include "../QueryDatabase.h"

// Hàm kiểm tra xem user đã login hay chưa
string QueryDatabase::checkLogin(const int &client_socket) {
  string response;
  try {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "SELECT * FROM users WHERE client_socket=?"));
    pstmt->setInt(1, client_socket);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (res->next()) {
      response = "User đã thực hiện login";
    } else {
      response = "User chưa thực hiện login!";
    }
  } catch (sql::SQLException &e) {
    response = std::string("ERROR: Lỗi MySQL: ") + e.what();
  }
  return response; 
}
