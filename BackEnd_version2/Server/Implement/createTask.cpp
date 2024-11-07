#include "../Server.h"
#include <string>

string Server::createTask(const int &client_socket,
                           std::istringstream &iss) {
    string check = checkLogin(client_socket);
    if (check == "User đã thực hiện login") {
        string project_id;
        iss >> project_id; // Đọc project_id

        string taskName, user_id, description;
        
        // Lặp qua các task
        while (iss >> taskName) {
            iss >> user_id; // Đọc user_id

            // Bỏ qua ký tự newline nếu có trước khi đọc mô tả
            iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Đọc mô tả
            getline(iss, description);

            // In ra mô tả (để kiểm tra)
            cout << "Description: " << description << endl;

            // Gọi hàm query để thêm task vào database
            query.queryDatabase("CREATE_TASK", stoi(project_id), stoi(user_id), taskName, description);
        }
    }
    return check;
}
