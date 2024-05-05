#include <stdint.h>
#include "regularnode.h"

RegularNode::RegularNode (int64_t val) {
  _key = val;
  _left = nullptr;
  _right = nullptr;
}

RegularNode::~RegularNode () {
  delete _left;
  delete _right;
}

bool RegularNode::_compare (int64_t val_b) const {
  return val_b < _key;
}

int64_t RegularNode::value () const {
  return _key;
}

RegularNode* RegularNode::find (int64_t value) const {
  if (_compare(value)) return _left;

  return _right;
}