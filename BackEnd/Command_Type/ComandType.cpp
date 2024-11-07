// CommandType.cpp
#include "Command_type.h"

// Định nghĩa hàm parse_command
CommandType parse_command(const std::string &command) {
  static const std::unordered_map<std::string, CommandType> command_map = {
      {"SIGNUP", SIGNUP},
      {"LOGIN", LOGIN},
      {"GET_ACCOUNT", GET_ACCOUNT},
      {"GETNAME", GETNAME},
      {"SHOW_LIST_ACCOUNT", SHOW_LIST_ACCOUNT},
      {"CREATE_PROJECT", CREATE_PROJECT},
      {"SHOW_LIST_PROJECT",SHOW_LIST_PROJECT}};

  auto it = command_map.find(command);
  return it != command_map.end() ? it->second : UNKNOWN;
}
