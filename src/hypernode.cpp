#include <stdint.h>
#include "hypernode.h"

HyperNode::HyperNode (int64_t val) {
  _key = val;
  for (uint8_t i = 0; i < 255; ++i) _children[i] = nullptr;
}

HyperNode::~HyperNode () {
  for (uint8_t i = 0; i < 255; ++i) delete _children[i];
}

uint8_t HyperNode::_compare (int64_t val_b) const {
  uint8_t result = 0;

  // Note: Each line is a power of 255, starting at 255^1, going to 255^8
  result |= (val_b & 255U) < (_key & 255U);
  result |= (val_b & 65280U) < (_key & 65280U) << 1;
  result |= (val_b & 16711680U) < (_key & 16711680U) << 2;
  result |= (val_b & 4278190080U) < (_key & 4278190080U) << 3;
  result |= (val_b & 1095216660480UL) < (_key & 1095216660480UL) << 4;
  result |= (val_b & 280375465082880UL) < (_key & 280375465082880UL) << 5;
  result |= (val_b & 71776119061217280UL) < (_key & 71776119061217280UL) << 6;
  result |= (val_b & 18374686479671623680UL) < (_key & 18374686479671623680UL) << 7;

  return ~result;
}

int64_t HyperNode::value () const {
  return _key;
}

HyperNode* HyperNode::find (int64_t value) const {
  return _children[_compare(value)];
}