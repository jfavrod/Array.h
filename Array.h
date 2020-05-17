#ifndef ARRAY_H
#define ARRAY_H
#include <iterator>
#include <vector>

template<class T> class Array {
    protected:
    /** The "current" element. **/
    int current;
    std::vector<T> data;

    public:
    Array<T>();
    Array<T>(std::vector<T>);

    T &operator [] (int);
    T &operator ++ ();
    T &operator * ();
    bool operator != (Array<T> &);

    T *begin();

    /**
     * Merge two or more arrays. The method does not change the existing
     * arrays, but instead returns a new array.
     */
    Array<T> concat(Array<T> &);

    T *end();

    /**
     * Tests whether all elements in the array pass the test
     * implemented by the provided function.
     */
    bool every(bool (*func)(T));

    /**
     * Creates a new array with all elements that pass the test
     * implemented by the provided function.
     */
    Array<T> filter(bool (*func)(T));

    /**
     * Returns the value of the first element in the provided array
     * that satisfies the provided testing function.
     */
    T find(bool (*func)(T));

    /**
     * Returns the index of the first element in the array that
     * satisfies the provided testing function. Otherwise, it returns
     * -1, indicating that no element passed the test.
     */
    int findIndex(bool (*func)(T));

    int length();

    /**
     * Removes the last element from an array and returns that element.
     * Changes the length of the array.
     */
    T pop();

    /**
     * Adds one or more elements to the end of an array and returns the
     * new length of the array.
     */
    int push(T obj);
};

template<class T>
Array<T>::Array() {
    this->data = std::vector<T>();
    this->current = -1;
}

template<class T>
Array<T>::Array(std::vector<T> base) {
    this->data = base;
    this->current = 0;
}

template<class T>
T &Array<T>::operator[](int index) {
    if (index >= this->length()) {
        throw std::out_of_range("Index out of bounds.");
    }
    return this->data.at(index);
}

template<class T>
T &Array<T>::operator++() {
    if ((this->current + 1) < this->data.size()) {
        ++(this->current);
    }
    else if (this->data.size()) {
        this->current = 0;
    }

    return &(this->data.at(current));
}

template<class T>
T &Array<T>::operator*() {
    return &(this->data.at(this->current));
}

template<class T>
bool Array<T>::operator!=(Array<T> &other) {
    return this->current != other.current;
}

template<class T>
T *Array<T>::begin() {
    return &(this->data.at(0));
}

template<class T>
Array<T> Array<T>::concat(Array<T> &arr) {
    Array<T> newArr = Array<T>(this->data);

    for (int i = 0; i < arr.length(); i++) {
        newArr.push(arr[i]);
    }

    return newArr;
}

template<class T>
T *Array<T>::end() {
    return &(this->data.at(this->length() - 1));
}

template<class T>
bool Array<T>::every(bool (*func)(T)) {
    for (T elm : this->data) {
        if (!func(elm)) {
            return false;
        }
    }

    return true;
}

template<class T>
Array<T> Array<T>::filter(bool (*func)(T)) {
    Array<T> newArr = Array<T>();

    for (T elm : this->data) {
        if (func(elm)) {
            newArr.push(elm);
        }
    }

    return newArr;
}

template<class T>
T Array<T>::find(bool (*func)(T)) {
    for (T elm : this->data) {
        if (func(elm)) {
            return elm;
        }
    }

    throw std::out_of_range("Could not find element.");
}

template<class T>
int Array<T>::findIndex(bool (*func)(T)) {
    int index = -1;
    return index;
}

template<class T>
int Array<T>::length() {
    return (int)this->data.size();
}

template<class T>
T Array<T>::pop() {
    T elm;

    if (!this->data.size()) {
        throw std::out_of_range("No elements in Array.");
    }
    else {
        elm = this->data.back();
        this->data.pop_back();
    }

    return elm;
}

template<class T>
int Array<T>::push(T obj) {
    this->data.push_back(obj);
    return this->data.size();
}

#endif
