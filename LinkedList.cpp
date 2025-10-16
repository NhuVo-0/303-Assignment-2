#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
    : headPtr(nullptr), tailPtr(nullptr), counter(0) {}  // constructor

template <typename T>
LinkedList<T>::~LinkedList() {  // linked list destructor
    Node* temp = headPtr;
    Node* hold;  // holder for head pointer

    while (temp != nullptr) {  // checking if headptr is null
        hold = temp->nextPtr;
        delete temp;
        temp = hold;
    }

    headPtr = nullptr;
    tailPtr = nullptr;
}

template <typename T>
void LinkedList<T>::push_front(
    const T& d) {  // push front function for linked list
    Node* newNode = new Node(d, headPtr);
    headPtr = newNode;
    if (tailPtr == nullptr) {
        tailPtr = newNode;
    }
    counter++;
}

template <typename T>
void LinkedList<T>::push_back(const T& d) {  // push back function
    Node* newNode = new Node(d, nullptr);
    if (tailPtr == nullptr) {
        headPtr = tailPtr = newNode;
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
    headPtr = headPtr->nextPtr;
    delete tempP;
    if (headPtr == nullptr) {
        tailPtr = nullptr;
    }
    counter--;
}

template <typename T>
void LinkedList<T>::pop_back() {  // pop back to remove from the back element
                                  // only
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
    counter--;
}

template <typename T>
size_t LinkedList<T>::find(
    const T& d) const {  // find function to find a specific element
    Node* curr = headPtr;
    size_t flag = 0;
    while (curr != nullptr) {
        if (curr->data == d) {
            return flag;
        }
        curr = curr->nextPtr;
        flag++;
    }
    return counter;
}

template <typename T>
void LinkedList<T>::insert(
    size_t index,
    const T& d) {  // insert function to insert element at a specific index
    if (index == 0) {
        push_front(d);
        return;
    } else if (index >= counter) {
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

template <typename T>
bool LinkedList<T>::remove(size_t index) {  // boolean value to verify whether
                                            // the element was removed or not
    if (index >= counter) {
        return false;
    }
    if (index == 0) {
        pop_front();
        return true;
    }

    Node* previous = headPtr;
    for (size_t i = 0; i < index - 1; i++) {
        previous = previous->nextPtr;
    }

    Node* targ = previous->nextPtr;
    previous->nextPtr = targ->nextPtr;
    if (targ == tailPtr) {
        tailPtr = previous;
    }
    delete targ;
    counter--;
    return true;
}

template <typename T>
T& LinkedList<T>::front() {  // function to return the front element
    if (headPtr == nullptr) {
        throw runtime_error("List is empty!");
    }
    return headPtr->data;
}

template <typename T>
T& LinkedList<T>::back() {  // function to return the last element
    if (tailPtr == nullptr) {
        throw runtime_error("List is empty!");
    }
    return tailPtr->data;
}

template <typename T>
void LinkedList<T>::printList() const {  // function to print the whole linked
                                         // list to keep track of operation
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

template class LinkedList<int>;
template class LinkedList<string>;