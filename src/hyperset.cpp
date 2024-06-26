#include "hyperset.h"
#include "hypernode.h"

HyperSet::HyperSet () {
  _root = nullptr;
}

HyperSet::~HyperSet () {
  clear();
}

void HyperSet::clear () {
  delete _root;
  _root = nullptr;
}

HyperNode* HyperSet::_find_best (HyperNode* node, int64_t val) const {
  if (node->value() == val) return node;

  HyperNode* next = node->find(val);

  if (next == nullptr) return node;
  return _find_best(next, val);
}

bool HyperSet::insert (int64_t val) {
  if (_root == nullptr) {
    _root = new HyperNode(val);

    return true;
  }

  HyperNode* best = _find_best(_root, val);

  if (best->value() == val) return false;

  HyperNode* node = new HyperNode(val);
  const uint8_t index = best->_compare(val);
  if (best->_children == nullptr) best->_children = new HyperNode*[256]();
  best->_children[index] = node;

  return true;
}

HyperNode* HyperSet::find (int64_t val) const {
  HyperNode* best = _find_best(_root, val);

  if (best->value() == val) return best;

  return nullptr;
}