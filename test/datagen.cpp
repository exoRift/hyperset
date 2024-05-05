#include <iostream>
#include <fstream>

int main () {
  std::ofstream insert;
  insert.open("insert.txt");
  std::ofstream query;
  query.open("query.txt");

  if (insert.bad() || query.bad()) {
    std::cerr << "Failed to open files" << std::endl;
    return 1;
  }

  for (uint32_t i = 0; i < 10000; ++i) {
    int64_t number = ((int64_t)arc4random() << 32) | arc4random();

    insert << number << std::endl;
  }
  for (uint32_t i = 0; i < 10000; ++i) {
    int64_t number = ((int64_t)arc4random() << 32) | arc4random();

    query << number << std::endl;
  }

  insert.close();
  query.close();

  return 0;
}