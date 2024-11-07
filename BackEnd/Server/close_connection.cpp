#include "server.h"

// Cài đặt phương thức close_connection
void Server::close_connection() {
    for (int i = 0; i < MAX_SOCKET; ++i) {
        if (sockets[i] != -1) { // Kiểm tra xem client đã kết nối
            sockets[i] = -1;          // Gọi phương thức disconnect để đóng kết nối
        }
    }
}