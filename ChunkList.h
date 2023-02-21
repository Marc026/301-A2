//
// Created by Varick Erickson 2/3/2021.
//

#ifndef CHUNKLIST_H
#define CHUNKLIST_H

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;

// These error classes are done. No modifications are required.
// See ChunkList_driver.cpp for an example of how they are used.
class InvalidArrayLength{
public:
    string Msg() {
        return "Invalid array length used for constructor.";
    }
};

class IndexOutOfBounds {
public:
    string Msg() {
        return "Index is out of bounds";
    }
};

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

class EmptyList {
public:
    string Msg() {
        return "List is empty";
    }
};

// Put your pre/post conditions here.

template<class T>
class ChunkList {
public:
    // Constructors
    //Function:
    // Default Constructor sets the default values to 0
    //Precondition:
    // None
    //Postcondition:
    //sets the iterNode, arrPos, head and tail to nullptr, listlen and numchunks to 0
    ChunkList();

    //Function:
    // Makes a empty chunklist and appends values from arr
    //Precondition:
    // Append must add the values and default constructor must have been initialized to make an empty chunklist
    //Postcondition:
    //chunklist is made and values from arr is properly inserted
    ChunkList(T arr[], int arrLen);

    // Deconstructor
    //Function:
    // deletes the entire chunklist at the end of each functions and unit test
    //Precondition:
    // a chunklist of some kind must exist for the destructor to be called after each test and function
    //Postcondition:
    //deletes the chunklist and only thing left is nullptr
    ~ChunkList();

    // Add/remove elements
    //Function:
    // adds a value at the end of the chunklist
    //Precondition:
    //tail is set to nullptr and that a new node must be declared and initialized
    //Postcondition:
    //value is added to the end of the list or otherwise a new node is made to add the value after max
    // array size is passed
    void Append(T value);

    //Function:
    // finds and removes a value then adjusts the array accordingly
    //Precondition:
    // Contains is implemented and checks to see if the value is in the list
    //Postcondition:
    //value is removed and the array's length and list len is decremented to reflect the value removal
    void Remove(T value);

    // Stuff to find out about the ChunkList
    //Function:
    // gets length
    //Precondition:
    // listlen is initialized to 0
    //Postcondition:
    //listlen is reassigned anumber based on the arrays length for the tests
    int GetLength();

    //Function:
    // calculates what percent of the chunklist is being used or how much space is being used
    //Precondition:
    // numChunks, listLen and arraysize has been initialized and assigned a value
    //Postcondition:
    //outputs a percentage of values compared to listLen is being used
    double LoadFactor();

    //Function:
    // checks each node if it contains a value
    //Precondition:
    //none
    //Postcondition:
    //returns true if the value is contained in the chunklist otherwise return false
    bool Contains(T value);

    // Accessing elements
    //Function:
    //returns the value at index i with reference to the entire list
    //Precondition:
    //iterNode is set to a value if known where i would be located
    //Postcondition:
    //returns the value at a certain position then places the next value in the next position
    T GetIndex(int i);

    //Function:
    //resets iterator back to head
    //Precondition:
    //arrpos is set to 0 and iternode to head
    //Postcondition:
    //sends the check back to the start of the chunklist
    void ResetIterator();

    //Function:
    //returns the current item and moves to next item in the list.
    //Precondition:
    //none
    //Postcondition:
    //returns value and moves to next value
    T GetNextItem();

    //Function:
    //returns that list is empty
    //Precondition:
    //len and tail is set to 0 and nullptr
    //Postcondition:
    //returns empty list
    bool IsEmpty();

private:

    // Note we did not need to make this a template
    // since this struct is part of a template class.
    struct Node {
        Node* next;
        int len;
        T values[ARRAY_SIZE];
    };

    Node* head;
    Node* tail;

    // iterator
    Node* iterNode;     // What node are were currently on?
    int arrPos;         // Within the node, what element are we looking at?

    int listLen;        // Total elements
    int numChunks;      // Total chunks/nodes
};

#include "ChunkList.cpp"

#endif //CHUNKLIST_H
