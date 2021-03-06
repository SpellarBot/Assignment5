#include "Student.h"
#include "RunProgram.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>

ofstream file_;
int studID = 2;
int facID = 1;
int searchID, searchID2;
int sID;
int studList[20];
int counter1=0;
BST<Student> masterStudent;
BST<Faculty> masterFaculty;
Faculty f1(01, "Rene German", "Lecturer", "Computer Science", studList);

GenStack<Student> studentStack;
GenStack<Faculty> facultyStack;
GenStack<Student> extraStudentStack;
GenStack<Faculty> extraFacultyStack;



void RunProgram::createTrees(){
  Student s1(01, "Jon Flees", "Sophomore", "Data Analytics", 3.15, 03);
  Student s2(02, "Cadre Carrigan", "Sophomore", "Data Analytics", 3.57, 01);
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
      cin >> searchID;
      searchAdvisorID(searchID);
      break;
    case 6: //print all advisee's info for a faculty
      cout << "Enter the Faculty ID: " << endl;
      cin >> searchID;
      printAdvisees(searchID);
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
      masterStudent.changeAdID(studID, 1);
      break;
    case 8: //delete student
      cout << "Enter Student ID:  " << endl;
      cin  >> searchID;
      masterStudent.deleteThis(searchID);
      break;
    case 9: //add faculty
      facID++;
      newFac.setID(facID);
      cout << "Enter Faculty Name: " << endl;
      cin.ignore();
      getline(cin,newFac.name);
      cout << "Enter Faculty Level: " << endl;
      //cin.ignore();
      getline(cin,newFac.level);
      cout << "Enter Faculty Department: " << endl;
      //cin.ignore();
      getline(cin,newFac.department);
      masterFaculty.insert(newFac);
      break;
    case 10: //delete faculty
      cout << "Enter the Faculty ID: " << endl;
      cin  >> searchID;
      masterFaculty.deleteThis(searchID);
      break;
    case 11: //change student's advisor
      cout << "Enter the Student ID: " << endl;
      cin >> searchID;
      cout << "Enter the new Faculty ID: " << endl;
      cin >> searchID2;
      changeAdvisorID(searchID, searchID2);
      masterFaculty.addToAdvisor(searchID, searchID2);
      break;
    case 12: //remove student from faculty's advisee  list
      cout << "Enter the Student ID: " << endl;
      cin >> searchID;
      cout << "Enter the Faculty ID: " << endl;
      cin >> searchID2;
      masterFaculty.removeFromAdvisor(searchID, searchID2);
      break;
    case 13: //Rollback
      break;
    case 14:
      createStudentTableFile();
      createFacultyTableFile();
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

void RunProgram::createStudentTableFile(){
  if(masterStudent.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    cout << "Writing results to 'studentTable.out'..." << endl;
    file_.open("studentTable.out", std::ios_base::app);
    masterStudent.fileTree();
    file_.close();
  }
}

void RunProgram::createFacultyTableFile(){
  if(masterFaculty.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    cout << "Writing results to 'facultyTable.out'..." << endl;
    file_.open("facultyTable.out", std::ios_base::app);
    masterFaculty.fileTree();
    file_.close();
  }
}

void RunProgram::searchAdvisorID(int id){
  int gg = masterStudent.findAdID(id);
  masterFaculty.contains(gg);
}

void RunProgram::changeAdvisorID(int stud, int fac){
  masterStudent.changeAdID(stud, fac);
  masterStudent.contains(stud);
}

void RunProgram::printAdvisees(int id){
    int cc = masterFaculty.findAdvisees(id);
    for(int i=0; i< 20; i++){
      if (cc!=0)
        masterStudent.contains(i);
    }
}


/*
void RunProgram::saveCommand()
{
  if(studentStack.sizeOf() >= 5)
  {
    for(int i = 0; i < 5; i++)
    {
      extraStudentStack.push(studentStack.pop());
    }
    extraStudentStack.pop();
    while(!extraStudentStack.empty())
    {
      studentStack.push(extraStudentStack.pop());
    }
    //studentStack.push(node : masterStudent);
  }
  else if(facultyStack.sizeOf() >= 5)
  {
    for(int i = 0; i < 5; i++)
    {
      extraFacultyStack.push(facultyStack.pop());
    }
    extraFacultyStack.pop();
    while(!extraFacultyStack.empty())
    {
      facultyStack.push(extraFacultyStack.pop());
    }
    //facultyStack.push(TreeNode<T> *node : masterFaculty);
  }

  else
  {
    //studentStack.push(masterStudent);
    //facultyStack.push(masterFaculty);
  }
}


void RunProgram::Rollback()
{
  try
  {
  //  masterStudent = studentStack.pop();
  //  masterStudent.pop();
  //  masterFaculty = facultyStack.pop();
  }
  catch(exception e)
  {
    cout << "You can only rollback your last 5 commands. Rollback Failed." << endl;
  }
}
*/

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



template <class T>
void BST<T>::fileTree()
{
  recFile(root);
}

template <class T>
void BST<T>::recFile(TreeNode<T> *node)
{
  if (node==NULL)
    return;
  else{
    recFile(node->left);
    file_ << node->key.printInfo() << endl;
    recFile(node->right);
  }
}


template <class T>
void BST<T>::changeAdID(int value, int fac)
{
  if(isEmpty())
    cout << "Tree is empty." << endl;
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
        cout << "Does not exist." << endl;
    }
    current->key.setAdvisorID(fac);
  }
}

