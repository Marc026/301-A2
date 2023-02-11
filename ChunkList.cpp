//
// Your code here
//

#include "ChunkList.h"


template<class T>
ChunkList<T>::ChunkList() {
    listLen = 0;
    head = tail = nullptr;
    iterNode;
    arrPos = 0;

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
    double percent = 0;
    if(listLen > 0){
        percent = listLen / numChunks * ARRAY_SIZE;
        return percent;
    }
    else
    return IsEmpty();
}

template<class T>
bool ChunkList<T>::Contains(T value) {

    return false;
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    return nullptr;
}

template<class T>
void ChunkList<T>::ResetIterator() {
    arrPos = 0;
}

template<class T>
T ChunkList<T>::GetNextItem() {
    return nullptr;
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return true;
}
