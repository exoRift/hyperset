#ifndef _regularnode_h
#define _regularnode_h

#include <stdint.h>

class RegularNode {
  friend class RegularSet;

  private:
    int64_t _key;
    RegularNode* _left;
    RegularNode* _right;

    bool _compare (int64_t val_b) const;
  public:
    RegularNode (int64_t val);
    ~RegularNode ();

    int64_t value () const;
    RegularNode* find (int64_t val) const;
};

#endif