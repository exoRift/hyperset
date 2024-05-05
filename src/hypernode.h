#ifndef _hypernode_h
#define _hypernode_h

#include <stdint.h>

class HyperNode {
  friend class HyperSet;

  private:
    int64_t _key;
    HyperNode* _children[256];

    uint8_t _compare (int64_t val_b) const;
  public:
    HyperNode (int64_t val);
    ~HyperNode ();

    int64_t value () const;
    HyperNode* find (int64_t val) const;
};

#endif