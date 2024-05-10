#include "../src/hyperset.h"
#include <iostream>
#include <fstream>
#include <chrono>

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

  auto insertStart = std::chrono::steady_clock::now();
  while (insert >> num) {
    const bool hyper_status = hyper.insert(num);
  }
  std::cout << "Insert: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - insertStart).count() << "ms" << std::endl;
  auto queryStart = std::chrono::steady_clock::now();
  while (query >> num) {
    const HyperNode* hyper_status = hyper.find(num);
  }
  std::cout << "Query: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - queryStart).count() << "ms" << std::endl;

  insert.close();
  query.close();

  return 0;
}