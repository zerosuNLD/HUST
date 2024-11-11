#include <string>

// #include "../Account/Project/Project.h"
#include "../Command_Type/Command_Type.h"
// #include "User/User.h"
#include "Server.h"

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
			response = signup(sd, iss);
			break;
		}

		case LOGIN: {
			response = login(sd, iss);
			break;
		}

		case SHOW_LIST_PROJECT:
			response = showListProject(sd, iss);
			break;

		
		case CREATE_PROJECT: 
			response = createProject(sd, iss);
			break;

		case SHOW_LIST_STUDENT:
			response = showListStudent(sd, iss);
			break;

		case CREATE_TASK:
			response = createTask(sd, iss);
			break;

		case SHOW_LIST_TASKS:
			response = showListTasks(sd, iss);
			break;

		case UPDATE_STATE:
			response = updateStatus(sd, iss);
			break;
			
		default:
			std::cerr << "Unknown command received: " << command_str
			          << std::endl;
			response = "UNKNOWN_COMMAND";
	}

	// Gửi phản hồi tới client
	send(sd, response.c_str(), response.size(), 0);
}
