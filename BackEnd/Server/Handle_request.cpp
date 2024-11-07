#include <string>

// #include "../Account/Project/Project.h"
#include "../Command_Type/Command_type.h"
// #include "User/User.h"
#include "server.h"

void Server::handle_request(const int& sd, const std::string& request) {
	std::istringstream iss(request);
	std::string command_str;
	iss >> command_str;

	// Xác định loại lệnh
	CommandType command = parse_command(command_str);
	std::string response;  // Biến lưu trữ phản hồi sẽ gửi tới client
	std::cout << "Request from client: " << request << std::endl;
	switch (command) {
		case SIGNUP: {
			response = process_signup(iss);
			break;
		}

		case LOGIN: {
			response = process_login(sd, iss);

			break;
		}

		case GETNAME: {
			// if (check_client_login(sd)) {
			// 	for (const auto& user : users) {
			// 		if (user.get_socket() == sd) {
			// 			if (user.get_account().has_value()) {
			// 				Account* acc = user.get_account().value();
			// 				response = acc->getUsername();
			// 			}
			// 			break;
			// 		}
			// 	}
			// } else {
			// 	response = "ERROR: Cần phải login trước!!!";
			// }

			break;
		}

		case SHOW_LIST_PROJECT: {
			response = show_list_project(sd);
			break;
		}

		case CREATE_PROJECT: {
			response = create_project(sd, iss);
			break;
		}

		default:
			std::cerr << "Unknown command received: " << command_str
			          << std::endl;
			response = "UNKNOWN_COMMAND";
	}

	// Gửi phản hồi tới client
	send(sd, response.c_str(), response.size(), 0);
}
