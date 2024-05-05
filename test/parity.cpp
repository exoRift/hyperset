#include "../src/hyperset.h"
#include "../comparison/regularset.h"
#include <iostream>
#include <fstream>

int main () {
  std::ifstream insert;
  insert.open("insert.txt");
  std::ifstream query;
  query.open("query.txt");

  HyperSet hyper;
  RegularSet regular;

  if (insert.bad() || query.bad()) {
    std::cerr << "Failed to open files" << std::endl;
    return 1;
  }

  int64_t num;

  while (insert >> num) {
    bool hyper_status = hyper.insert(num);
    bool regular_status = regular.insert(num);

    if (hyper_status != regular_status) {
      std::cerr << "INSERT MISMATCH: " << num << " Hyp: " << hyper_status << " Reg: " << regular_status << std::endl;

      return 1;
    }
  }
  while (query >> num) {
    HyperNode* hyper_status = hyper.find(num);
    RegularNode* regular_status = regular.find(num);

    if (hyper_status == nullptr || regular_status == nullptr) {
      if (hyper_status) {
        std::cerr << "QUERY MISMATCH: " << num << ", Hyper found, regular not found." << std::endl;

        return 1;
      }
      if (regular_status) {
        std::cerr << "QUERY MISMATCH: " << num << ", Hyper not found, regular found." << std::endl;

        return 1;
      }

      continue;
    }

    if (hyper_status->value() != regular_status->value()) {
      std::cerr << "QUERY MISMATCH: " << num << " Hyp: " << hyper_status->value() << " Reg: " << regular_status->value() << std::endl;

      return 1;
    }
  }

  insert.close();
  query.close();

  return 0;
}