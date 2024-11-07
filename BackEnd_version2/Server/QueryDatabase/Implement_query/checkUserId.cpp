#include "../QueryDatabase.h"

// Search user_id dựa trên username và password
string QueryDatabase::searchUserId(const string &username,
                                   const string &password) {
  string response;
  try {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "SELECT user_id FROM users WHERE username = ? AND password_hash = ?"));
    pstmt->setString(1, username);
    pstmt->setString(2, password);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (res->next()) {
      // Lấy user_id từ kết quả truy vấn
      int user_id = res->getInt("user_id"); // Lấy giá trị user_id
      response = std::to_string(user_id); // Chuyển đổi thành chuỗi
    } else {
      response = "ERROR: User_id không tồn tại!";
    }
  } catch (sql::SQLException &e) {
    response = std::string("ERROR: Lỗi MySQL: ") + e.what();
  }
  return response; // Trả về user_id hoặc thông báo lỗi
}
