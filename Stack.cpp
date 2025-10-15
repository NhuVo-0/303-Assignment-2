
#include "Stack.h"


using namespace std;



bool vectorStack::empty() const { //check if stack is empty by using vector function
    return data.empty();
}

size_t vectorStack::size() const { //same thing
    return data.size();
}

void vectorStack::push(int val) { //implementing push with push_back function from vector
    data.push_back(val);
}

void vectorStack::pop() { //implementing pop with pop_back from vector
    if (empty()) {
        throw runtime_error("\nStack is empty!");
    }
    data.pop_back();
}

int vectorStack::top() { //same thing using vector's back
    if ( empty()) {
        throw runtime_error("\nStack is empty!");
    }
    return data.back();
}

double vectorStack::avg() const { //take all of the value in the stack and calculating the avg
    if ( empty()) {
        throw runtime_error("\nStack is empty!");
    }

    double total = 0.0;
        for ( int val : data) { //auto iterator for easy for loop
            total += val;
        }
        return total / data.size();
            
}

void vectorStack::print() const { //print the data in reverse to be correct with stack order ->LIFO
    cout << "\nStack from top to bottom : ";
    for ( auto iter = data.rbegin(); iter != data.rend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

