#include "Person.h"

Person::Person(){
  id = -1;
  name = "";
  level = "";
}

Person::Person(int id, string name, string level){
  this->id = id;
  this->name = name;
  this->level = level;
}
