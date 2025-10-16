#include "LinkedList.h"

template <typename T> //creating template class for every function within the LinkedList Class
LinkedList<T>::LinkedList()
    : headPtr(nullptr), tailPtr(nullptr), counter(0) {}  // constructor

template <typename T>
LinkedList<T>::~LinkedList() {  // linked list destructor
    Node* temp = headPtr;
    Node* hold;  // holder for head pointer

    while (temp != nullptr) {  // checking if headptr is null
        hold = temp->nextPtr;
        delete temp; //deleting the temp value within the Linked List
        temp = hold;
    }

    headPtr = nullptr; //setting the head and tail pointer == nullpointer to indicate Linked List is empty
    tailPtr = nullptr;
}

template <typename T> //template type for function parameter 
void LinkedList<T>::push_front(
    const T& d) {  // push front function for linked list
    Node* newNode = new Node(d, headPtr);
    headPtr = newNode;
    if (tailPtr == nullptr) {
        tailPtr = newNode; //setting tail pointer to newNode to create the new value that was pushed into the Linked List
    }
    counter++; //increasing the counter to keep track of the size of the Linked List
}

template <typename T>
void LinkedList<T>::push_back(const T& d) {  // push back function with a template type parameter
    Node* newNode = new Node(d, nullptr);
    if (tailPtr == nullptr) {
        headPtr = tailPtr = newNode; //push back function worked the same as push front but this is changing the head pointer because a single linked list only go in one direction 
    } else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    counter++;
}

template <typename T>
size_t LinkedList<T>::sizeOfList() const {  // returning the counter as the size
    return counter;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {  // check if linked list is empty
    return headPtr == nullptr;
}

template <typename T>
void LinkedList<T>::pop_front() {  // pop front to remove the front element only
    if (headPtr == nullptr) {
        return;
    }
    Node* tempP = headPtr;
    headPtr = headPtr->nextPtr; //getting head pointer's next value to remove as the next of head pointer would be the front of the list
    delete tempP;
    if (headPtr == nullptr) {
        tailPtr = nullptr;
    }
    counter--; //decrementing the size as you removed one 
}

template <typename T>
void LinkedList<T>::pop_back() {  // pop back to remove from the back element
                                  // work same way as the pop front except this check for tail pointer's next
    if (headPtr == nullptr) {
        return;
    }
    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = tailPtr = nullptr;
    } else {
        Node* tempP = headPtr;

        while (tempP->nextPtr != tailPtr) {
            tempP = tempP->nextPtr;
        }
        delete tailPtr;
        tailPtr = tempP;
        tailPtr->nextPtr = nullptr;
    }
    counter--; //decrementing counter
}

template <typename T>
size_t LinkedList<T>::find(
    const T& d) const {  // find function to find a specific element
    Node* curr = headPtr;
    size_t flag = 0;
    while (curr != nullptr) {
        if (curr->data == d) { //check if the current node's data is equal to the target given
            return flag;
        }
        curr = curr->nextPtr;
        flag++; //increasing the flag to get the actual index of the target value
    }
    return counter; //return size of List if it is not found
}

template <typename T>
void LinkedList<T>::insert(
    size_t index,
    const T& d) {  // insert function to insert element at a specific index
    if (index == 0) {
        push_front(d); //check if the index is == to 0 then push front 
        return;
    } else if (index >= counter) { //if the index is >= counter then push it back into the List
        push_back(d);
        return;
    }

    Node* previous = headPtr;
    for (size_t i = 0; i < index - 1; i++) { //this is a for loop to insert element at specific index between other nodes
        previous = previous->nextPtr;
    }

    Node* newN = new Node(d, previous->nextPtr); //this is also the same thing
    previous->nextPtr = newN;
    counter++;
}

template <typename T>
bool LinkedList<T>::remove(size_t index) {  // boolean value to verify whether
                                            // the element was removed or not
    if (index >= counter) { //check if the remove index is bigger than the size that would be out of bounds
        return false;
    }
    if (index == 0) { //check if we're removing the front element or not
        pop_front();
        return true;
    }

    Node* previous = headPtr;
    for (size_t i = 0; i < index - 1; i++) { //running though the list to see if the target is between other nodes
        previous = previous->nextPtr;
    }

    Node* targ = previous->nextPtr; //checking for if the target is near the tail pointer
    previous->nextPtr = targ->nextPtr;
    if (targ == tailPtr) {
        tailPtr = previous;
    }
    delete targ;
    counter--; //decrementing after removing the target index
    return true; //return true if remove operation is successfull
}

template <typename T>
T& LinkedList<T>::front() {  // function to return the front element
    if (headPtr == nullptr) {
        throw runtime_error("List is empty!"); //if the list is empty it will throw a run time error and program will be stopped
    }
    return headPtr->data;
}

template <typename T>
T& LinkedList<T>::back() {  // function to return the last element
    if (tailPtr == nullptr) {
        throw runtime_error("List is empty!"); //same thing, will stop the program 
    }
    return tailPtr->data;
}

template <typename T>
void LinkedList<T>::printList() const {  // function to print the whole linked
                                         // list to keep track of operation
    Node* current = headPtr;

    if (current == nullptr) { //check if the list is empty or not, could've used the empty function here too
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked List: ";
    while (current != nullptr) { //if list is not empty run a while loop to print the data
        cout << current->data << " ";
        current = current->nextPtr;
    }
    cout << endl;
}

template class LinkedList<int>; //template class instantiation explicitly -> got this solution from Canann for separting template class definition and declaration.
template class LinkedList<string>;
