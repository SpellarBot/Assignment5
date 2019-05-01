#include "Student.h"
#include "RunProgram.h"
#include "Faculty.h"
#include <iostream>

int studID = 2;
int facID = 1;
int searchID;
BST<Student> masterStudent;
BST<Faculty> masterFaculty;
//Student s1(01, "Jon Flees", "Sophomore", "Data Analytics", 3.15, 03);
//Student s2(02, "Cadre Carrigan", "Sophomore", "Data Analytics", 3.57, 04);
Faculty f1(01, "Rene German", "Lecturer", "Computer Science");



void RunProgram::createTrees(){
  //BST<Student> masterStudent;
  Student s1(01, "Jon Flees", "Sophomore", "Data Analytics", 3.15, 03);
  Student s2(02, "Cadre Carrigan", "Sophomore", "Data Analytics", 3.57, 04);
  masterStudent.insert(s1);
  masterStudent.insert(s2);
  masterFaculty.insert(f1);
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
  Student newStudent;
  Faculty newFac;
  switch(menuSel){
    case 1: //print all students
      printAllStudents();
      break;
    case 2: //print all faculty
      printAllFaculty();
      break;
    case 3: //print a student's info
      cout << "Enter the Student ID: " << endl;
      cin >> searchID;
      masterStudent.contains(searchID);
      break;
    case 4: //print a faculty's info
      cout << "Enter the Faculty ID: " << endl;
      cin >> searchID;
      masterFaculty.contains(searchID);
      break;
    case 5: //print a faculty's info from student id
      cout << "Enter the Student ID: " << endl;
      break;
    case 6: //print all advisee's info for a faculty
      cout << "Enter the Faculty ID: " << endl;
      break;
    case 7: //add student
      studID++;
      newStudent.setID(studID);
      cout << "Enter Student Name: " << endl;
      cin.ignore();
      getline(cin,newStudent.name);
      cout << "Enter Student Level: " << endl;
      cin >> newStudent.level;
      cout << "Enter Student Major: " << endl;
      cin.ignore();
      getline(cin,newStudent.major);
      cout << "Enter Student GPA: " << endl;
      cin >> newStudent.gpa;
      masterStudent.insert(newStudent);
      break;
    case 8: //delete student
      cout << "Enter the Student ID: " << endl;
      break;
    case 9: //add faculty
      facID++;
      newFac.setID(facID);
      cout << "Enter Faculty Name: " << endl;
      cin.ignore();
      getline(cin,newFac.name);
      cout << "Enter Faculty Level: " << endl;
      cin.ignore();
      getline(cin,newFac.level);
      cout << "Enter Faculty Department: " << endl;
      cin.ignore();
      getline(cin,newFac.department);
      masterFaculty.insert(newFac);
      break;
    case 10: //delete faculty
      cout << "Enter the Faculty ID: " << endl;
      break;
    case 11: //change student's advisor
      cout << "Enter the Student ID: " << endl;
      cout << "Enter the new Faculty ID: " << endl;
      break;
    case 12: //remove student from faculty's advisee  list
      cout << "Enter the Student ID: " << endl;
      cout << "Enter the new Faculty ID: " << endl;
      break;
    case 13: //Rollback
      break;
  }
}

void RunProgram::printAllStudents(){
  if(masterStudent.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    masterStudent.printTree();
  }
}

void RunProgram::printAllFaculty(){
  if(masterFaculty.isEmpty())
    cout << "No Faculty exist at this time." << endl;
  else{
    masterFaculty.printTree();
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
  data = k.getID();
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
  if (node==NULL)
    return;
  else{
    recPrint(node->left);
    cout << node->key.printInfo() << endl;
    recPrint(node->right);
  }
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

      if (node->data < current->data)
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
bool BST<T>::contains(int value)
{
  if(isEmpty())
    return false;
  else  //not empty tree
  {
    TreeNode<T> *current = root;

    while(current->data != value)
    {
      if(value < current->data)  //going left
        current = current->left;
      else
        current = current->right;
      if(current == NULL)   //we did not find it, DNE
        return false;
    }
    cout << current->key.printInfo() << endl;
  }
  return true;
}
