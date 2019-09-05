//============================================================================
// Name        : InsertionSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "ArrayListT.h"
using namespace std;

void readFromFile(ArrayList<int>& A, string fileName){
	ifstream fin(fileName);
	int number;
	while(fin >> number){
		A.insertEnd(number);
	}
}


int main() {

	string fileName = "example.txt";
	try{
		ArrayList<int> A(1000); //Maximum array size is 1000
		readFromFile(A, fileName); // Populates the array with a random set of numbers
		A.print(); // Prints the array with random numbers

		A.insertionSort();
		A.print();
	}
	catch (const char* e) {
		cout << e;
	}
}
