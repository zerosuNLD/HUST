# Đặt biến cho trình biên dịch và cờ biên dịch
CXX = g++
CXXFLAGS = -std=c++11 # Thêm chuẩn C++ 
LDFLAGS_SERVER = -lmysqlcppconn # Cờ liên kết cho server
LDFLAGS_CLIENT = -lmysqlcppconn -lc -lstdc++

# Tên file thực thi
TARGET_SERVER = server
TARGET_CLIENT = client

# Danh sách file nguồn
SRCS_SERVER = Server.cpp \
              Server/Start.cpp \
              Server/Handle_Request.cpp \
              Server/ServerContructor.cpp \
              Server/Implement/login.cpp \
              Server/Implement/signup.cpp \
              Server/Implement/showListProject.cpp \
              Server/Implement/checkLogin.cpp \
              Server/Implement/createProject.cpp \
              Server/Implement/showListStudent.cpp \
              Server/Implement/createTask.cpp \
              Server/Implement/createTask.cpp \
              Server/Implement/showListTasks.cpp \
              Server/Implement/updateStatus.cpp \
              Server/QueryDatabase/queryDatabase.cpp \
              Server/QueryDatabase/QueryDatabaseContructor.cpp \
              Server/QueryDatabase/Implement_query/checkUserCredentials.cpp \
              Server/QueryDatabase/Implement_query/checkUserId.cpp \
              Server/QueryDatabase/Implement_query/closeStateAllUsers.cpp \
              Server/QueryDatabase/Implement_query/setStateUser.cpp \
              Server/QueryDatabase/Implement_query/closeStateUser.cpp \
              Server/QueryDatabase/Implement_query/addNewUser.cpp \
              Server/QueryDatabase/Implement_query/showListProject.cpp \
              Server/QueryDatabase/Implement_query/checkLogin.cpp \
              Server/QueryDatabase/Implement_query/createNewProject.cpp \
              Server/QueryDatabase/Implement_query/addMemberToProject.cpp \
              Server/QueryDatabase/Implement_query/showListMembersProject.cpp \
              Server/QueryDatabase/Implement_query/createTask.cpp \
              Server/QueryDatabase/Implement_query/showListTasks.cpp \
              Server/QueryDatabase/Implement_query/updateStatus.cpp \
              Command_Type/Command_Type.cpp

SRCS_CLIENT = Client.cpp \
              Client/Client_Contructor.cpp \
              Client/Send_Request.cpp \
              Command_Type/Command_Type.cpp \

# Danh sách file đối tượng
OBJS_SERVER = $(SRCS_SERVER:.cpp=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.cpp=.o)

# Quy tắc để biên dịch
.PHONY: all clean

# Biên dịch cả server và client khi gọi make all
all: $(TARGET_SERVER) $(TARGET_CLIENT)

# Biên dịch file thực thi server
$(TARGET_SERVER): $(OBJS_SERVER)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS_SERVER)

# Biên dịch file thực thi client
$(TARGET_CLIENT): $(OBJS_CLIENT)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS_CLIENT)

# Quy tắc tự động để biên dịch file .cpp thành .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Xóa file thực thi và file đối tượng
clean:
	rm -f $(TARGET_SERVER) $(TARGET_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT)
