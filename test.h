#include "Person.h"

bool concat();
bool every();
bool filter();
bool find();

bool nameLenGtFive(Person person) {
    return person.name.length() > 5;
}

bool nameIsHarry(Person person) {
    return person.name == "Harry";
}

bool nameIsNotHarry(Person person) {
    return person.name != "Harry";
}
