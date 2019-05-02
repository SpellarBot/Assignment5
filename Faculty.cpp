#include "Faculty.h"

Faculty::Faculty(){
  typedef Person super;
  department = "";
}

Faculty::Faculty(int id, string name, string level, string department, int studList[30]){
  typedef Person super;
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
  this->studList[30] = studList[30];
}

Faculty::~Faculty(){
  delete adviseeIDList;
}

int Faculty::getID(){
  return id;
}

void Faculty::setID(int id){
  this->id = id;
}

string Faculty::printInfo(){
  return "| ID: " + to_string(id) + " | Name: " + name + " | Level: " + level + " | Department: " + department + " |";
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
