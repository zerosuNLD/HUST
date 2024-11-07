#include "Server.h"
#include <string>

void Server::start() {
    while (true) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(server_sock, &readfds);
        int max_fd = server_sock;

        for (int i = 0; i < MAX_SOCKET; ++i) {
            int sd = sockets[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_fd) max_fd = sd;
        }

        int activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            std::cerr << "Select error." << std::endl;
            continue;
        }

        if (FD_ISSET(server_sock, &readfds)) {
            accept_new_client();
        }

        for (int i = 0; i < MAX_SOCKET; ++i) {
            int sd = sockets[i];
            if (FD_ISSET(sd, &readfds)) {
                process_client_request(sd, i);
            }
        }
    }
}

void Server::accept_new_client() {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_socket = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);
    if (client_socket < 0) {
        std::cerr << "Accept failed." << std::endl;
        return;
    }

    for (int i = 0; i < MAX_SOCKET; ++i) {
        if (sockets[i] == -1) {
            sockets[i] = client_socket;
            std::cout << "Socket: " << client_socket << " is used!" << std::endl;
            break;
        }
    }
}

void Server::process_client_request(int sd, int index) {
    char request[BUFFER_SIZE];
    int bytes_received = recv(sd, request, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        request[bytes_received] = '\0';
        std::string request_str(request);
        
        handle_request(sd, request_str);
        
    } else {
        std::cerr << "Client disconnected: " << sd << std::endl;
        close(sd);
        reset_socket(sd, index);
    }
}

void Server::reset_socket(int sd, int index) {
    query.queryDatabase("CLOSE_STATE", sd);
    sockets[index] = -1;
}
