#include "../Server.h"

string Server::showListStudent(const int &client_socket, std::istringstream &iss) {
	string check = checkLogin(client_socket);
	cout << check << endl;
	if(check=="User đã thực hiện login"){
		string res; 
		iss >> res;
		// Hiển thị danh sách sinh viên 1 project
		if (res == "PROJECT") {
			int project_id;
			iss >> project_id;
			return query.queryDatabase2("SHOW_LIST_STUDENT_PROJECT", project_id);
		}else if(res == "TASK"){
			// Hiển thị danh sách sinh viên 1 task 
			return "Chưa có code cho phần này";
		}
		else if(res == "ALL") {
			// Hiển thị tất cả sinh viên
			return "Chưa có code cho phần này";
		}else{
			return "ERROR: " + res + " not found!!";
		}
	}
	return check;
}