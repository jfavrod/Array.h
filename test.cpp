#include <assert.h>
#include <iostream>
#include <string>
#include "Array.h"
#include "Person.h"
#include "test.h"

using namespace std;

int main() {
    Array<Person> arr = Array<Person>();
    arr.push(Person("John"));
    arr.push(Person("John II"));
    arr.push(Person("John III"));

    for (Person person : arr) {
        cout << "the person's name is " << person.name << endl;
    }
    // if (concat()
    //     && every()
    //     && filter()
    //     && find()) {
    //     cout << "All tests passed." << endl;
    //     return 0;
    // }
    // else {
    //     return 1;
    // }
}

bool concat() {
    cout << "Testing Array.concat" << endl;
    Array<Person> *arr = new Array<Person>();
    Array<Person> arr2 = Array<Person>();

    arr->push(Person("John"));
    arr->push(Person("John II"));
    arr->push(Person("John III"));

    arr2.push(Person("Henry"));
    arr2.push(Person("Henry II"));
    arr2.push(Person("Henry III"));

    Array<Person> arr3 = arr->concat(arr2);

    cout << "  It should have a length equivalent to the sum of the two concat'ed arrays... ";

    if (arr3.length() == (arr->length() + arr2.length())) {
        cout << "pass" << endl;
    }
    else {
        cout << "fail" << endl;
    }

    delete arr;
    return true;
}

bool every() {
    cout << "Testing Array.every" << endl;

    Array<Person> arr = Array<Person>();
    arr.push(Person("Henry I"));
    arr.push(Person("Henry II"));

    cout << "  It should return true when all items in array return true... ";
    assert(arr.every(nameLenGtFive));
    cout << "pass" << endl;

    arr.push(Person("Henry"));
    cout << "  It should not return true when all items in array don't return true... ";
    assert(!arr.every(nameLenGtFive));
    cout << "pass" << endl;

    return true;
}

bool filter() {
    cout << "Testing Array.filter" << endl;
    Array<Person> arr = Array<Person>();
    Array<Person> filtered = Array<Person>();

    arr.push(Person("John"));
    arr.push(Person("Henry"));
    arr.push(Person("Harry"));

    cout << "  It should filter all objects except matches... ";
    filtered = arr.filter(nameIsHarry);
    assert(filtered.length() == 1);
    assert(filtered[0].name == "Harry");
    cout << "pass" << endl;

    cout << "  It should filter all objects except inverse matches... ";
    filtered = arr.filter(nameIsNotHarry);
    assert(filtered.length() == 2);
    cout << "pass" << endl;

    return true;
}

bool find() {
    cout << "Testing Array.find" << endl;

    Array<Person> *arr = new Array<Person>();
    arr->push(Person("Tom"));
    arr->push(Person("Dick"));
    arr->push(Person("Harry"));

    cout << "  It should find Person with correct name... ";

    try {
        assert((arr->find(nameIsHarry).name == "Harry"));
        cout << "pass" << endl;
    }
    catch(exception &e) {
        cout << "fail" << endl;
    }

    delete arr;
    return true;
}
