#include "../Server.h"
#include <limits>
#include <string>

string Server::updateStatus(const int &client_socket, std::istringstream &iss) {
  // Kiểm tra trạng thái đăng nhập của người dùng
  string check = checkLogin(client_socket);
  if (check == "User đã thực hiện login") {
    // Đọc task_id từ dòng đầu tiên
    string task_id;
    iss >> task_id;

    // Bỏ qua ký tự xuống dòng sau task_id
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Đọc status từ dòng tiếp theo
    string status;
    getline(iss, status);

    // Kiểm tra task_id và status có hợp lệ không
    if (task_id.empty() || status.empty()) {
      return "ERROR: task_id hoặc trạng thái không hợp lệ.";
    }

    // Gọi hàm queryDatabase để cập nhật trạng thái
    return query.queryDatabase("UPDATE_STATE_TASK", client_socket,
                               stoi(task_id), status);
  }
  return check;
}
