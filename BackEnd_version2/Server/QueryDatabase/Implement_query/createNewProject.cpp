#include "../QueryDatabase.h"

string QueryDatabase::createNewProject(const int &client_socket,
                                       const string &name_project,
                                       const string &description) {
  string result;
  int user_id = -1;
  int project_id = -1; // Khai báo project_id ở đầu để có thể sử dụng sau

  try {
    // Truy vấn để lấy user_id từ client_socket
    std::unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement(
        "SELECT user_id FROM users WHERE client_socket = ?"));
    pstmt1->setInt(1, client_socket);
    std::unique_ptr<sql::ResultSet> res1(pstmt1->executeQuery());

    if (res1->next()) {
      user_id = res1->getInt("user_id");
    } else {
      return "Không tìm thấy user với client_socket đã cho!";
    }

    // Truy vấn để chèn dự án mới vào bảng projects
    std::unique_ptr<sql::PreparedStatement> pstmt2(con->prepareStatement(
        "INSERT INTO projects (project_name, description, created_by) "
        "VALUES(?, ?, ?)"));
    pstmt2->setString(1, name_project);
    pstmt2->setString(2, description);
    pstmt2->setInt(3, user_id);
    pstmt2->executeUpdate();

    // Lấy project_id của dự án mới
    std::unique_ptr<sql::Statement> stmt(con->createStatement());
    std::unique_ptr<sql::ResultSet> res2(stmt->executeQuery("SELECT LAST_INSERT_ID() AS project_id"));

    if (res2->next()) {
      project_id = res2->getInt("project_id");
    } else {
      return "Lỗi: Không thể lấy project_id của dự án mới!";
    }

    // Thêm người tạo vào bảng project_members với vai trò mặc định
    std::unique_ptr<sql::PreparedStatement> pstmt3(con->prepareStatement(
        "INSERT INTO project_members (project_id, user_id, role) VALUES (?, ?, ?)"));
    pstmt3->setInt(1, project_id);
    pstmt3->setInt(2, user_id);
    pstmt3->setString(3, "creator"); // Vai trò mặc định là "creator"
    pstmt3->executeUpdate();

    // Gán project_id vào kết quả trả về
    result = "Dự án mới đã được tạo thành công! Project ID: " + std::to_string(project_id);

  } catch (sql::SQLException &e) {
    result = "ERROR: Lỗi MySQL: " + std::string(e.what());
  }

  return result;
}
