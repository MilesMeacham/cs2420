// Author: Miles Meacham
// Date: 03/28/2016
// Contents: Hashing

#include "Hash.h"



Hash::Hash()
{
	// Initialize all elements to -999
	for (int i = 0; i <= MAX - 1; i++)
	{
		hashTable[i] = -999;
	}
}


int Hash::getHashValue(int value)
{
	// Formula to get the hash value
	int hashValue = value % MAX;

	return hashValue;
}

bool Hash::insert(int value, int location) 
{
	// Insert the value at the location passed
	if (hashTable[location] < 0)
	{
		hashTable[location] = value;
		return true;					// Return true if it succeeded
	}
	else
	{
		cout << "Collision detected at location " << location << ", for value " << value << endl;
		return false;					// Return false if it failed
	}
}

bool Hash::resolveCollision(int value, int originalLoc)
{
	// Varialbes
	bool resolved = false;
	int i = 0;
	int newLoc;

	// Try inserting the value in a new location each time using linear probing
	while (resolved == false && i <= (MAX - 1))
	{
		i++;

		newLoc = (originalLoc + i) % MAX;

		// Call insert function and pass the new location
		if (hashTable[newLoc] < 0)
		{
			hashTable[newLoc] = value;
			resolved = true;			

			cout << "Inserted data " << value << " in position " << newLoc << endl << endl;
		}
	}
	
	// Check to see if it succeeded or failed. If it failed table is full.
	if (resolved == false)
		cout << "Table is full. Could not enter " << value << endl << endl;

	return resolved;

}

void Hash::show() 
{
	// Print the header
	cout << endl << "Hash Table Contents" << endl;
	cout << setw(10) << "Element" << setw(10) << "Value" << endl;

	// Output each position and the value stored there
	for (int i = 0; i <= MAX - 1; i++)
	{
		cout << setw(10) << i << setw(10) << hashTable[i] << endl;

	}

}

void Hash::search(int value)
{
	// Get the hashValue of the value that the user wants to find
	int hashVal = getHashValue(value);

	// Check to see if the desired data is in the location of the hashVal
	if (hashTable[hashVal] == value)
		cout << "Found data " << value << " in position " << hashVal << endl;
	else
	{
		// Variables
		bool resolved = false;
		int i = 0;
		int hashLocation = hashVal;

		// Look for the data in the array using linear probing
		while (resolved == false && i <= (MAX - 1))
		{
			i++;

			hashVal = (hashLocation + i) % MAX;

			// If data is found, let the user know it was found and set resolved to true
			if (hashTable[hashVal] == value)
			{
				cout << endl << "Found data " << value << " in position " << hashVal << endl;
				resolved = true;
			}
		}

		// If the data was never found, let the user know.
		if (resolved == false)
			cout << endl << "Data " << value << " was not found in the list." << endl;

	}

}
