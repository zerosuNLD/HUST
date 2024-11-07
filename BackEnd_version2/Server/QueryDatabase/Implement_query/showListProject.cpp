#include "../QueryDatabase.h"

// Hàm lấy danh sách dự án cho người dùng có client_socket cụ thể
string QueryDatabase::showListProject(const int &client_socket) {
  string result;
  try {
    // Câu truy vấn với tham số
    string query = R"(SELECT * 
                      FROM projects 
                      WHERE project_id IN (
                          SELECT project_id 
                          FROM project_members 
                          WHERE user_id = (
                              SELECT user_id 
                              FROM users 
                              WHERE client_socket = ?
                              LIMIT 1
                          )
                      ))";

    // Chuẩn bị và thực hiện câu truy vấn
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
    pstmt->setInt(1, client_socket); // Gắn giá trị client_socket vào câu truy vấn

    // Thực hiện truy vấn và xử lý kết quả
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    if (!res->next()) {
      return "Không có dự án nào cho client_socket này!";
    }

    do {
      int project_id = res->getInt("project_id");
      string project_name = res->getString("project_name");
      string description = res->getString("description");
      string createdAt = res->getString("created_at");
      
      // Kết hợp thông tin vào kết quả
      result += "Project ID: " + std::to_string(project_id) + 
                "\nProject Name: " + project_name +
                "\nDescription: " + description +
                "\nCreated At: " + createdAt + "\n\n";
    } while (res->next());
  } catch (sql::SQLException &e) {
    result = "ERROR: Lỗi MySQL: " + std::string(e.what());
  }

  return result;
}
