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
  return "| ID: " + to_string(id) + " | Name: " + name + " | Level: " + level + " | Department: " + department + " | Advisees:" + stringAd() + " |" ;
}

int Faculty::listOfAdvisees(){
  for (int i : studList)
    return studList[i];
}

string Faculty::stringAd(){
  string s = "";
  for (int i  : studList)
    s+= to_string(studList[i]) + ", ";
  return s;
}

void Faculty::addAdvisee(int id){
  bool x = true;
  while(x == true){
    for (int i : studList){
      if(studList[i]==0){
        studList[i] = id;
        break;
      }
    }
    if(x==true){
      cout << "Faculty Member is at capacity for Advisees." << endl;
      break;
    }
  }
  studList[id] = id;
}

void Faculty::deleteAdvisee(int id){
  studList[id] = 0;
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
