#include <string>
#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person{

public:
  Person();
  Person(int id, string name, string level);
  int id;
  string name;
  string level;
};
#endif
