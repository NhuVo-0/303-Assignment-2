#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#ifndef STACK_H
#define STACK_H

using namespace std;

class vectorStack { //class stack that is created with a vector as a container
private:
    vector<int> data; //the container for the stack class
public:
    bool empty() const; //check if stack is empty

    size_t size() const; //keep track of size of stack

    void push(int val); //push a value to the top of the stack

    void pop(); //pop the top value of the stack

    int top(); //return the top value of the stack

    double avg() const; //return the double value of the average in the stack

    void print() const; //print the stack to keep track of operation

};

#endif