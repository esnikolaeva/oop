#ifndef TREE_H
#define TREE_H
#include "Tnode.h"
#include "Rhomb.h"
class Tree {
public:
    Tree();
    void Create(Rhomb a);
    ~Tree();
    static void DestroyNode(Tnode* node);
    void Insert(Rhomb r);
    void GetNode(Tnode* node, double s);
    void DeleteNode(Tnode* node, double s);
    friend std::ostream& operator<<(std::ostream& os, const Tree& obj);
    Tnode* Root;
};
#endif
