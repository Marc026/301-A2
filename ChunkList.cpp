//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    listLen = 0;            //declares the toal # of values in the entire chunklist to 0
    numChunks = 0;          //declares the toal # of nodes in the entire chunklist to 0
    arrPos = 0;             //declare the current position being looked at to 0 or the first value in the node
    head = tail = nullptr;  //set both head and tail to nullptr
    iterNode = nullptr;     //set iterNode to nullptr
}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {
    ChunkList();                        //declare chunklist to make an empty one
    for(int i = 0; i < arrLen; i++){    //loop to add a value at the end of the list
        Append(arr[i]);
    }

    if(arrLen < 1){              //if the length of the list is 0 , throw error
        throw InvalidArrayLength();
    }
}

template<class T>
ChunkList<T>::~ChunkList() {     //destructor that is called at the end of each function

}

template<class T>
void ChunkList<T>::Append(T value) {
    if(tail == nullptr){                //if tail is at nullptr
        Node *insertNode = new Node;    //make ned node called insertNode
        insertNode->next = nullptr;     //next to new node, make it nullptr
        insertNode->len = 0;            //set the new node length to 0
        insertNode->values[insertNode->len] = value;    //insert a value into new node
        head = tail = insertNode;                       //set the head and tail to the new node

        numChunks++;                    //book keeping
    }

    else if (tail->len < ARRAY_SIZE){   //otherwise, if len is less than the max amount of values
        tail->values[tail->len] = value;    //throw value in
    }

    else {                              //otherwise
        Node *insertNode = new Node;    //new node called insertNode
        insertNode->next = nullptr;     //next to new node, call it nullptr
        insertNode->len = 0;            //length to 0
        insertNode->values[insertNode->len] = value;    //throw value in
        tail->next = insertNode;        //set the tail of prev node to insertnode
        tail = insertNode;              //set to tail
        numChunks++;
    }

    tail->len++;      //book keeping
    listLen++;        //book keeping
}

template<class T>
void ChunkList<T>::Remove(T value) {
    Node* tempNode = head;            //new node called temp node
    Node* prevNode = nullptr;         //set prev node to nullptr
    bool isFound = false;             //false until we find value needing to be removed
    int savePos;                      //saves position of found value
    while (tempNode != nullptr) {       //while tempnode isnt at nullptr
        for (int i = 0; i < tempNode->len; i++) {   //check the array list
            if (tempNode->values[i] == value) {     //if value is found
                tempNode->len--;      //minus the nodes length
                savePos = i;         //set position of value to i
                isFound = true;     //set isfound to true
                listLen--;   //decrease overall chunklist length
                break;      //break out
            }
        }
        if(isFound){        //if found, break out
            break;
        }
        //next node
        prevNode = tempNode;        //set prev node to the temp node
        tempNode = tempNode->next;  //set the temp node to the next node in chunklist
    }
    if (tempNode == nullptr){       //if the tempnode is nullptr
        throw EmptyList();          //throw error
    }
    else if (tempNode->len == 0) {  //if tempnode length is 0
        if (tempNode == head) {     //and if the tempnode is at head
            head = head->next;      //set head to next
        } else if (tempNode == tail) {              //if tempnode is at tail
            tail = prevNode;        //the tail of the prevnode
            prevNode->next = nullptr;               //to nullptr
        } else {                     //otherwise
            prevNode->next = tempNode->next;        //set the prevnode next to tempnode next
        }
        delete tempNode;    //book keeping
        numChunks--;        //book keeping
    }
    else{       //otherwise
        if(savePos == tempNode->len){               //if savedpos is the same length
            tempNode->values[savePos] = tempNode->values[savePos+1];    //move onto next position
        }
        else{                                       //otherwise
            for(int i = savePos; i < tempNode->len; i++){   //check the position
                tempNode->values[i] = tempNode->values[i+1];    //move onto next position
            }
        }
    }
}


template<class T>
int ChunkList<T>::GetLength() {     //gets the listLen of the entire chunk list
    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    double percent = 0.0;           //declare double of 0
    if(listLen > 0){                //if len is greater than o
        // 8 / (2 * 8) = 8/16 = 0
        // int/int = int
        // 1/2 = 0
        percent = 1.0*(listLen) / (numChunks * ARRAY_SIZE);     //do this formula of list len divided by
                                                                //num of nodes and max values in the node allowed
        return percent; //return
    }
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    Node* tempNode = head;  //set tempnode to head

    while (tempNode != nullptr) {   //while tempnode isnt at head
        for (int i = 0; i < tempNode->len; i++) {   //check the array list for value
            if (tempNode->values[i] == value) {     //if value is found
                return true;    //return true
            }
        }
        tempNode = tempNode->next;  //move to next node in list
    }

    return false;   //otherwise return false(does not contain)
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    Node* tempNode = head;  //tempnode to head

    while(tempNode != nullptr  && i >= 0){      //while tempnode isnt nullptr and greater or equal to 0
        if(i < tempNode->len){      //if i is less than the max value in the list
            return tempNode->values[i];     //return value
        }
        i -= tempNode->len;     //subtract i and equal to the array len
        tempNode = tempNode->next;  //move to next node
    }

    if(i < 0){                      //if i<0 throw error
        throw IndexOutOfBounds();
    }
    if(tempNode == nullptr){        //if tempnode is nullptr throw error
        throw EmptyList();
    }
    if(i > listLen){                //if i>length throw error
        throw IndexOutOfBounds();
    }

}

template<class T>
void ChunkList<T>::ResetIterator() {
    arrPos = 0;             //reset array position being looked at to 0
    if(head != nullptr){    //if head isnt at nullptr
        iterNode = head;    //set the current node being looked at to head
    }
    else{                   //otherwise, throw error
        throw EmptyList();
    }
}

template<class T>
T ChunkList<T>::GetNextItem() {
    if (head == nullptr){   //if head is nullptr, throw error
        throw EmptyList();
    }
    if(arrPos < 0){         //if arrpos is not 0, throw error
        throw IteratorOutOfBounds();
    }
    else if(arrPos < iterNode->len){    //if arrpos is less than the length of array
        return iterNode->values[arrPos++];  //return value then post increment
    }
    else if(arrPos == iterNode->len){   //if arrpos is the last value in array list
        if(iterNode->next != nullptr)   //and if next is not nullptr
        {
            iterNode = iterNode->next;  //move to next node
            arrPos = 0;                 //reset back to position 0
            return iterNode->values[arrPos++];  //return value then post increment
        }
        else{                           //else throw error
            throw IteratorOutOfBounds();
        }
    }
}

template<class T>
bool ChunkList<T>::IsEmpty() {      //returns empty when called
    return true;
}
