#include "Client/Client.h"
// #include "crow_all.h"
#include "Command_Type/Command_Type.h"
#include <cstdio>
#include <iomanip> // Để căn chỉnh cột
#include <iostream>
#include <sstream>
#include <string>
// #include "Router/Router.h"
#include <algorithm>
#include <limits>

#define POST 8080
#define localhost "127.0.0.1"
#define MAX_ThanhVien 100


void login(const Client &client) {
  string username;
  string password;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;
  string resquest_send = "LOGIN " + username + " " + password;
  cout << "Response from server: " << client.send_request(resquest_send)
       << endl;
}

void signup(const Client &client) {
  // Giai doan 1: Gui username, password cho server de server kiem tra
  string username, password;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;

  string resquest_send =
      "SIGNUP CHECK_USER_CREDENTIALS " + username + " " + password;
  string response = client.send_request(resquest_send);
  if (response == "ERROR: Username hoặc password không đúng!") {
    // Giai doan 2: Neu server tra loi username, password chua ton tai thi gui
    // tiep thong tin con lai cho server luu tru vao database
    string name, email;
    int age;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Email: ";
    cin >> email;
    string resquest_send = "SIGNUP ADD_NEW_USER " + username + " " + password +
                           " " + name + " " + to_string(age) + " " + email;
    cout << client.send_request(resquest_send) << endl;
  } else {
    cerr << "Error: Account da ton tai" << endl;
  }
}

void showListProject(const Client &client) {
  std::string data = client.send_request("SHOW_LIST_PROJECT");
  std::cout << string(45, '-') << "LIST PROJECT" << string(45, '-') << endl;
  // Tạo tiêu đề cho bảng
  std::cout << std::string(100, '_') << std::endl;
  std::cout << std::left << std::setw(12) << "Project ID" << " | "
            << std::setw(30) << "Project Name" << " | " << std::setw(40)
            << "Description" << " | " << "Created At" << std::endl;
  std::cout << std::string(100, '-') << std::endl;

  // Tách dữ liệu thành các dòng
  std::istringstream iss(data);
  std::string line;

  while (std::getline(iss, line)) {
    if (line.find("Project ID:") != std::string::npos) {
      int project_id;
      std::string project_name, description, created_at;

      // Lấy từng giá trị từ chuỗi
      std::istringstream lineStream(line);
      lineStream.ignore(11); // Bỏ qua "Project ID: "
      lineStream >> project_id;

      std::getline(iss, line);
      project_name = line.substr(13); // Bỏ qua "Project Name: "

      std::getline(iss, line);
      description = line.substr(13); // Bỏ qua "Description: "

      std::getline(iss, line);
      created_at = line.substr(11); // Bỏ qua "Created At: "

      // In ra từng dòng của bảng với ký tự phân cách "|"
      std::cout << std::left << std::setw(12) << project_id << " | "
                << std::setw(30) << project_name << " | " << std::setw(40)
                << description << " | " << created_at << std::endl;
    }
  }
  std::cout << std::string(100, '_') << std::endl;
  std::cout << string(45, '-') << "LIST PROJECT" << string(45, '-') << endl;
}

