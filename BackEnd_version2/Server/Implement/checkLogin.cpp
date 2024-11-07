#include "../Server.h"

string Server::checkLogin(const int &client_socket) {
	return query.queryDatabase2("CHECK_LOGIN", client_socket);
}