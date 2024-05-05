#include "../src/hyperset.h"
#include "../comparison/regularset.h"
#include <iostream>
#include <fstream>
#include <set>

int main () {
  std::ifstream insert;
  insert.open("insert.txt");
  std::ifstream query;
  query.open("query.txt");

  std::set<int64_t> sanity;
  HyperSet hyper;
  RegularSet regular;

  if (insert.bad() || query.bad()) {
    std::cerr << "Failed to open files" << std::endl;
    return 1;
  }

  int64_t num;

  while (insert >> num) {
    size_t original_size = sanity.size();
    sanity.insert(num);
    size_t new_size = sanity.size();
    const bool sanity_status = new_size != original_size;
    const bool hyper_status = hyper.insert(num);
    const bool regular_status = regular.insert(num);

    if (hyper_status != sanity_status || regular_status != sanity_status) {
      std::cerr << "INSERT MISMATCH: " << num << " Hyp: " << hyper_status << " Reg: " << regular_status << " San: " << sanity_status << std::endl;

      return 1;
    }
  }
  while (query >> num) {
    const auto sanity_iterator = sanity.find(num);
    const HyperNode* hyper_status = hyper.find(num);
    const RegularNode* regular_status = regular.find(num);

    if (sanity_iterator == sanity.end()) {
      if (hyper_status) {
        std::cerr << "QUERY MISMATCH: " << num << ", Hyper found, sanity not found." << std::endl;

        return 1;
      }
      if (regular_status) {
        std::cerr << "QUERY MISMATCH: " << num << ", Regular found, sanity not found." << std::endl;

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