template <class T>
void BST<T>::addToAdvisor(int value, int fac)
{
  if(isEmpty())
    cout << "Tree is empty." << endl;
  else  //not empty tree
  {
    TreeNode<T> *current = root;

    while(current->data != fac)
    {
      if(fac < current->data)  //going left
        current = current->left;
      else
        current = current->right;
      if(current == NULL)   //we did not find it, DNE
        cout << "Does not exist." << endl;
    }
    current->key.addAdvisee(value);
  }
}


template <class T>
void BST<T>::removeFromAdvisor(int value, int fac)
{
  if(isEmpty())
    cout << "Tree is empty." << endl;
  else  //not empty tree
  {
    TreeNode<T> *current = root;

    while(current->data != fac)
    {
      if(fac < current->data)  //going left
        current = current->left;
      else
        current = current->right;
      if(current == NULL)   //we did not find it, DNE
        cout << "Does not exist." << endl;
    }
    current->key.deleteAdvisee(value);
  }
}

template <class T>
int BST<T>::findAdID(int value)
{
  if(isEmpty())
    cout << "Tree is empty." << endl;
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
    return current->key.advisorID;
  }
}

template <class T>
int BST<T>::findAdvisees(int value)
{
  if(isEmpty())
    cout << "Tree is empty." << endl;
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
    return current->key.listOfAdvisees();
  }
}


template <class T>
bool BST<T>::deleteThis(int value)
{
  bool check = false;

  if(root == NULL)
  {
    return false;
  }

  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;


  while(current->data != value)
  {
    parent = current;

    if(value < current->data)
    {
      check = true;
      current = current->left;
    }
    else
    {
      check = false;
      current = current->right;
    }

    if(current == NULL)
    {
      return false;
    }
  }


  //delete with no Child

  if(current->left == NULL && current->right == NULL)
  {
    if(current == root)
    {
      root = NULL;
    }
    else if(check)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
  }

  //delete with left Child

  else if(current->right == NULL)
  {
    if(current == root)
    {
      root = current->left;
    }
    else if(check)
    {
      parent->left = current->left;
    }
    else
    {
      parent->right = current->right;
    }
  }

  //delete with right Child

  else if(current->left == NULL)
  {
    if(current == root)
    {
      root = current->right;
    }
    else if(check)
    {
      parent->left = current->right;
    }
    else
    {
      parent->right = current->right;
    }
  }

  //delete with two children

  else
  {
    TreeNode<T> *next = getNext(current);

    if(current == root)
    {
        root = next;
    }
    else if(check)
    {
      parent->left = next;
    }
    else
    {
      parent->right = next;
    }
    next->left = current->left;
  }
//  --size;
  return true;
}

template <class T>
TreeNode<T>* BST<T>::getNext(TreeNode<T> *value)
{
  TreeNode<T> *temp = value;
  TreeNode<T> *next = value;
  TreeNode<T> *current = value->right;

  while(current != NULL)
  {

    temp = next;
    next = current;
    current = current->left;

  }

  if(next != value->right)
  {
    if(next->right > temp->left)
    {
      temp->left = next->right;
      next->right = value->right;
    }
  }
  return next;
}
