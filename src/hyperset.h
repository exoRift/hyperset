#ifndef _hyperset_h
#define _hyperset_h
#include "hypernode.h"

class HyperSet {
  private:
    HyperNode* _root;

    HyperNode* _find_best (HyperNode* node, int64_t val) const;
  public:
    HyperSet ();
    ~HyperSet ();

    bool insert (int64_t val);
    bool erase (int64_t val);
    void clear ();

    HyperNode* find (int64_t val) const;
};

#endif