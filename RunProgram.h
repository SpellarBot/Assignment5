#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "GenStack.h"
#ifndef RUNPROGRAM_H
#define RUNPROGRAM_H

class RunProgram{
public:
  void createTrees();
  void printMenu();
  void menuSelection(int menuSel);
  void printAllStudents();
  void printAllFaculty();
  void createStudentTableFile();
  void createFacultyTableFile();
  void deleteStudent(int id);
  void getStudentList(int id);
  void searchAdvisorID(int id);
  void changeAdvisorID(int stud, int fac);
  void printAdvisees(int id);
  void deleteStudent();
  void saveCommand();
  void Rollback();
};
#endif


template <class T>
class TreeNode {
public:
  TreeNode();
  TreeNode(T &key);
  virtual ~TreeNode();

  int data;
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
  bool contains(int value);  //AKA search
  bool deleteNode(T &value);   //T or F if the node was deleted

  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  bool deleteRec();

  TreeNode<T>* getMin();
  TreeNode<T>* getMax();
  bool isEmpty();
  void printTree();
  void recPrint(TreeNode<T> *d);
  void fileTree();
  void recFile(TreeNode<T> *d);
  T find(int id);
  int findAdID(int id);
  int findAdvisees(int id);
  void changeAdID(int stud, int fac);
  void addToAdvisor(int value, int fac);
  void removeFromAdvisor(int value, int fac);
  bool deleteThis(int value);
  TreeNode<T>* getNext(TreeNode<T> *d);

private:
  TreeNode<T> *root;
};
