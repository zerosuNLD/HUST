# Đặt biến cho trình biên dịch và cờ biên dịch
CXX = g++
CXXFLAGS = -lpthread

# Tên file thực thi
TARGET_SERVER = server
TARGET_CLIENT = client

# Danh sách file nguồn
SRCS_SERVER = server.cpp \
              Server/Start.cpp \
              Server/Handle_request.cpp \
              Server/close_connection.cpp \
              Server/Server_Constructor.cpp \
              Server/Request_Implement/init_user.cpp \
              Server/Request_Implement/login.cpp \
              Server/Request_Implement/signup.cpp \
              Server/Request_Implement/create_project.cpp \
              Server/Request_Implement/check_client_login.cpp \
              Server/Request_Implement/show_list_project.cpp \
              Account/account.cpp \
              Account/AccountList.cpp \
              Account/Project/Project.cpp \
              Command_Type/ComandType.cpp   

SRCS_CLIENT = client.cpp \
              Client/Client_Constructor.cpp \
              Client/Send_request.cpp   \
              Router/Router.cpp \
              Command_Type/ComandType.cpp

# Quy tắc để biên dịch
.PHONY: all clean

# Biên dịch file thực thi khi gọi make server
server: $(SRCS_SERVER)
	$(CXX) $(SRCS_SERVER) -o $(TARGET_SERVER) $(CXXFLAGS)

# Biên dịch file thực thi khi gọi make client
client: $(SRCS_CLIENT)
	$(CXX) $(SRCS_CLIENT) -o $(TARGET_CLIENT) $(CXXFLAGS)

# Quy tắc mặc định
all: server client

# Xóa file thực thi và file đối tượng
clean:
	rm -f $(TARGET_SERVER) $(TARGET_CLIENT)
