#include "Student.h"
#include "Faculty.h"
#ifndef RUNPROGRAM_H
#define RUNPROGRAM_H

class RunProgram{
public:
  void createTrees();
  void printMenu();
  void menuSelection(int menuSel);
};
#endif


class TreeNode {
public:
  TreeNode();
  TreeNode(int key);
  virtual ~TreeNode();

  int key;
  TreeNode *left;
  TreeNode *right;
};


class BST{
public:
  BST();
  virtual ~BST();
  void insert(int value);
  bool contains(int value);  //AKA search
  bool deleteNode(int value);   //T or F if the node was deleted

  TreeNode* getSuccessor(TreeNode* d);
  bool deleteRec();

  TreeNode* getMin();
  TreeNode* getMax();
  bool isEmpty();
  void printTree();
  void recPrint(TreeNode *d);

private:
  TreeNode *root;
};
