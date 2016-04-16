// Author: Miles Meacham
// Date: 03/28/2016
// Contents: Hashing

#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Hash
{
private:
	const int MAX = 20;
	int hashTable[20];

public:

	// Default Constructor
	// Purpose: create a default "Hash"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: HashTable created, initialized all elements to -999
	Hash();

	// getHashValue function
	// Purpose: get the hash value
	// Parameter: int
	// Return: int (hash value)
	int getHashValue(int);

	// insert function
	// Purpose: inserts the value into the hashed value
	// Parameter: int (value), int (hashValue)
	// Return: bool (if it succeeded or not)
	bool insert(int, int);

	// resolveCollision function
	// Purpose: tries to insert the value using linear probing
	// Parameter: int (value), int (hashValue)
	// Return: bool (if it succeeded or not)
	bool resolveCollision(int, int);

	// show function
	// Purpose: prints the contents of the hashTable
	// Parameter: none
	// Return: void
	void show();

	// search function
	// Purpose: Searches for data in the hashtable
	// Parameter: int (value)
	// Return: void
	void search(int);
};

