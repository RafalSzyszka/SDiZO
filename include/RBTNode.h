#ifndef RBTNODE_H
#define RBTNODE_H


struct RBTNode
{
  RBTNode * up;
  RBTNode * left;
  RBTNode * right;
  int key;
  char color;
};

#endif // RBTNODE_H
