/*
 * ArrayListT.h
 *
 *  Created on: Sep 4, 2019
 *      Author: Mahima
 */

#ifndef ARRAYLISTT_H_
#define ARRAYLISTT_H_

#include <iostream>
using namespace std;

template <class elemType>
class ArrayList{
public:
	ArrayList(const unsigned int=1);
	bool isEmpty() const; 				//Checks if list is empty
	bool isFull() const; 				// Checks if list is full
	unsigned int listSize() const; 		// Returns the size of the list
	unsigned int maxListSize() const;	// Returns the maximum possible size of the list
	void print() const; 						// Prints the elements of the list on the console
	bool isItemAtEqual(const unsigned int, const elemType &) const;	// Checks if the item at position matches the 2nd parameter
	void insertAt(const unsigned int, const elemType &);		// Inserts 2nd parameter at position
	void insertEnd(const elemType&); 			// Inserts object to end of the list
	void removeAt(const unsigned int); 				// Removes object at position
	elemType retreiveAt(const unsigned int) const; 			// Retrieves object at position
	void replaceAt(const unsigned int, const elemType &); 		// Replaces object at position with 2nd parameter
	void clearList(); 					// Empties the list
	ArrayList &operator=(const ArrayList &); // Assignment operator overload
	void insertionSort(); // Sorts the array in ascending order
	virtual ~ArrayList();

private:
	unsigned int size;
	unsigned int maxSize;
	elemType* myList;
};

template<class elemType>
ArrayList<elemType>::ArrayList(const unsigned int maxSize) {
	this->maxSize = maxSize;
	this->size = 0;
	this->myList = new elemType[maxSize];
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isEmpty() const {
	if(size == 0)
		return true;
	return false;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isFull() const {
	if(size == maxSize)
		return true;
	return false;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::listSize() const {
	return size;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::maxListSize() const {
	return maxSize;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::print() const {
	for(unsigned int i = 0; i < size; i++){
		cout << myList[i] << ", ";
	}
	cout << endl;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isItemAtEqual(const unsigned int position, const elemType &element) const {
	if(position > size){
		throw "Out of bounds.";
	}
	if(element == myList[position-1])
		return true;
	return false;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::insertAt(const unsigned int position, const elemType &element) {
	if (this->isFull()){
		throw "List if full";
	}
	if(position > size+1){
		throw "Inserting out of bounds.";
	}
	for(unsigned int i = size; i > position-1; i--){
		myList[i] = myList[i-1];
	}
	myList[position-1] = element;
	size++;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::insertEnd(const elemType &element) {
	if (this->isFull()){
		throw "List if full";
	}
	myList[size] = element;
	size++;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::removeAt(const unsigned int position) {
	if(position > size){
		throw "Removing out of bounds.";
	}
	for(unsigned int i = position-1; i < size-1; i++){
		myList[i] = myList[i+1];
	}
	size--;
}

//This function is O(1)
template<class elemType>
elemType ArrayList<elemType>::retreiveAt(const unsigned int position) const{
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	return myList[position-1];
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::replaceAt(const unsigned int position, const elemType &element) {
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	myList[position-1] = element;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::clearList() {
	size = 0;
}

//This function is O(n)
template<class elemType>
ArrayList<elemType>& ArrayList<elemType>::operator =(const ArrayList<elemType>& constArrayList) {
	if (constArrayList.maxListSize() > maxSize){
		throw "Array too big to copy";
	}
	for(unsigned int i = 0; i < constArrayList.listSize(); i++){
		myList[i] = constArrayList.retreiveAt(i+1);
	}
	size = constArrayList.listSize();
	return *this;
}

template<class elemType>
void ArrayList<elemType>::insertionSort() {
	    int i; 
    for (int x = 1; x < size; x++){  
        elemType k = myList[x];  
        int j = x - 1;
        while (j >= 0 && myList[j] > k){  
            myList[j + 1] = myList[j];  
            j = j - 1;  
        }  
        myList[j + 1] = k;  
    }   
}

//This function is O(1)
template<class elemType>
inline ArrayList<elemType>::~ArrayList() {
	delete[] myList;
}

#endif /* ARRAYLISTT_H_ */
