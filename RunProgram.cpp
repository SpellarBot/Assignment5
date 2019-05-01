#include "Student.h"
#include "RunProgram.h"
#include <iostream>

void RunProgram::createTrees(){
  BST studentBST;
  Student s1(01, "Jon Flees", "Sophomore", "Data Analytics", 3.15, 03);
  studentBST.insert(01);
  if (studentBST.contains(01))
    cout << "Jon Flees" << endl;
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









TreeNode::TreeNode()
{
  left = NULL;
  right =  NULL;
}

TreeNode::TreeNode(int k)
{
  left = NULL;
  right = NULL;
  key = k;
}

TreeNode::~TreeNode()
{
  // lets do a little research
}









BST::BST() //default constructor
{
  root = NULL;  //empty tree
}

BST::~BST()
{
  //iterate and delete
  //lets put on our research hats
}

void BST::printTree()
{
  recPrint(root);
}

void BST::recPrint(TreeNode *node)
{
  if(node==NULL)
    return;
  else
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
}

bool BST::isEmpty()
{
  return (root == NULL);
}

void BST::insert(int value)
{
  // check if value exists, use contains(), if DNE then continue
  TreeNode *node = new TreeNode(value);   //key is now set to  value
  if(isEmpty())   //empty tree
  {
    root = node;
  }
  else    //not an empty tree, need to find insertion point
  {
    TreeNode *current = root;
    TreeNode *parent;   //empty node

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

bool BST::contains(int value)
{
  if(isEmpty())
    return false;
  else  //not empty tree
  {
    TreeNode *current = root;

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
