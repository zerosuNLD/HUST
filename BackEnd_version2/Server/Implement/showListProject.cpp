#include "../Server.h"

string Server::showListProject(const int &client_socket, std::istringstream &iss) {
	string check = checkLogin(client_socket);
	cout << check << endl;
	if(check=="User đã thực hiện login"){
		return query.queryDatabase2("SHOW_LIST_PROJECT", client_socket);
	}else {
		return check;
	}
}