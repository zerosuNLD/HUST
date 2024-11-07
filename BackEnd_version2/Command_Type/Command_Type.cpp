// CommandType.cpp
#include "Command_Type.h"

// Định nghĩa hàm parse_command
CommandType parse_command(const std::string &command) {
  static const std::unordered_map<std::string, CommandType> command_map = {
      {"SIGNUP", SIGNUP},
      {"LOGIN", LOGIN},
      {"GET_ACCOUNT", GET_ACCOUNT},
      {"GETNAME", GETNAME},
      {"SHOW_LIST_STUDENT", SHOW_LIST_STUDENT},
      {"CREATE_PROJECT", CREATE_PROJECT},
      {"SHOW_LIST_PROJECT",SHOW_LIST_PROJECT},
      {"CREATE_TASK", CREATE_TASK},
      {"SHOW_LIST_TASKS", SHOW_LIST_TASKS},
      {"UPDATE_STATE", UPDATE_STATE}};

  auto it = command_map.find(command);
  return it != command_map.end() ? it->second : UNKNOWN;
}
