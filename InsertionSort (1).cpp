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
	string fileName1 = "test1.txt";
	string fileName2 = "test2.txt";
	string fileName3 = "test3.txt";
	string fileName4 = "test4.txt";
	string fileName5 = "test5.txt";
	try{
		for (int x = 0; x < 6; x++){
			ArrayList<int> A(1000); //Maximum array size is 1000
			string printed;
			switch (x){
				case 0: readFromFile(A, fileName);
					printed = fileName;
					break;
				case 1: readFromFile(A, fileName1);
					printed = fileName1;
					break;
				case 2: readFromFile(A, fileName2);
					printed = fileName2;
					break;
				case 3: readFromFile(A, fileName3);
					printed = fileName3;
					break;
				case 4: readFromFile(A, fileName4);
					printed = fileName4;
					break;
				case 5: readFromFile(A, fileName5);
					printed = fileName5;
					break;
			}
			cout << printed << ":" << endl;
			cout << "UNSORTED: " << endl;
			A.print(); // Prints the array with random numbers
			A.insertionSort();
			cout << "\nSORTED: " << endl;
			A.print();
			cout << "" << endl;
		}
	}
	catch (const char* e) {
		cout << e;
	}
}
