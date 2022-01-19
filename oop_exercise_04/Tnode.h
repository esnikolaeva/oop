#ifndef TNODE_H
#define TNODE_H
#include "Rhomb.h"
class Tnode {
public:
    Tnode(Rhomb r);
    Rhomb rb;
    Tnode* Parent = nullptr;
    Tnode* Left = nullptr;
    Tnode* Right = nullptr;
};
#endif
