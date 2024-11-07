#include "../Server.h"

string Server::login(const int &client_socket, std::istringstream &iss) {
	// Cần thêm cái chỉ có thể login 1 lần, để login 1 lần nữa cần phải logout
	string response;
	string username, password;
	iss >> username >> password;
	response = query.queryDatabase("CHECK_USER_CREDENTIALS", username, password);
	if(response == "SUCCESS: Username và password hợp lệ!"){
		// Set status users do online
		int user_id = stoi(query.queryDatabase("SEARCH_USER_ID", username, password));
		query.queryDatabase("UPDATE_STATE", client_socket, user_id);
	}
	return response;
}