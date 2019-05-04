# Assignment5

Jon Flees flees@chapman.edu
Cadre Carrigan ccarriga@chapman.edu

CPSC 350: Data Structures & Algorithms

Files Included:

Person.h      base class for each person (header)
Person.cpp    base class for each person (implementation)
Faculty.h     derived class for each faculty (header)
Faculty.cpp   derived class for each faculty (implementation)
Student.h     derived class for each student (header)
Student.cpp   derived class for each student (implementation)
RunProgram.h  includes RunProgram, TreeNode, & BST Classes (header)
RunProgram.cpp  includes RunProgram, TreeNode, & BST Classes (implementation)
GenStack.h    includes GenStack which was used for storing changes in the stack to be used
DoublyLinkedList.h    includes Doubly Linked List
main.cpp      main


The program provides the user a menu to choose from options to add, delete, view, or change objects in two separate BST's,
one for students and one for faculty. The program loops back to the menu until user chooses to exit then it outputs the
results to a separate files for each BST.

For running and compiling:
g++ Person.cpp Faculty.cpp Student.cpp RunProgram.cpp main.cpp
./a.out
