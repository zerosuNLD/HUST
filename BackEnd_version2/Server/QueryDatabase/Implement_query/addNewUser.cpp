#include "../QueryDatabase.h"

// Thêm người dùng mới
string QueryDatabase::add_new_user(const string &username,
                                   const string &password, const string &name,
                                   const int &age, const string &email) {
  string response;
  try {
    // Bước 1: Kiểm tra xem username đã tồn tại hay chưa
    std::unique_ptr<sql::PreparedStatement> pstmt_check(con->prepareStatement(
        "SELECT * FROM users WHERE username = ?"));
    pstmt_check->setString(1, username);

    std::unique_ptr<sql::ResultSet> res(pstmt_check->executeQuery());
    if (res->next()) {
      response = "ERROR: Username đã tồn tại!";
    } else {
      // Bước 2: Thêm người dùng mới vào cơ sở dữ liệu
      std::unique_ptr<sql::PreparedStatement> pstmt_insert(con->prepareStatement(
          "INSERT INTO users (username, password_hash, name, age, email) VALUES (?, ?, ?, ?, ?)"));
      pstmt_insert->setString(1, username);
      pstmt_insert->setString(2, password);  
      pstmt_insert->setString(3, name);
      pstmt_insert->setInt(4, age);
      pstmt_insert->setString(5, email);

      pstmt_insert->executeUpdate();
      response = "SUCCESS: Đăng ký người dùng mới thành công!";
    }
  } catch (sql::SQLException &e) {
    response = std::string("ERROR: Lỗi MySQL: ") + e.what();
  }
  return response;
}