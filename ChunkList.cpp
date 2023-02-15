//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    listLen = 0;
    head = tail = NULL;
    iterNode;
    arrPos;

    //for(int i = 0; i < ARRAY_SIZE; i++ ){
    //    values[i] = -1
    //}
}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {

}

template<class T>
ChunkList<T>::~ChunkList() {

}

template<class T>
void ChunkList<T>::Append(T value) {
    if(tail == nullptr){
        Node *insertNode = new Node;
        insertNode->len = 0;
        insertNode->values[insertNode->len] = value;
        head = tail = insertNode;
        numChunks++;
    }
    else if (tail->len < ARRAY_SIZE){
        tail->values[tail->len] = value;
    }
    else {
        Node *insertNode = new Node;
        insertNode->len = 0;
        insertNode->values[insertNode->len] = value;
        tail->next = insertNode;
        tail = insertNode;
        numChunks++;
    }
    tail->len++;
    listLen++;
}

template<class T>
void ChunkList<T>::Remove(T value) {

}

template<class T>
int ChunkList<T>::GetLength() {
    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    double percent = 0.0;
    if(listLen > 0){
        percent = listLen / (numChunks * ARRAY_SIZE);
        return percent;
    }
    else
    return IsEmpty();
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    Node* tempNode = head;
    while (tempNode != nullptr) {
        for (int i = 0; i < tempNode->len; i++) {
            if (tempNode->values[i] == value) {
                return true;
            }
        }
        tempNode = tempNode->next;
    }
    return false;
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    return nullptr;
}

template<class T>
void ChunkList<T>::ResetIterator() {
    arrPos = -1;
}

template<class T>
T ChunkList<T>::GetNextItem() {
    return nullptr;
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return true;
}
