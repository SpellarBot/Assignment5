#include "Student.h"
#include<iostream>

using namespace std;

Student::Student(){
  super();
  major = "";
  gpa = -1;
  advisorID = -1;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor){
  super(id, name, level);
  this->major = major;
  this->gpa = gpa;
  this->advisorID = advisorID;
}

void Student::changeAdvisor(int advisorID){
  this->advisorID = advisorID;
}

bool Student::operator== (const Student &s1, const Student &s2)
{
    return (s1.gpa == s2.gpa &&
            s1.major == s2.major && s1.advisorID == s2.advisorID);
}

bool Student::operator> (const Student &s1, const Student &s2)
{
    return s1.gpa > s2.gpa;
}

bool Student::operator>= (const Student &s1, const Student &s2)
{
    return s1.gpa >= s2.gpa;
}

bool Student::operator< (const Student &s1, const Student &s2)
{
    return s1.gpa < s2.gpa;
}

bool Student::operator<= (const Student &s1, const Student &s2)
{
    return s1.gpa <= s2.gpa;
}
