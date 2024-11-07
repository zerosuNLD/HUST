#include "../QueryDatabase.h"

// Hàm tổng quát hóa cho `setStateUser`
void QueryDatabase::closeStateUser(const int& client_socket) {
    std::string query = "UPDATE users SET client_socket = -1 WHERE client_socket = ?";
    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setInt(1, client_socket); // Đặt giá trị client_socket
        pstmt->executeUpdate(); // Thực thi truy vấn cập nhật
    } catch (sql::SQLException &e) {
        std::cerr << "ERROR: SQL Exception in closeStateUser - " << e.what() << std::endl;
    }
}