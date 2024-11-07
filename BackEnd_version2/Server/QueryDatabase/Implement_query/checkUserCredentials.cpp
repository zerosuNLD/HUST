#include "../QueryDatabase.h"

string QueryDatabase::checkUserCredentials(const string &username,
                                         const string &password) {
  string reponse;
  try {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "SELECT * FROM users WHERE username = ? AND password_hash = ?"));
    pstmt->setString(1, username);
    pstmt->setString(2, password);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (res->next()) {
       reponse =  "SUCCESS: Username và password hợp lệ!";
      // Có thể lấy thêm thông tin nếu cần
    } else {
       reponse =  "ERROR: Username hoặc password không đúng!";
    }
  } catch (sql::SQLException &e) {
    reponse = std::string("ERROR: Lỗi MySQL: ") + e.what();
  }
  return reponse;
}