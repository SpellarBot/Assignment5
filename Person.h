#include <string>
#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person{

public:
  Person();
  Person(int id, std::string name, std::string level);
  int id;

private:
  
  std::string name;
  std::string level;
};
#endif
