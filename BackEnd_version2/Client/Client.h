#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>  
#include <unistd.h>    

using namespace std;

#define BUFFER_SIZE 1024

class Client {
private:
    string server_ip;
    int server_port;
    int client_socket;

    void report_err(const char* message); 
    void connect_to_server(); 

public:
    Client(const string& ip, int port);  
    ~Client();
    std::string send_request(const std::string& request) const;
    void close_socket(); 
};

#endif 
