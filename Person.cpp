#include <string>
#include "Person.h"

Person::Person() {
    this->name = "no name";
}

Person::Person(std::string name) {
    this->name = name;
}
