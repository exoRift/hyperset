#include "../comparison/regularset.h"
#include <iostream>
#include <fstream>
#include <chrono>

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

  auto insertStart = std::chrono::steady_clock::now();
  while (insert >> num) {
    const bool regular_status = regular.insert(num);
  }
  std::cout << "Insert: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - insertStart).count() << "ms" << std::endl;
  auto queryStart = std::chrono::steady_clock::now();
  while (query >> num) {
    const RegularNode* regular_status = regular.find(num);
  }
  std::cout << "Query: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - queryStart).count() << "ms" << std::endl;

  insert.close();
  query.close();

  return 0;
}