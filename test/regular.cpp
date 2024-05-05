#include "../comparison/regularset.h"
#include <iostream>
#include <fstream>

int main () {
  std::ifstream insert;
  insert.open("insert.txt");
  std::ifstream query;
  query.open("query.txt");

  RegularSet regular;

  if (insert.bad() || query.bad()) {
    std::cerr << "Failed to open files" << std::endl;
    return 1;
  }

  int64_t num;

  while (insert >> num) {
    const bool regular_status = regular.insert(num);
  }
  while (query >> num) {
    const RegularNode* regular_status = regular.find(num);
  }

  insert.close();
  query.close();

  return 0;
}