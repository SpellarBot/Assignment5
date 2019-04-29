#include "string"
#ifndef PERSON_H
#define PERSON_H

class Person{

public:
  Person();
  Person(int id, string name, string level);

private:
  int id;
  string name;
  string level;
};
#endif
