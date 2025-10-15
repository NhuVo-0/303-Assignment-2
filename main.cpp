#include "LinkedList.h"
#include "Stack.h"
#include <iostream>

using namespace std;

bool isAlpha(string str1) {
    return (str1.find_first_not_of("abcdefghijq0123456789") == string::npos); //validate the input value
}


int main() {
    LinkedList<int> list; //initializing list with integers
    vectorStack stack; //creating a stack object

    string maininput; //input for menu
    while (true) {
        cout << "\n\nMain Menu: \na: Single Linked Class Function \nb: Stack Function \nq: Exit \nEnter an option: "; //main menu
        cin >> maininput;
        cout << endl;
        if (maininput.empty() || !isAlpha(maininput) || (maininput.length() != 1)) { //check if input is correct
            cerr << "\nInvalid option! Try again!";
            continue;
        }

        char mainOpt = tolower(maininput[0]); //using lowercase letter only
        
        if (mainOpt == 'q') {
            cout << "\n\nExiting Program!\n"; //program exit
            break;
        }

        if ( mainOpt == 'a') { //if user choose a for linked list operation
            bool backMain = false;
            while (!backMain) {
                string userinput;
                cout << "\n\nLinked List Class Functions Menu: \n\na: push_front \nb: push_back \nc: pop_front \nd: pop_back \ne: front \nf: back \ng: empty \nh: insert \ni: remove \nj: find \n\nq: Exit\n";
                cout << "Enter an option: ";
                cin >> userinput; //get user input
                cout << endl;
                if (userinput.empty() || !isAlpha(userinput) || (userinput.length() != 1)) { //check user input
                    cerr << "Invalid input. Try again! \n\n";
                    continue;
                }

                char useropt = tolower(userinput[0]); //using lowercase 
                switch(useropt) { //case operation for easy menu handling
                    case 'a': { //call push_front function
                        int userVal;
                        cout << "Enter an integer to push_front: ";
                        cin >> userVal;
                        list.push_front(userVal);
                        list.printList();
                        break;
                    }
                    case 'b': { //call push back function
                        int userIn;
                        cout << "\nEnter an integer to push_back: ";
                        cin >> userIn;
                        
                        list.push_back(userIn);
                        
                        list.printList();
                        break;
                    }
                    case 'c': { //call pop front function
                        cout << "\nRemoved the front of list!\n";
                        list.pop_front();
                        
                        list.printList();
                        break;
                    }
                    case 'd': { //call pop back function
                        cout << "\nRemoved the back of list!\n";
                        list.pop_back();
                        
                        list.printList();
                        break;
                    }
                    case 'e': {
                        try{ //try and catch to validate front values 
                            cout << "\nReturning the front value: " << list.front() << endl;
                        }
                        catch ( const exception& e) {
                            cout << "\nError : " << e.what() << endl;
                        }
                        break;
                    }
                    case 'f': {
                        try { //same thing but with back value
                            cout << "\nReturning the back value: " << list.back() << endl;
                        }
                        catch (const exception& e) {
                            cout << "Error : " << e.what() << endl;
                        }

                        break;
                    }
                    case 'g': { //call empty function and also printing the size of list
                        if (list.isEmpty() == true) {
                            cout << "\nList is empty!";
                        }
                        else {
                            cout << "\nElement in list: " << list.sizeOfList();
                            
                        }
                        break;
                    }
                    case 'h': { //call insertion function 
                        int index, value;
                        cout << "\nEnter an index to insert at: ";
                        cin >> index;
                        cout << "\nEnter a value to insert: ";
                        cin >> value;
                        list.insert(index, value);
                        list.printList();
                        break;
                    }
                    case 'i': { //call remove function
                        int index2;
                        cout << "\nEnter an index to remove at: ";
                        cin >> index2;
                        if (list.remove(index2)) {
                            cout << "\nValue removed successfully!\n";
                        }
                        else {
                            cout << "\nValue was not removed.\n";
                        }
                        list.printList();
                        break;
                    }
                    case 'j': { //call find function
                        int target;
                        cout << "\nEnter a value to search: ";
                        cin >> target;
                        
                        size_t position = list.find(target);
                        if (position < list.sizeOfList()) {
                            cout << "Value found at index: " << position << endl;
                        }
                        else {
                            cout << "Value not found in List. \n";
                        }
                        break;
                    }
                    case 'q': { //exit program 
                        cout << "\n\nExiting Single Linked Class! Thank you!\n";
                        backMain = true;
                        break;
                    }
                    default: { //default case for invalid choice
                        cerr << "\nInvalid choice. Enter a valid option!\n\n";
                        break;
                    }
                }
            }
        }
        
        if (mainOpt == 'b') { //stack functions 
            bool backMain2 = false;
            while (!backMain2) {
                string userinput2;
                cout << "\n\nStack Functions: \na: Create a Stack object. \nb: Empty? \nc: Insert a Value \nd: Remove an Element \ne: Top of Stack \nf: Average value of Stack \nq: Exit\n\n " << endl;
                cout << "Enter an option: ";
                cin >> userinput2;
                cout << endl;
                if (userinput2.empty() || !isAlpha(userinput2) || (userinput2.length() != 1)) { //validate the menu options
                    cerr << "Invalid input. Try again! \n\n";
                    continue;
                }

                char useropt = tolower(userinput2[0]);
                switch(useropt) {
                    case 'a': //stack object was created above 
                        cout << "\nCreated a stack object...sucessfully!";
                        break;
                    case 'b': //call empty function
                        if (stack.empty() == true) { 
                            cout << "\nStack is empty!";
                        }
                        else {
                            cout << "\nStack is not empty! \nStack size: " << stack.size();
                        }
                        break;
                    case 'c': //call push function
                        int value;
                        cout << "\nEnter value to add to stack: ";
                        cin >> value;
                        if ( !isAlpha(to_string(value))) { //also validate values
                            cout << "\nValue is invalid!.";
                            break;
                        }
                        else {
                            stack.push(value);
                            stack.print();
                        }
                        break;
                    case 'd': //call pop function
                        cout << "\nRemoving an element from stack! \nRemoved: " << stack.top();
                        stack.pop();
                        break;
                    case 'e': //call top function
                        cout << "\nReturning the top of stack: " << stack.top();
                        break;
                    case 'f': //call average function
                        cout << "\nReturning the average value of stack: " << stack.avg();
                        break;
                    case 'q': //exit program
                        cout << "Exiting Stack Functions, Thank you!" << endl;
                        backMain2 = true;
                        break;
                    default: //default for invalid cases
                        cerr << "\nInvalid Input! Try again!\n";
                        break;
                }
            }
        }
    }

    return 0;
}


