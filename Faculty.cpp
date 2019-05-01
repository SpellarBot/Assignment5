#include "Faculty.h"

Faculty::Faculty(){
  typedef Person super;
  department = "";
}

Faculty::Faculty(int id, string name, string level, string department){
  typedef Person super;
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
}

Faculty::~Faculty(){
  delete adviseeIDList;
}

bool operator== (const Faculty &f1, const Faculty &f2)
{
    return (f1.id == f2.id);
}

bool operator!= (const Faculty &f1, const Faculty &f2)
{
    return !(f1 == f2);
}

bool operator> (const Faculty &f1, const Faculty &f2)
{
    return f1.id > f2.id;
}

bool operator>= (const Faculty &f1, const Faculty &f2)
{
    return f1.id >= f2.id;
}

bool operator< (const Faculty &f1, const Faculty &f2)
{
    return f1.id < f2.id;
}

bool operator<= (const Faculty &f1, const Faculty &f2)
{
    return f1.id <= f2.id;
}
