#include "../Server.h"
#include <string>

string Server::createProject(const int &client_socket,
                             std::istringstream &iss) {
  string check = checkLogin(client_socket);
  if (check == "User đã thực hiện login") {
    string res;
    iss >> res;
    if (res == "CREATE_NEW_PROJECT") {
      string name_project, description;
      iss >> name_project >> description;
      return query.queryDatabase("CREATE_NEW_PROJECT", client_socket,
                                 name_project, description);
    } else if (res == "ADD_MEMBERS") {
      string members_id, project_id;
      string reponse;
	  string role;
      iss >> project_id;

      while (iss >> members_id) {
		iss >> role;
        reponse += query.queryDatabase("ADD_MEMBER_TO_PROJECT", stoi(project_id),
                            stoi(members_id), role) + "\n";
      }
	  return  reponse;
    } else {
      return "Error: Resquest: " + res + " not fonud!!";
    }
  }
  return check;
}