#include "Student.h"
#include "RunProgram.h"
#include <iostream>

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
