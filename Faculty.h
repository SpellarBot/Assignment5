#include <string>
#include "DoublyLinkedList.h"
#include "Person.h"
#ifndef FACULTY_H
#define FACULTY_H

using namespace std;

class Faculty : public Person{
public:
  Faculty();
  Faculty(int id, string name, string level, string department, int studList[30]);
  ~Faculty();

  int getID();
  void setID(int id);
  string printInfo();
  int listOfAdvisees();
  string stringAd();
  void addAdvisee(int id);
  void deleteAdvisee(int id);

  //some operator overload
  bool friend operator==(const Faculty &f1, const Faculty &f2);
  bool friend operator!= (const Faculty &f1, const Faculty &f2);
  bool friend operator> (const Faculty &f1, const Faculty &f2);
  bool friend operator>= (const Faculty &f1, const Faculty &f2);
  bool friend operator< (const Faculty &f1, const Faculty &f2);
  bool friend operator<= (const Faculty &f1, const Faculty &f2);

  string department;
  int studList[30];

private:
  DubLinkList<int>* adviseeIDList = new DubLinkList<int>();
};
#endif
