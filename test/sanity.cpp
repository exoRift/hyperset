#include "../src/hyperset.h"
#include "../comparison/regularset.h"
#include <iostream>
#include <vector>

std::vector<int64_t> insert = {3, 6, 2, -4, 8, 3, 11, -24, 7, -4, 6};
std::vector<bool> insert_status = {true, true, true, true, true, false, true, true, true, false, false};
std::vector<int64_t> query = {11, 34, 2, 3, -4, 100, 200, 8};
std::vector<bool> query_status = {true, false, true, true, true, false, false, true};

int main () {
  HyperSet hyper;
  RegularSet regular;

  int64_t num;

  for (size_t i = 0; i < insert.size(); ++i) {
    int64_t num = insert[i];
    bool desired_status = insert_status[i];
    bool hyper_status = hyper.insert(num);
    bool regular_status = regular.insert(num);

    if (hyper_status != desired_status) {
      std::cerr << "INSERT MISMATCH: " << i << " " << num << " Hyp: " << hyper_status << " Des: " << desired_status << std::endl;

      return 1;
    }
    if (regular_status != desired_status) {
      std::cerr << "INSERT MISMATCH: " << i << " " << num << " Reg: " << regular_status << " Des: " << desired_status << std::endl;

      return 1;
    }
  }
  for (size_t i = 0; i < query.size(); ++i) {
    int64_t num = query[i];
    bool desired_status = query_status[i];
    HyperNode* hyper_status = hyper.find(num);
    RegularNode* regular_status = regular.find(num);

    if (desired_status) {
      if (hyper_status == nullptr) {
        std::cerr << "QUERY MISMATCH: " << i << " " << num << ", Hyper not found, expected." << std::endl;

        return 1;
      }
      if (regular_status == nullptr) {
        std::cerr << "QUERY MISMATCH: " << i << " " << num << ", Regular not found, expected." << std::endl;

        return 1;
      }

      if (hyper_status->value() != num) {
        std::cerr << "QUERY MISMATCH: " << num << ", Hyper returned: " << hyper_status->value() << std::endl;

        return 1;
      }
      if (regular_status->value() != num) {
        std::cerr << "QUERY MISMATCH: " << num << ", Regular returned: " << regular_status->value() << std::endl;

        return 1;
      }
    } else {
      if (hyper_status != nullptr) {
        std::cerr << "QUERY MISMATCH: " << num << ", Hyper found, not expected." << std::endl;

        return 1;
      }

      if (regular_status != nullptr) {
        std::cerr << "QUERY MISMATCH: " << num << ", Regular found, not expected." << std::endl;

        return 1;
      }
    }
  }

  return 0;
}