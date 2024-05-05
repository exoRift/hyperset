#include "../src/hyperset.h"
#include <iostream>
#include <fstream>

int main () {
  std::ifstream insert;
  insert.open("insert.txt");
  std::ifstream query;
  query.open("query.txt");

  HyperSet hyper;

  if (insert.bad() || query.bad()) {
    std::cerr << "Failed to open files" << std::endl;
    return 1;
  }

  int64_t num;

  while (insert >> num) {
    bool hyper_status = hyper.insert(num);
  }
  while (query >> num) {
    HyperNode* hyper_status = hyper.find(num);
  }

  insert.close();
  query.close();

  return 0;
}