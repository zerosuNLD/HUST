#include "../server.h"

// Kiểm tra xem client đã thực hiện login hay chưa 
bool Server::check_client_login(const int& sd){
	for (const auto& user : users) {
		if(user.get_socket() == sd){
			return true;
		}
	}
	return false;
}