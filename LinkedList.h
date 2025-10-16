#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <istream>
#include <sstream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>


using namespace std;

template<typename T> //template class so you can create any instant of different type inputs
class LinkedList {
private:
    struct Node { //node structure for the linked list
        T data; //template class T data
        Node* nextPtr;
        Node(const T& d, Node* next = nullptr) : data(d), nextPtr(next){} //node constructor
    };
	Node* headPtr; //head pointer
	Node* tailPtr; //tail pointer
    size_t counter; //counter to keep track of the size of the stack or the linked list, this will be inherited by the stack also
public:

	LinkedList();

    ~LinkedList();

    
    void push_front(const T& d);
    
    void push_back(const T& d);
    
    size_t sizeOfList() const;

    
    bool isEmpty() const;

    
    void pop_front();

    
    void pop_back();

    
    size_t find(const T& d) const;

    
    void insert(size_t index, const T& d);


    bool remove(size_t index);

    
    T& front();


    T& back();


    void printList() const;

};

extern template class LinkedList<int>; //got this solution from Cannan !! 
extern template class LinkedList<string>;

#endif
