#include "Student.h"
#include "RunProgram.h"
#include <iostream>

void RunProgram::createTrees(){
  BST<Student> masterStudent;
  Student s1(01, "Jon Flees", "Sophomore", "Data Analytics", 3.15, 03);
  Student s2(02, "Cadre Carrigan", "Sophomore", "Data Analytics", 3.57, 04);
  masterStudent.insert(s1);
  masterStudent.insert(s2);
  if (masterStudent.contains(s2))
    cout << s2.getID() << endl;
}

void RunProgram::printMenu(){
  cout << "~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~" << endl;
  cout << " 1) Print all students and their information (sorted by ascending id #)" << endl;
  cout << " 2) Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << " 3) Find and display student information given the students id" << endl;
  cout << " 4) Find and display faculty information given the faculty id" << endl;
  cout << " 5) Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << " 6) Given a faculty id, print ALL the names and info of his/her advisees" << endl;
  cout << " 7) Add a new student" << endl;
  cout << " 8) Delete a student given the id" << endl;
  cout << " 9) Add a new faculty member" << endl;
  cout << " 10) Delete a faculty member given the id" << endl;
  cout << " 11) Change a student’s advisor given the student id and the new faculty id" << endl;
  cout << " 12) Remove an advisee from a faculty member given the ids" << endl;
  cout << " 13) Rollback" << endl;
  cout << " 14) Exit" << endl;
}

void RunProgram::menuSelection(int menuSel){
  switch(menuSel){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      break;
  }
}








template <class T>
TreeNode<T>::TreeNode()
{
  left = NULL;
  right =  NULL;
}

template <class T>
TreeNode<T>::TreeNode(T &k)
{
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode()
{
  // lets do a little research
}








template <class T>
BST<T>::BST() //default constructor
{
  root = NULL;  //empty tree
}

template <class T>
BST<T>::~BST()
{
  //iterate and delete
  //lets put on our research hats
}

template <class T>
void BST<T>::printTree()
{
  recPrint(root);
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if(node==NULL)
    return;
  else
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

template <class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}

template <class T>
void BST<T>::insert(T &value)
{
  // check if value exists, use contains(), if DNE then continue
  TreeNode<T> *node = new TreeNode<T>(value);   //key is now set to  value
  if(isEmpty())   //empty tree
  {
    root = node;
  }
  else    //not an empty tree, need to find insertion point
  {
    TreeNode<T> *current = root;
    TreeNode<T> *parent;   //empty node

    while(true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left;   //going left

        if(current==NULL)  //we found the insertion point for new node
        {
          parent->left = node;
          break;
        }
        //else keep looping
      }
      else //going right
      {
        current = current->right;

        if(current==NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(T &value)
{
  if(isEmpty())
    return false;
  else  //not empty tree
  {
    TreeNode<T> *current = root;

    while(current->key != value)
    {
      if(value < current->key)  //going left
        current = current->left;
      else
        current = current->right;
      if(current == NULL)   //we did not find it, DNE
        return false;
    }
  }
  return true;
}
