#include "../Server.h"

string Server::signup(const int &client_socket, std::istringstream &iss) {
	string res, req;
	iss  >> res;
	if(res == "CHECK_USER_CREDENTIALS"){
		string username, password;
		iss >> username >> password;
		req = query.queryDatabase(res, username, password);
	}else if(res == "ADD_NEW_USER"){
		string username, password, name, age , email;
		iss >> username >> password >> name >> age >> email;
		req = query.queryDatabase(res, username, password, name, stoi(age), email);
	}else {
		req = "ERROR: " + res + " not found!!!";
	}
	return req;
}