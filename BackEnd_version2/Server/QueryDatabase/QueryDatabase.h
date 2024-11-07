#ifndef QUERYDATABASE_H
#define QUERYDATABASE_H

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> // Thêm dòng này
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <memory> // thêm thư viện để sử dụng unique_ptr
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <string>

using namespace std;

class QueryDatabase {
private:
  string username;
  string password;
  string database;
  unique_ptr<sql::Connection> con; // sử dụng unique_ptr

  unique_ptr<sql::Connection> connectDatabase(const string &username,
                                              const string &password,
                                              const string &database);

public:
  QueryDatabase(const string &username, const string &password,
                const string &database);

  ~QueryDatabase();

  void executeUpdate(const string &query);
  void executeQuery(const string &query,
                    void (*processResult)(sql::ResultSet *));

  // Search user_id dua tren username, password
  string searchUserId(const string &username, const string &password);

  // Kiem tra xem tai khoan co ton tai hay ko
  string checkUserCredentials(const string &username, const string &password);

  // Chuyển trạng thái người dùng bằng cách thay đổi client_socket
  void setStateUser(int client_socket, int user_id);

  // Thêm người dùng mới
  string add_new_user(const string &username, const string &password,
                      const string &name, const int &age, const string &email);

  // Show danh sách project
  string showListProject(const int &client_sock);

  string checkLogin(const int &client_sock);

  // Tạo project mới
  string createNewProject(const int &client_socket, const string &username,
                          const string &password);

  string addMemberToProject(const int &project_id, const int &user_id,
                            const string &role);

 string createTask(const int &project_id, const int &user_id,
                    const string &task_name, const string &description);

  string showListStudentProject(const int &project_id);

  string showListTasks(const int &client_socket);
  string updateStatus(const int &client_socket, const int &task_id, const string& state);
  // Truyy vấn database
  void queryDatabase(const string &request);

  void queryDatabase(const string &request, const int &client_socket);

  string queryDatabase(const string &request, const int &param1,
                       const int &param2, const string &params3);

  string queryDatabase2(const string &request, const int &client_socket);

  void queryDatabase(const string &request, int client_socket, int user_id);

  string queryDatabase(const string &request, const string &username,
                       const string &password);

  string queryDatabase(const string &request, const int &client_socket,
                       const string &username, const string &password);

  string queryDatabase(const string &request, const string &username,
                       const string &password, const string &name,
                       const int &age, const string &email);

  string queryDatabase(const string &request, const int &params1,
                       const int &params2, const string &params3,
                       const string &params4);
  void closeStateAllUsers();
  void closeStateUser(const int &client_socket);
};

#endif // QUERYDATABASE_H