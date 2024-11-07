#include "../server.h"

void Server::initialize_user_session(const int &sd, const std::string& username, const std::string& password) {
    for (int j = 0; j < MAX_USERS; ++j) {
        if (users[j].get_socket() == -1) {
            users[j].set_socket(sd);

            // Tìm tài khoản và kiểm tra nếu có tồn tại
            auto account_opt = account_list.find_acc(username, password);
            if (account_opt.has_value()) {
                users[j].set_account(account_opt.value());  // Truyền vào tham chiếu tới Account
                account_opt.value().displayInfo(); // Hiển thị thông tin tài khoản
            } else {
                // Xử lý trường hợp không tìm thấy tài khoản
                std::cerr << "Tài khoản không tồn tại hoặc thông tin không hợp lệ.\n";
            }
            break;
        }
    }
}
