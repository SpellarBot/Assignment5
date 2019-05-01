#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#ifndef RUNPROGRAM_H
#define RUNPROGRAM_H

class RunProgram{
public:
  void createTrees();
  void printMenu();
  void menuSelection(int menuSel);
};
#endif


template <class T>
class TreeNode {
public:
  TreeNode();
  TreeNode(T &key);
  virtual ~TreeNode();

  T key;
  TreeNode<T> *left;
  TreeNode<T> *right;
};


template  <class T>
class BST{
public:
  BST();
  virtual ~BST();
  void insert(T &value);
  bool contains(T &value);  //AKA search
  bool deleteNode(T &value);   //T or F if the node was deleted

  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  bool deleteRec();

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  bool isEmpty();
  void printTree();
  void recPrint(TreeNode<T> *d);

private:
  TreeNode<T> *root;
};
