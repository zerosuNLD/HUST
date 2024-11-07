#include "../QueryDatabase.h"
#include <string>

// Thêm người dùng vào project mới
string QueryDatabase::addMemberToProject(const int &project_id, const int &user_id,
                                         const string &role) {
  string response;
  try {
    // Kiểm tra xem user_id có tồn tại trong bảng users hay không
    std::unique_ptr<sql::PreparedStatement> userCheckStmt(con->prepareStatement(
        "SELECT COUNT(*) AS count FROM users WHERE user_id = ?"));
    userCheckStmt->setInt(1, user_id);
    std::unique_ptr<sql::ResultSet> userCheckRes(userCheckStmt->executeQuery());

    if (userCheckRes->next() && userCheckRes->getInt("count") == 0) {
      return "Lỗi: Không tìm thấy người dùng với user_id = " + to_string(user_id);
    }

    // Kiểm tra xem thành viên đã có trong dự án chưa
    std::unique_ptr<sql::PreparedStatement> checkStmt(con->prepareStatement(
        "SELECT COUNT(*) AS count FROM project_members WHERE project_id = ? AND user_id = ?"));
    checkStmt->setInt(1, project_id);
    checkStmt->setInt(2, user_id);
    std::unique_ptr<sql::ResultSet> res(checkStmt->executeQuery());

    if (res->next() && res->getInt("count") > 0) {
      return "Thành viên " + to_string(user_id) + " đã có trong dự án!";
    }

    // Nếu chưa có, thì thêm thành viên vào project_members
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "INSERT INTO project_members (project_id, user_id, role) VALUES (?, ?, ?)"));
    pstmt->setInt(1, project_id);
    pstmt->setInt(2, user_id);
    pstmt->setString(3, role);
    pstmt->executeUpdate();

    response = "Thành viên " + to_string(user_id) + " đã được thêm vào dự án thành công!";
  } catch (sql::SQLException &e) {
    response = std::string("ERROR: Lỗi MySQL: ") + e.what();
  }
  return response;
}
