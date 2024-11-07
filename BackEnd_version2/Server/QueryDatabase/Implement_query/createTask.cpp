#include "../QueryDatabase.h"

// Hàm thêm task mới
std::string QueryDatabase::createTask(const int &project_id, const int &user_id,
                                       const std::string &task_name,
                                       const std::string &description) {
    std::string result;

    try {
        // Câu truy vấn để thêm task mới
        std::string query = R"(INSERT INTO tasks (project_id, task_name, assigned_to, description)  
                               VALUES (?, ?, ?, ?))";

        // Chuẩn bị câu lệnh
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));

        // Gán giá trị cho các tham số
        pstmt->setInt(1, project_id);              // Gắn giá trị project_id
        pstmt->setString(2, task_name);            // Gắn giá trị task_name
        pstmt->setInt(3, user_id);                 // Gắn giá trị assigned_to (user_id)
        pstmt->setString(4, description);          // Gắn giá trị description

        // Thực thi câu lệnh
        pstmt->executeUpdate();

        result = "Task đã được thêm thành công!";
    } catch (sql::SQLException &e) {
        result = "ERROR: Lỗi MySQL: " + std::string(e.what());
    }

    return result;
}
