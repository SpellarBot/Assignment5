#include "Student.h"
#include<iostream>

using namespace std;

Student::Student(){
  typedef Person super;
  major = "";
  gpa = -1;
  advisorID = -1;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor){
  typedef Person super;
  this->id = id;
  this->name = name;
  this->level = level;
  this->major = major;
  this->gpa = gpa;
  this->advisorID = advisorID;
}

void Student::changeAdvisor(int advisorID){
  this->advisorID = advisorID;
}

int Student::getID(){
  return id;
}

void Student::setID(int id){
  this->id = id;
}

bool operator!= (const Student &s1, const Student &s2)
{
    return (s1.id != s2.id);
}

bool operator== (const Student &s1, const Student &s2)
{
    return (s1.id == s2.id);
}

bool operator> (const Student &s1, const Student &s2)
{
    return s1.id > s2.id;
}

bool operator>= (const Student &s1, const Student &s2)
{
    return s1.id >= s2.id;
}

bool operator< (const Student &s1, const Student &s2)
{
    return s1.id < s2.id;
}

bool operator<= (const Student &s1, const Student &s2)
{
    return s1.id <= s2.id;
}
