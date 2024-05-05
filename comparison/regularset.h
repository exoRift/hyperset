#ifndef _regularset_h
#define _regularset_h
#include "regularnode.h"

class RegularSet {
  private:
    RegularNode* _root;

    RegularNode* _find_best (RegularNode* node, int64_t val) const;
  public:
    RegularSet ();
    ~RegularSet ();

    bool insert (int64_t val);
    bool erase (int64_t val);
    void clear ();

    RegularNode* find (int64_t val) const;
};

#endif