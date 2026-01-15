// intlist.cpp
// Implements class IntList
// Alex Wray 1/8/26

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : IntList()  {
    Node* adder = source.head;
    while (adder) {
        push_back(adder->info);
        adder = adder->next;
    }

}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* select = head;
    while (select) {
        sum += select->info;
        select = select->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* select = head;
    while (select) {
        if (select->info == value) {return true;}
        select = select->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head) {
        Node* select = head->next;
        int max = head->info;
        while (select) {
            if (select->info > max) {
                max = select->info;
            }
            select = select->next;
        }
        return max;
    }
    else {
        return 0;
    }
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head) {return 0;}
    int sum = 0;
    int size = 0;
    Node* select = head;
    while (select) {
        sum += select->info;
        size++;
        select = select->next;
    }
    return static_cast<double>(sum) / size;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    head = new Node{value, head};
    if (!tail) {tail = head;}
}

// append value at end of list
void IntList::push_back(int value) {
    if (!head) {
        head = new Node{value, nullptr};
        tail = head;
    }
    else {
        tail->next = new Node{value, nullptr};
        tail = tail->next;
    }

}

// return count of values
int IntList::count() const {
    int size = 0;
    Node* select = head;
    while (select) {
        size++;
        select = select->next;
    }
    return size;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    // Clear
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;

    // Copy
    Node* select = source.head;
    while (select) {
        push_back(select->info);
        select = select->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

