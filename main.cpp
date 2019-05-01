//just using this to include all the files and to
//see if everything compiles well
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include "RunProgram.h"
int main(){
  int choice1;

  RunProgram rp;
  while(true){      // loops back to MENU after completing action until user enters 14 for exit
    rp.printMenu();
    cin >> choice1;
    if (choice1==14)
      return false;
    rp.menuSelection(choice1);
  }

  return 0;
}
