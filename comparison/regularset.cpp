#include "regularset.h"
#include "regularnode.h"

RegularSet::RegularSet () {
  _root = nullptr;
}

RegularSet::~RegularSet () {
  clear();
}

void RegularSet::clear () {
  delete _root;
  _root = nullptr;
}

RegularNode* RegularSet::_find_best (RegularNode* node, int64_t val) const {
  if (node->value() == val) return node;

  RegularNode* next = node->find(val);

  if (next == nullptr) return node;
  return _find_best(next, val);
}

bool RegularSet::insert (int64_t val) {
  RegularNode* best = _find_best(_root, val);

  if (best->value() == val) return false;

  RegularNode* node = new RegularNode(val);
  if (best->_compare(val)) best->_left = node;
  else best->_right = node;

  return true;
}

RegularNode* RegularSet::find (int64_t val) const {
  RegularNode* best = _find_best(_root, val);

  if (best->value() == val) return best;

  return nullptr;
}