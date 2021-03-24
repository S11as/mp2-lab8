//
// Created by Kirill on 11/29/2020.
//

#ifndef STACKLISTLIB_TSTACKLIST_H
#define STACKLISTLIB_TSTACKLIST_H

#include "TList.h"

template<class T>
class TStackList {
protected:
    TList<T> list;
public:
    TStackList() = default;

    TStackList(TList<T> &list);

    TStackList(TStackList<T> &stack);

    ~TStackList() = default;

    TStackList<T> &operator=(const TStackList<T> &stack);

    void push(T item);

    T pop();

    bool is_empty();

    bool is_full();

    T get_max();

    T get_least();

    template<class T1>
    friend istream &operator>>(istream &istream, TStackList<T1> &stack);

    template<class T1>
    friend ostream &operator<<(ostream &ostream, const TStackList<T1> &stack);

    static TStackList<T> &load(const char *name);

    void save(const char *name);
};


template<class T>
TStackList<T>::TStackList(TStackList<T> &stack) {
    this->list = stack.list;
}

template<class T>
TStackList<T>::TStackList(TList<T> &list) {
    this->list = list;
}

template<class T>
TStackList<T> &TStackList<T>::operator=(const TStackList<T> &stack) {
    if (this == &stack) {
        return *this;
    }
    this->list = stack.list;
    return *this;
}

template<class T>
void TStackList<T>::push(T item) {
    if (this->list.IsFull()) {
        throw std::overflow_error("Stack is full");
    }
    this->list.InsFirst(item);
}

template<class T>
T TStackList<T>::pop() {
    if (this->list.IsEmpty()) {
        throw std::range_error("Stack is empty");
    }
    T tmp = this->list.GetFirst()->GetData();
    this->list.DelFirst();
    return tmp;
}

template<class T>
bool TStackList<T>::is_empty() {
    return this->list.IsEmpty();
}

template<class T>
bool TStackList<T>::is_full() {
    return this->list.IsFull();
}

template<class T1>
istream &operator>>(istream &istream, TStackList<T1> &stack) {
    return istream >> stack.list;
}

template<class T1>
ostream &operator<<(ostream &ostream, const TStackList<T1> &stack) {
    return ostream << stack.list;
}

template<class T>
T TStackList<T>::get_max() {
    if (this->list.IsEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    T max = this->list.GetFirst()->GetData();
    for (auto elem : this->list) {
        if (elem > max) {
            max = elem;
        }
    }
    return max;
}

template<class T>
T TStackList<T>::get_least() {
    if (this->list.IsEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    T least = this->list.GetFirst()->GetData();
    for (auto elem : this->list) {
        if (elem < least) {
            least = elem;
        }
    }
    return least;
}

template<class T>
TStackList<T> &TStackList<T>::load(const char *name) {
    TList<T> list = TList<T>::load(name);
    TStackList<T>* stack = new TStackList(list);
    return *stack;
}

template<class T>
void TStackList<T>::save(const char *name) {
    this->list.save(name);
}


#endif //STACKLISTLIB_TSTACKLIST_H
