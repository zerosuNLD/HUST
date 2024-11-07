#include "../QueryDatabase.h"

// Hàm tổng quát hóa cho `setStateUser`
void QueryDatabase::closeStateAllUsers() {
    std::string query = "UPDATE users SET client_socket = -1 WHERE client_socket != -1";
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->executeUpdate();  // Thực thi truy vấn cập nhật
    } catch (sql::SQLException &e) {
        std::cerr << "ERROR: SQL Exception in closeStateAllUsers - " << e.what() << std::endl;
    }
}