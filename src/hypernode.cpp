#include <stdint.h>
#include "hypernode.h"

HyperNode::HyperNode (int64_t val) {
  _key = val;
  _children = nullptr;
}

HyperNode::~HyperNode () {
  delete[] _children;
}

uint8_t HyperNode::_compare (int64_t val_b) const {
  // Note: Each line is a power of 255, starting at 255^1, going to 255^8
  uint8_t result = ((_key & 255U) < (val_b & 255U))
    | ((_key & 65280U) < (val_b & 65280U)) << 1
    | ((_key & 16711680U) < (val_b & 16711680U)) << 2
    | ((_key & 4278190080U) < (val_b & 4278190080U)) << 3
    | ((_key & 1095216660480UL) < (val_b & 1095216660480UL)) << 4
    | ((_key & 280375465082880UL) < (val_b & 280375465082880UL)) << 5
    | ((_key & 71776119061217280UL) < (val_b & 71776119061217280UL)) << 6
    | ((_key & 18374686479671623680UL) < (val_b & 18374686479671623680UL)) << 7;

  return result;
}

int64_t HyperNode::value () const {
  return _key;
}

HyperNode* HyperNode::find (int64_t value) const {
  if (_children == nullptr) return nullptr;

  return _children[_compare(value)];
}