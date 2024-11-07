#include "../QueryDatabase.h"

// Hàm lấy danh sách thành viên cho một dự án cụ thể
std::string QueryDatabase::showListStudentProject(const int &project_id) {
  std::string result;
  try {
    // Câu truy vấn lấy danh sách thành viên cho project_id
    std::string query = R"(SELECT pm.user_id, pm.role, u.username 
                               FROM project_members pm
                               JOIN users u ON pm.user_id = u.user_id
                               WHERE pm.project_id = ?)";

    // Chuẩn bị và thực hiện câu truy vấn
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
    pstmt->setInt(1, project_id); // Gắn giá trị project_id vào câu truy vấn

    // Thực hiện truy vấn và xử lý kết quả
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    if (!res->next()) {
      return "Không có thành viên nào trong dự án này!";
    }

    do {
      int user_id = res->getInt("user_id");
      std::string role = res->getString("role");
      std::string username = res->getString("username");

      // Kết hợp thông tin vào kết quả
      result += "Project ID: " + std::to_string(project_id) +
                "\nUser ID: " + std::to_string(user_id) + "\nUsername: " + username +
                "\nRole: " + role + "\n\n";
    } while (res->next());
  } catch (sql::SQLException &e) {
    result = "ERROR: Lỗi MySQL: " + std::string(e.what());
  }

  return result;
}