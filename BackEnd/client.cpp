#include "Client/client.h"
// #include "crow_all.h"
#include <iostream>
#include <string>
// #include "Router/Router.h"

#define POST 8080
#define localhost "127.0.0.1"
#include "Command_Type/Command_type.h"
#define MAX_ThanhVien 100

// Hằng số cho các phản hồi từ server
// const std::string SIGNUP_SUCCESS = "SIGNUP SUCCESS";
// const std::string LOGIN_SUCCESS = "LOGIN SUCCESS";
// const std::string SIGNUP_FAIL = "SIGNUP FAIL";
// const std::string LOGIN_FAIL = "LOGIN FAIL";
void login(const Client &client) {
	string username = "admin", password = "admin";
	// cout << "Username: ";
	// cin >> username;
	// cout << "Password: ";
	// cin >> password;
	string request_str = "LOGIN " + username + " " + password;

	cout << request_str << endl;
	string reponse = client.send_request(request_str);

	cout << "Reponse from server: " << reponse << endl;
}

void signup(const Client &client) {
	string username, password, name, email;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	int age;
	cout << "Input your name: ";
	cin >> name;
	cout << "Input age: ";
	cin >> age;
	cout << "Input email: ";
	cin >> email;

	string request_str = "SIGNUP " + username + " " + password + " " + name +
	                     " " + to_string(age) + " " + email;

	string reponse = client.send_request(request_str);

	cout << "Reponse from server: " << reponse << endl;
}

void create_new_project(const Client &client) {
	string name_project, Mo_ta;
	int n_thanhvien;
	string ds_thanhvien[MAX_ThanhVien];
	// cout << "Nhap ten du an: ";
	// cin >> name_project;
	// cout << "Mo ta: ";
	// cin >> Mo_ta;
	// cout << "Nhap so luong thanh vien: ";
	// cin >> n_thanhvien;
	// for (int i = 0; i < n_thanhvien; i++) {
	//   cout << "Nhap thanh vien " << i << ": ";
	//   cin >> ds_thanhvien[i];
	// }

	// string request_str = "CREATE_PROJECT " + name_project + " " + Mo_ta;
	// for (int i = 0; i < n_thanhvien; i++) {
	//   request_str += " " + ds_thanhvien[i];
	// }

	// cout << request_str;

	string request_str = "CREATE_PROJECT test mo_ta 1 2 3";

	cout << endl
	     << "Messenge from server: " << endl
	     << client.send_request(request_str) << endl;
}

void start(const Client &client, const std::string &request) {
	CommandType command = parse_command(request);
	switch (command) {
		case LOGIN:
			login(client);
			break;

		case SIGNUP:
			signup(client);
			break;

		case GET_ACCOUNT:

			break;

		case SHOW_LIST_PROJECT: {
			string reponse = client.send_request(request);
			break;
		}

		case GETNAME: {
			string reponse = client.send_request(request);
			cout << "Hi! " << reponse << endl;
			// Xử lý lệnh GETNAME
			break;
		}

		case SHOW_LIST_ACCOUNT: {
			string reponse = client.send_request(request);
			cout << "Reponse from server: " << reponse << endl;
			break;
		}

		case CREATE_PROJECT:
			create_new_project(client);
			break;

		default:
			// Xử lý lệnh không xác định
			cout << request << " command not found!!" << endl;
			break;
	}
}

int main() {
	Client client(localhost, POST);
	// crow::SimpleApp app;

	string request;
	while (true) {
		cout << "++++++++++++++++++++++++++++" << endl;
		cout << "Request: ";
		cin >> request;
		start(client, request);
		cout << "++++++++++++++++++++++++++++" << endl;
	}
	// setupRoutes(app, client, "Signup");

	// app.port(3001).multithreaded().run();

	return 0;
}
