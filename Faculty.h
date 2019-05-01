#include <string>
#include "DoublyLinkedList.h"
#include "Person.h"
#ifndef FACULTY_H
#define FACULTY_H

using namespace std;

class Faculty : public Person{
public:
  Faculty();
  Faculty(int id, string name, string level, string department);
  ~Faculty();

  //some operator overload
  bool friend operator==(const Faculty &f1, const Faculty &f2);
  bool friend operator!= (const Faculty &f1, const Faculty &f2);


private:
  string department;
  DubLinkList<int>* adviseeIDList = new DubLinkList<int>();
};
#endif
