#include "../QueryDatabase.h"

// Hàm lấy danh sách task mà người dùng được giao
string QueryDatabase::showListTasks(const int &client_socket) {
  string result;
  try {
    // Câu truy vấn với tham số
    string query = R"(SELECT task_id, project_id, task_name, status, description
                      FROM tasks
                      WHERE assigned_to = (
                          SELECT user_id 
                          FROM users 
                          WHERE client_socket = ?
                      ))";

    // Chuẩn bị và thực hiện câu truy vấn
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
    pstmt->setInt(1, client_socket); // Gắn giá trị client_socket vào câu truy vấn

    // Thực hiện truy vấn và xử lý kết quả
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    if (!res->next()) {
      return "Không có task nào cho client_socket này!";
    }

    do {
      int task_id = res->getInt("task_id");
      int project_id = res->getInt("project_id");
      string task_name = res->getString("task_name");
      string status = res->getString("status");
      string description = res->getString("description");

      // Kết hợp thông tin vào kết quả
      result += "Task ID: " + std::to_string(task_id) + 
                "\nProject ID: " + std::to_string(project_id) +
                "\nTask Name: " + task_name +
                "\nStatus: " + status +
                "\nDescription: " + description + "\n\n";
    } while (res->next());
  } catch (sql::SQLException &e) {
    result = "ERROR: Lỗi MySQL: " + std::string(e.what());
  }

  return result;
}
