// Author: Miles Meacham
// Date: 03/28/2016
// Contents: Hashing

#include "Hash.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	Hash myHashTable;
	int hashValue;
	bool succeeded;
	string fileAddress;
	int data;

	// Printing my name and the class
	cout << "Miles Meacham" << endl;
	cout << "CS 2420" << endl;
	cout << "Program 5 - Hashing" << endl << endl;

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

	// For each peice of data in the file
	while (!myFile.eof())
	{
		// Call the getHashValue function and store the return in a variable
		hashValue = myHashTable.getHashValue(data);

		// Call the insert funciton and store whether it failed or not in a variable
		succeeded = myHashTable.insert(data, hashValue);

		// If it failed call the resolveCollision function
		if (!succeeded)
			myHashTable.resolveCollision(data, hashValue);

		myFile >> data; // grab the next piece of data
	}

	myFile.close();  // Close the file

	// Print the data
	myHashTable.show();

	system("PAUSE");


	// EXTRA CREDIT - I will search the list for whatever the user wants
	cout << endl << "EXTRA CREDIT - SEARCHING" << endl << endl;

	// Variables
	bool searching = true;
	int dataToFind;
	char continueSearch;

	// Do While loop to let the user search as much as he wants
	do 
	{
		// Ask for data to search for
		cout << "What data would you like to find in the list?" << endl;
		cin >> dataToFind;

		// Make sure they only insert an interger
		if (cin.fail())
		{
			cout << "Please only insert an interger." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			// Call the search function and pass the data to be searched
			myHashTable.search(dataToFind);

			// See if the user wants to search again
			cout << endl << "Would you like to search again? (y/n)" << endl;
			
			// Do while loop to make sure we know what the user wants to do
			do
			{
				cout << "Please insert 'y' or 'n' " << endl;
				cin >> continueSearch;

				if (cin.fail())
				{
					cin.clear();
				}
				else
				{
					if (continueSearch == 'y')
						searching = true;
					else if (continueSearch == 'n')
						searching = false;
				}

			} while (continueSearch != 'y' && continueSearch != 'n');
		}
		

	} while (searching == true);


	cout << endl << "Thank you for using my program!" << endl;
	system("PAUSE");


	return 0;
}