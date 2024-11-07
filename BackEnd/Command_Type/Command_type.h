// CommandType.h
#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

#include <string>
#include <unordered_map>

// Định nghĩa các lệnh dưới dạng enum
enum CommandType { SIGNUP, LOGIN, GET_ACCOUNT, GETNAME, SHOW_LIST_ACCOUNT, CREATE_PROJECT, SHOW_LIST_PROJECT, UNKNOWN };

// Khai báo hàm parse_command
CommandType parse_command(const std::string &command);

#endif // COMMAND_TYPE_H
