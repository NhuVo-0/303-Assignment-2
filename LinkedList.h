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

	LinkedList() : headPtr(nullptr), tailPtr(nullptr), counter(0) {} //linked list initialization  template class implementation have to be in the same file for visibility

    ~LinkedList() { //linked list destructor
        Node* temp = headPtr;
        Node* hold; //holder for head pointer
        
        while (temp != nullptr) { //checking if headptr is null
            hold = temp->nextPtr;
            delete temp;
            temp = hold;
        }
        
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    
    void push_front(const T& d) { //push front function for linked list
        Node* newNode = new Node(d, headPtr);
        headPtr = newNode;
        if (tailPtr == nullptr) {
            tailPtr = newNode;
        }
        counter++;
    }
    
    void push_back(const T& d) { //push back function
        Node* newNode = new Node(d, nullptr);
        if (tailPtr == nullptr) {
            headPtr = tailPtr = newNode;
        }
        else {
            tailPtr->nextPtr = newNode;
            tailPtr = newNode;
        }
        counter++;
    }
    
    size_t sizeOfList() const{ //returning the counter as the size 
        return counter;
    }

    
    bool isEmpty() const{ //check if linked list is empty
        return headPtr == nullptr;
    }

    
    void pop_front() { //pop front to remove the front element only
        if ( headPtr == nullptr) {
            return;
        }
        Node* tempP = headPtr;
        headPtr = headPtr->nextPtr;
        delete tempP;
        if (headPtr == nullptr) {
            tailPtr = nullptr;
        }
        counter--;
    }

    
    void pop_back() { //pop back to remove from the back element only
        if (headPtr == nullptr) {
            return;
        }
        if (headPtr == tailPtr) {
            delete headPtr;
            headPtr = tailPtr = nullptr;
        }
        else {
            Node* tempP = headPtr;

            while (tempP->nextPtr != tailPtr){
                tempP = tempP->nextPtr;
            }
            delete tailPtr;
            tailPtr = tempP;
            tailPtr->nextPtr = nullptr;
        }
        counter--;
    }

    
    size_t find(const T& d) const { //find function to find a specific element
        Node* curr = headPtr;
        size_t flag = 0;
        while (curr != nullptr) {
            if ( curr->data == d) {
                return flag;
            }
            curr = curr->nextPtr;
            flag++;
        }
        return counter;
    }

    
    void insert(size_t index, const T& d) { //insert function to insert element at a specific index
        if ( index == 0){
            push_front(d);
            return;
        }
        else if (index >= counter) {
            push_back(d);
            return;
        }

        Node* previous = headPtr;
        for (size_t i = 0; i < index - 1; i++) {
            previous = previous->nextPtr;
        }

        Node* newN = new Node(d, previous->nextPtr);
        previous->nextPtr = newN;
        counter++;
    }


    bool remove(size_t index) { //boolean value to verify whether the element was removed or not
        if (index >= counter) {
            return false;
        }
        if ( index == 0){
            pop_front();
            return true;
        }
        

        Node* previous = headPtr;
        for (size_t i = 0; i < index - 1; i++) {
            previous = previous->nextPtr;
        }

        Node* targ = previous->nextPtr;
        previous->nextPtr = targ->nextPtr;
        if ( targ == tailPtr) {
            tailPtr = previous;
        }
        delete targ;
        counter--;
        return true;
    }

    
    T& front() { //function to return the front element 
        if ( headPtr == nullptr) {
            throw runtime_error("List is empty!");
        }
        return headPtr->data;
    }


    T& back(){ //function to return the last element
        if (tailPtr == nullptr) {
            throw runtime_error("List is empty!");
        }
        return tailPtr->data;
    }


    void printList() const{ //function to print the whole linked list to keep track of operation
        Node* current = headPtr;

        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->nextPtr;
        }
        cout << endl;
    }


};

#endif
