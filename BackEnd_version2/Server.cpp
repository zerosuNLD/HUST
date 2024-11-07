#include "Server/Server.h"
#include <csignal>
#include <unistd.h> 

#define PORT 8080
const string username = "root";
const string password = "123456";
const string database = "quan_ly_cong_viec";

int main() {
    
    Server server(PORT, username, password, database);
    server.start();

    return 0;
}