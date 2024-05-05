#include "../src/hyperset.h"
#include "../comparison/regularset.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main () {
  std::ifstream insert;
  insert.open("insert.txt");
  std::ifstream query;
  query.open("query.txt");

  HyperSet hyper;
  RegularSet regular;

  if (insert.bad() || query.bad()) {
    std::cout << "Failed to open files" << std::endl;
    return 1;
  }

  int64_t num;

  while (insert >> num) {
    std::cout << num << std::endl;

    bool hyper_status = hyper.insert(num);
    bool regular_status = regular.insert(num);

    if (hyper_status != regular_status) {
      std::cerr << "MISMATCH: " << num << " Hyp: " << hyper_status << " Reg: " << regular_status << std::endl;

      return 1;
    }
  }
  // while (query >> num) {
  //   std::cout << num << std::endl;

  //   bool hyper_status = hyper.insert(num);
  //   bool regular_status = regular.insert(num);

  //   if (hyper_status != regular_status) {
  //     std::cerr << "MISMATCH: " << num << " Hyp: " << hyper_status << " Reg: " << regular_status << std::endl;

  //     return 1;
  //   }
  // }

  insert.close();
  query.close();

  return 0;
}