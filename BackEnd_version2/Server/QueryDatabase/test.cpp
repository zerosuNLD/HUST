#include "QueryDatabase.h"

int main() {
  QueryDatabase query = QueryDatabase("root", "123456", "quan_ly_cong_viec");

  query.queryDatabase("CLOSE_ALL_USERS");
  return 0;
}
