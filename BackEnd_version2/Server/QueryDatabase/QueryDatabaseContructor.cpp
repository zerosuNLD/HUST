#include "QueryDatabase.h"

QueryDatabase::QueryDatabase(const string &username, const string &password,
                             const string &database)
    : username(username), password(password), database(database) {
  this->con = connectDatabase(this->username, this->password, this->database);
}

unique_ptr<sql::Connection> QueryDatabase::connectDatabase(const string &username,
                                                           const string &password,
                                                           const string &database) {
  sql::mysql::MySQL_Driver *driver;
  unique_ptr<sql::Connection> con;

  try {
    driver = sql::mysql::get_mysql_driver_instance();
    con.reset(driver->connect("tcp://127.0.0.1:3306", username, password));
    con->setSchema(database);

    cout << "Kết nối cơ sở dữ liệu thành công!" << endl;
    return con;
  } catch (sql::SQLException &e) {
    cerr << "Lỗi MySQL: " << e.what() << endl;
    return nullptr;
  }
}


QueryDatabase::~QueryDatabase() {
  // Đảm bảo rằng tài nguyên kết nối cơ sở dữ liệu được giải phóng tự động
  if (con) {
    con->close();
  }
  std::cout << "Đã hủy đối tượng QueryDatabase và giải phóng tài nguyên!" << std::endl;
}