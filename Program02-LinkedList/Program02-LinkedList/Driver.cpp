// Author: Miles Meacham
// Date: 01/27/2016
// Contents: program 2 - linked lists

#include <iostream>
#include "SingleLinkList.h"
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// the print function
// Purpose: Prints out the value of a Node
// Parameter: a Node
// Returns: none
void print(Node* p);

// the print function
// Purpose: Prints out the value of a DoubleNode
// Parameter: a DoubleNode
// Returns: none
void print(DoubleNode* p);

int main()
{
	// Declaring Variabless
	SingleLinkList myList;
	DoubleLinkList myDoubleList;
	string fileAddress;
	int myData;

	// Printing my name and the class
	cout << "Miles Meacham" << endl;
	cout << "CS 2420" << endl;
	cout << "Program 2 - Linked Lists" << endl << endl;


	// Prompt user to choose a file to use
	cout << "Enter the full path of the file you want to read in:" << endl;
	getline(cin, fileAddress);

	// Open the file
	ifstream myFile(fileAddress.c_str());

	// Test to see if the file was able to be opened
	if (!myFile)
	{
		cout << "There was an Error opening this file" << endl;

		system("PAUSE");
		return 1;
	}

	// Read the data from the file and save it into a vector (numbers)
	do
	{
		myFile >> myData;

		if (myFile.good())
		{
			myList.addNode(myData);
		}
		else
		{
			// Skip lines that don't contain just numbers
			myFile.clear();
			myFile.ignore();
		}
	} while (!myFile.eof());


	// Call the traverse function and pass the double link list in
	// THis is the function that adds the data from the single list to the double
	myList.traverse(&myDoubleList);

	// Print out the singlelinklist by passing the print function to the traversePrint
	cout << endl << "Single Linked List Contents" << endl;
	myList.traversePrint(print);

	// Print out the doublelinklist by passing the print function to the traversePrint
	cout << endl << "Double Linked List Contents" << endl;
	myDoubleList.traversePrint(print);

	cout << endl;

	system("PAUSE");
	return 0;
}

void print(Node *p)
{
	cout << p->getValue() << endl;
}

void print(DoubleNode *p)
{
	cout << p->getValue() << endl;
}