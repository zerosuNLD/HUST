#include "QueryDatabase.h"
#include <string>

void QueryDatabase::executeUpdate(const string &query) {
  try {
    std::unique_ptr<sql::Statement> stmt(this->con->createStatement());
    int rows_affected = stmt->executeUpdate(query);
    std::cout << "Số hàng đã cập nhật: " << rows_affected << std::endl;
  } catch (sql::SQLException &e) {
    std::cerr << "Lỗi MySQL: " << e.what() << std::endl;
  }
}

void QueryDatabase::queryDatabase(const string &request) {
  if (request == "CHECK_USERNAME_PASSWORD") {

  } else if (request == "GETNAME") {

  } else if (request == "CLOSE_ALL_USERS") {
    closeStateAllUsers();
  } else {
    std::cout << "Yêu cầu không hợp lệ: " << request << std::endl;
  }
}

void QueryDatabase::queryDatabase(const string &request,
                                  const int &client_socket) {
  if (request == "CLOSE_STATE") {
    closeStateUser(client_socket);
  } else {
    std::cout << "Yêu cầu không hợp lệ: " << request << std::endl;
  }
}

string QueryDatabase::queryDatabase2(const string &request,
                                     const int &params1) {
  if (request == "SHOW_LIST_PROJECT") {
    return showListProject(params1);
  } else if (request == "CHECK_LOGIN") {
    return checkLogin(params1);
  } else if (request == "SHOW_LIST_STUDENT_PROJECT") {
    return showListStudentProject(params1);
  } else if (request == "SHOW_LIST_TASKS") {
    return showListTasks(params1);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}

void QueryDatabase::queryDatabase(const string &request, int params1,
                                  int params2) {
  if (request == "UPDATE_STATE") {
    setStateUser(params1, params2);
  }
}

string QueryDatabase::queryDatabase(const string &request, const int &params1,
                                    const int &params2, const string &params3) {
  if (request == "ADD_MEMBER_TO_PROJECT") {
    return addMemberToProject(params1, params2, params3);
  } else if (request == "UPDATE_STATE_TASK") {
    return updateStatus(params1, params2, params3);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}

string QueryDatabase::queryDatabase(const string &request,
                                    const string &username,
                                    const string &password) {
  if (request == "CHECK_USER_CREDENTIALS") {
    return checkUserCredentials(username, password);
  } else if (request == "SEARCH_USER_ID") {
    return searchUserId(username, password);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}

string QueryDatabase::queryDatabase(const string &request,
                                    const int &client_socket,
                                    const string &username,
                                    const string &password) {
  if (request == "CREATE_NEW_PROJECT") {
    return createNewProject(client_socket, username, password);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}

string QueryDatabase::queryDatabase(const string &request,
                                    const string &username,
                                    const string &password, const string &name,
                                    const int &age, const string &email) {
  if (request == "ADD_NEW_USER") {
    return add_new_user(username, password, name, age, email);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}

string QueryDatabase::queryDatabase(const string &request, const int &params1,
                                    const int &params2, const string &params3,
                                    const string &params4) {
  if (request == "CREATE_TASK") {
    return createTask(params1, params2, params3, params4);
  }
  return "ERROR: Request database: " + request + " không hợp lệ!!";
}