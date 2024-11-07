#include "../server.h"

std::string Server::show_list_project(const int&sd) {
	std::string response = "Show failed";
	account_list.displayAllAccounts();
	// for (const auto& user : users) {
	// 	if (user.get_socket() == sd && user.get_account().has_value()) {
	// 		user.get_account().value()->displayListProject();
	// 		response = "Show success";
	// 	}
	// }
	return response;
}