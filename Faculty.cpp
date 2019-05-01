#include "Faculty.h"

Faculty::Faculty(){
  typedef Person super;
  department = "";
}

Faculty::Faculty(int id, string name, string level, string department){
  typedef Person super;
  this->department = department;
}

Faculty::~Faculty(){
  delete adviseeIDList;
}

bool operator== (const Faculty &f1, const Faculty &f2)
{
    return (f1.department == f2.department);
}

bool operator!= (const Faculty &f1, const Faculty &f2)
{
    return !(f1 == f2);
}
