#include "string"
#include "DoublyLinkedList.h"
#include "Person.h"
class Faculty : public Person{
public:
  Faculty();
  Faculty(int id, string name, string level, string department);
  ~Faculty();

  //some operator overload
  bool operator==(const Faculty &f1, const Faculty &f2);
  bool operator!= (const Faculty &f1, const Faculty &f2);


private:
  string department;
  DubLinkList<int>* adviseeIDList = new DubLinkList<int>();
};
