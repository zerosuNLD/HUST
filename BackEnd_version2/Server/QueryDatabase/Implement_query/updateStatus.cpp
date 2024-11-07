#include "../QueryDatabase.h"

// Hàm cập nhật trạng thái của task
string QueryDatabase::updateStatus(const int &client_socket, const int &task_id, const string &state) {
  string result;
  try {
    // Câu truy vấn cập nhật trạng thái của task
    string query = R"(
      UPDATE tasks
      SET status = ?
      WHERE task_id = ?
        AND assigned_to = (SELECT user_id FROM users WHERE client_socket = ?)
    )";

    // Chuẩn bị và thực hiện câu truy vấn
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
    pstmt->setString(1, state);          // Gắn trạng thái mới
    pstmt->setInt(2, task_id);           // Gắn task_id cần cập nhật
    pstmt->setInt(3, client_socket);     // Gắn client_socket của người dùng

    // Thực hiện câu lệnh cập nhật và kiểm tra số hàng bị ảnh hưởng
    int rows_affected = pstmt->executeUpdate();
    if (rows_affected > 0) {
      result = "Task đã được cập nhật trạng thái thành công!";
    } else {
      result = "Không tìm thấy task nào với task_id và client_socket này!";
    }
  } catch (sql::SQLException &e) {
    result = "ERROR: Lỗi MySQL: " + std::string(e.what());
  }

  return result;
}