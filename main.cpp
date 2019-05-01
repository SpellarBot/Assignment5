#include "DoublyLinkedList.h"
#include "RunProgram.h"

int main(){
  int choice1;

  BST<Student> masterStudent;
  RunProgram rp;
  rp.createTrees();

  while(true){      // loops back to MENU after completing action until user enters 14 for exit
    rp.printMenu();
    cin >> choice1;
    if (choice1==14)
      return false;
    rp.menuSelection(choice1);
  }

  return 0;
}
