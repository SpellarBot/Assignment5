#include "Faculty.h"

Faculty::Faculty(){
  super();
  department = "";
}

Faculty::Faculty(int id, string name, string level, string department){
  super(id, name, level);
  this->department = department;
}

Faculty::~Faculty(){
  delete adviseeIDList;
}

bool Faculty::operator== (const Faculty &f1, const Faculty &f2)
{
    return (f1.department == f2.department);
}

bool Faculty::operator!= (const Faculty &f1, const Faculty &f2)
{
    return !(f1 == f2);
}