void create_project(const Client &client) {
  // Bước 1: Tạo project mới
  std::string name_project, description;
  std::cout << "Name project: ";
  std::cin >> name_project;
  std::cout << "Description: ";
  std::cin >> description;
  std::string request_mes =
      "CREATE_PROJECT CREATE_NEW_PROJECT " + name_project + " " + description;
  std::string response = client.send_request(request_mes);

  // Kiểm tra phản hồi và tách Project ID
  if (response.find("Dự án mới đã được tạo thành công!") != std::string::npos) {
    size_t pos = response.find("Project ID: ");
    int project_id = -1;
    if (pos != std::string::npos) {
      project_id =
          std::stoi(response.substr(pos + 12)); // Tách Project ID từ phản hồi
    }

    if (project_id != -1) {
      // Bước 2: Thêm thành viên
      request_mes =
          "CREATE_PROJECT ADD_MEMBERS " + std::to_string(project_id) + " ";
      int count_members;

      // Nhập số lượng thành viên và kiểm tra kiểu dữ liệu
      std::cout << "Count members: ";
      while (!(std::cin >> count_members) || count_members <= 0) {
        std::cout
            << "Số lượng thành viên phải là một số nguyên dương. Nhập lại: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      int member_id;
      std::string role;
      for (int i = 0; i < count_members; i++) {
        // Nhập ID thành viên và kiểm tra kiểu dữ liệu
        std::cout << "ID Members: ";
        while (!(std::cin >> member_id) || member_id <= 0) {
          std::cout << "ID thành viên phải là một số nguyên dương. Nhập lại: ";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Nhập vai trò và kiểm tra kiểu dữ liệu
        std::cout << "Role: ";
        std::cin >> role;
        while (std::any_of(role.begin(), role.end(), ::isdigit)) {
          std::cout << "Vai trò không được chứa số. Nhập lại: ";
          std::cin >> role;
        }

        // Thêm thông tin vào request_mes
        request_mes += std::to_string(member_id) + " " + role + " ";
      }

      std::cout << request_mes << std::endl;
      response = client.send_request(request_mes);
      std::cout << response << std::endl;
    }
  } else {
    std::cout << response << std::endl;
  }
}

void showListStudentOfProject(const Client &client, const int &project_id) {
  // Tạo chuỗi yêu cầu
  std::string request_msg =
      "SHOW_LIST_STUDENT PROJECT " + std::to_string(project_id);
  std::string data = client.send_request(request_msg);
  std::cout << string(45, '-') << "LIST STUDENT" << string(45, '-') << endl;

  // Tạo tiêu đề cho bảng
  std::cout << std::string(80, '_') << std::endl;
  std::cout << std::left << std::setw(12) << "Project ID" << " | "
            << std::setw(12) << "User ID" << " | " << std::setw(20)
            << "Username" << " | " << "Role" << std::endl;
  std::cout << std::string(80, '-') << std::endl;

  // Tách dữ liệu thành các dòng
  std::istringstream iss(data);
  std::string line;

  while (std::getline(iss, line)) {
    if (line.find("User ID:") != std::string::npos) {
      int user_id;
      std::string username, role;

      // Lấy từng giá trị từ chuỗi
      std::istringstream lineStream(line);
      lineStream.ignore(8); // Bỏ qua "User ID: "
      lineStream >> user_id;

      std::getline(iss, line);
      username = line.substr(10); // Bỏ qua "Username: "

      std::getline(iss, line);
      role = line.substr(6); // Bỏ qua "Role: "

      // In ra từng dòng của bảng với ký tự phân cách "|"
      std::cout << std::left << std::setw(12) << project_id << " | "
                << std::setw(12) << user_id << " | " << std::setw(20)
                << username << " | " << role << std::endl;
    }
  }
  std::cout << std::string(80, '_') << std::endl;
  std::cout << string(45, '-') << "LIST STUDENT" << string(45, '-') << endl;
}

void showListTasks(const Client &client) {
  std::string data = client.send_request("SHOW_LIST_TASKS");
  std::cout << std::string(45, '-') << "LIST TASKS" << std::string(45, '-') << std::endl;

  std::cout << std::string(100, '_') << std::endl;
  std::cout << std::left << std::setw(12) << "Task ID" << " | "
            << std::setw(12) << "Project ID" << " | "
            << std::setw(30) << "Task Name" << " | "
            << std::setw(20) << "Status" << " | "
            << std::setw(40) << "Description" << std::endl;
  std::cout << std::string(100, '-') << std::endl;

  std::istringstream iss(data);
  std::string line;

  while (std::getline(iss, line)) {
    if (line.find("Task ID:") != std::string::npos) {
      int task_id, project_id;
      std::string task_name, status, description;

      std::istringstream lineStream(line);
      lineStream.ignore(9);
      lineStream >> task_id;

      std::getline(iss, line);
      project_id = std::stoi(line.substr(12));

      std::getline(iss, line);
      task_name = line.substr(11);

      std::getline(iss, line);
      status = line.substr(8);

      std::getline(iss, line);
      description = line.substr(13);

      std::cout << std::left << std::setw(12) << task_id << " | "
                << std::setw(12) << project_id << " | "
                << std::setw(30) << task_name << " | "
                << std::setw(20) << status << " | "
                << description << std::endl;
    }
  }
  std::cout << std::string(100, '_') << std::endl;
  std::cout << std::string(45, '-') << "LIST TASKS" << std::string(45, '-') << std::endl;
}

void update_state_task(const Client &client) {
  showListTasks(client);
  int task_id;
  std::cout << "Input task id to update state task: ";
  std::cin >> task_id;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string state;
  std::cout << "Input state task ('chua_bat_dau', 'dang_lam', 'hoan_thanh'): ";
  std::getline(std::cin, state);

  std::string request_mes = "UPDATE_STATE\n" + std::to_string(task_id) + "\n" + state;
  std::cout << "Sending request to server: " << request_mes << std::endl;
  std::cout << client.send_request(request_mes) << std::endl;

  showListTasks(client);
}

void create_task(const Client &client) {
  showListProject(client);
  cout << "Enter the project ID to create a task:  ";
  int project_id, count_task;
  cin >> project_id;

  // Hiển thị danh sách sinh viên nhóm vừa chọn
  showListStudentOfProject(client, project_id);
  cout << "Enter count task: ";
  cin >> count_task;
  string task_name, description;
  int user_id;
  string resquest_mes = "CREATE_TASK\n" + to_string(project_id) + "\n";

  for (int i = 1; i <= count_task; i++) {
    cout << string(10, '_') << "Task " << i << string(10, '_') << endl;
    cout << "Enter task name: ";
    cin >> task_name;

    cout << "User id: ";
    cin >> user_id;

    // Bỏ qua ký tự newline còn lại trong bộ đệm
    cin.ignore();

    cout << "Description: ";
    getline(cin, description);

    resquest_mes += task_name + "\n" + to_string(user_id) + "\n" + description +
                    "\n"; // Thêm description vào request
  }

  cout << resquest_mes << endl;
  cout << client.send_request(resquest_mes) << endl;
}



int main() {
  Client client(localhost, POST);

  int choice;
  while (true) {
    std::cout << "\nMenu:\n";
    std::cout << "1. Login\n";
    std::cout << "2. Sign Up\n";
    std::cout << "3. Create Project\n";
    std::cout << "4. Create New Tasks\n";
    std::cout << "5. Show List Projects\n";
    std::cout << "6. Show List Students Of Project\n";
    std::cout << "7. Show List Tasks\n";
    std::cout << "8. Update Task State\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      login(client);
      break;
    case 2:
      signup(client);
      break;
    case 3:
      create_project(client);
      break;

    case 4:
      create_task(client);
      break;

    case 5:
      showListProject(client);
      break;

    case 6:
      {
        int project_id;
        std::cout << "Enter project id: ";
        std::cin >> project_id;
        showListStudentOfProject(client, project_id);
      }
      break;
    case 7:
      showListTasks(client);
      break;

    case 8:
      update_state_task(client);
      break;
      
    case 0:
      return 0;
    default:
      std::cout << "Invalid choice. Try again." << std::endl;
    }
  }

  return 0;
}
