#include "../server.h"
#include <string>

// Các hàm xử lý cụ thể cho từng loại lệnh
std::string Server::process_signup(std::istringstream &iss) {
  std::string username, password, name, age, email;
  iss >> username >> password >> name >> age >> email;

  Account new_account = Account(username, password, name, stoi(age), email);
  if(account_list.addAccount(new_account)){
    account_list.displayAllAccounts();
    return "Account added successfully.";
  }

  return "The account already exists.";
}