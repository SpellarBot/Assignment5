#include <string>
#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student : public Person{
public:
  Student();
  Student(int id, string name, string level, string major, double gpa, int advisorID);
  int getAdvisorID();
  void setAdvisorID(int advisorID);


  //some overload operator here
  bool friend operator!= (const Student &s1, const Student &s2);
  bool friend operator== (const Student &s1, const Student &s2);
  bool friend operator> (const Student &s1, const Student &s2);
  bool friend operator>= (const Student &s1, const Student &s2);
  bool friend operator< (const Student &s1, const Student &s2);
  bool friend operator<= (const Student &s1, const Student &s2);

  int getID();
  void setID(int id);
  string printInfo();

  string major;
  double gpa;
  int advisorID;
};
#endif
