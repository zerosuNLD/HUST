#include <string>
#include <optional>
#include "../../Account/Project/Project.h"
#include "../server.h"

std::string Server::create_project(const int& sd, std::istringstream& iss) {
    std::string response;

    // Kiểm tra xem client đã login hay chưa
    if (!check_client_login(sd)) {
        return "ERROR: Bạn cần login trước!!!";
    }

    std::string name_project, Mo_ta;
    iss >> name_project >> Mo_ta;
    Project project(name_project, Mo_ta);

    for (auto& user : users) {
        if (user.get_socket() == sd) {
            if (auto account_opt = user.get_account()) {
                Account& account = account_opt.value().get();
                account.addProject(project);
                project.addMenber(account);
                response += "Thêm thành viên: " + account.getName() + " thành công\n";
            }
        }
    }

    std::string id_thanhvien;
    while (iss >> id_thanhvien) {
        auto account_opt = account_list.find_acc(std::stoi(id_thanhvien));
        if (account_opt.has_value()) {
            Account& acc = account_opt.value().get();
            if (project.addMenber(acc)) {
                if (acc.addProject(project)) {
                    response += "Thêm thành công người dùng: " + acc.getName() + "\n";
                }
            } else {
                response += "Id: " + id_thanhvien + " đã tồn tại";
            }
        } else {
            response += "Id: " + id_thanhvien + " không tồn tại\n";
        }
    }

    for (const auto& user : users) {
        if (user.get_socket() != -1) {
            if (auto account_opt = user.get_account()) {
                account_opt.value().get().displayListProject();
            }
        }
    }

    return response;
}
