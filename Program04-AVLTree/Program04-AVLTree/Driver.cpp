// Author: Miles Meacham
// Date: 03/20/2016
// Contents: AVL Tree


#include "AVLTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	// Declaring Variables
	AVLTree myTree;
	string fileAddress;
	int data;

	// Printing my name and the class
	cout << "Miles Meacham" << endl;
	cout << "CS 2420" << endl;
	cout << "Program 4 - AVL Tree" << endl << endl;

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

	myFile >> data;

	// Output the header for all the numbers to be added to the tree.
	cout << endl << "Adding all of these numbers to the Tree" << endl;
	cout << "---------------------------------------------" << endl;

	while (!myFile.eof())
	{
		cout << data;	// Output each piece of data

		// Call the insert function and add the new piece of data
		myTree.insert(data);
		cout << " ";

		myFile >> data; // grab the next piece of data
	}

	myFile.close();  // Close the file

	cout << endl;

	// Traverse the tree Inorder using a recursive function
	cout << endl << "Inorder Traversal (Recusive)" << endl;
	cout << "---------------------------------------------" << endl;
	myTree.inorderTraverse(myTree.getRoot());
	cout << endl;

	// Traverse the tree Preorder using a non recusive function
	cout << endl << "Preorder Traversal (Non-Recursivly)" << endl;
	cout << "---------------------------------------------" << endl;
	myTree.preorderTraverseNonRecursive(myTree.getRoot());



	system("PAUSE");
	return 0;

}