// Author: Miles Meacham
// Date: 01/27/2016
// Contents: program 2 - linked lists


#pragma once
#include <iostream>
#include <string>
#include "DoubleLinkList.h"

using namespace std;


class Node
{
private:

	//declaring variables
	Node* next;
	int value;

public:

	// Default Constructor
	// Purpose: create a default "Node"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default "Node" created
	Node();

	// Parameterized Constructor
	// Purpose: create a "Node" using the parameters given
	// Parameter: int
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 parameterized "Node" created
	Node(int);

	// setNextNode function
	// Purpose: set the next "Node" in the list
	// Parameter: Node*
	// Return: None
	// Pre-conditions: 
	// Post-conditions:
	void setNextNode(Node*);

	// setValue function
	// Purpose: set the value of nodes in the list
	// Parameter: int
	// Return: none
	// Pre-conditions:
	// Post-conditions:
	void setValue(int);

	// getNextNode function
	// Purpose: get the next "Node" in the list
	// Parameter: none
	// Return: Node*
	// Pre-conditions: at least one node in the list
	// Post-conditions: none
	Node* getNextNode() const;

	// getValue funciton
	// Purpose: get the value
	// Parameter: none
	// Return: int
	// Pre-conditions: at least one node in the list that has quantity
	// Post-conditions:
	int getValue();

	

};

class SingleLinkList
{
private:
	Node* head;
	int numbOfNodes;

public:

	// Default Constructor
	// Purpose: create a default link list
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: default list created
	SingleLinkList();

	// addNode function
	// Purpose: add a "Node" to the end of the list
	// Parameter: int
	// Return: none
	// Pre-conditions: a List must exist
	// Post-conditions: the Node is added to the end of the list
	void addNode(int);

	// getFirst function
	// Purpose: returns the first "Node" in the list
	// Parameter: none
	// Return: Node*
	// Pre-conditions: have one "Node" in the list
	// Post-conditions: none
	Node* getFirst() const;

	// traverse function
	// Purpose: traverse the list and add each Node to a doubleLinkList
	// Parameter: a DoubleLinkList 
	// Return: none
	// Pre-conditions: a List must exist
	// Post-conditions: none
	void traverse(DoubleLinkList *);

	// traversePrint function
	// Purpose: traverse the list and use the print function
	// Parameter: a function and a node
	// Return: none
	// Pre-conditions: a List must exist
	// Post-conditions: none
	void traversePrint(void(*passedFunction)(Node *));
};
