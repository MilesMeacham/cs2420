// Author: Miles Meacham
// Date: 01/27/2016
// Contents: program 2 - linked lists


#pragma once
#include <iostream>
#include <string>

using namespace std;


class DoubleNode
{
private:

	//declaring variables
	DoubleNode* next;
	DoubleNode* prev;
	int value;

public:

	// Default Constructor
	// Purpose: create a default "Node"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default "Node" created
	DoubleNode();

	// Parameterized Constructor
	// Purpose: create a "Node" using the parameters given
	// Parameter: int
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 parameterized "Node" created
	DoubleNode(int);

	// setNextNode function
	// Purpose: set the next "Node" in the list
	// Parameter: Node*
	// Return: None
	// Pre-conditions: 
	// Post-conditions:
	void setNextNode(DoubleNode*);

	// setPrevNode function
	// Purpose: set the prev "Node" in the list
	// Parameter: Node*
	// Return: None
	// Pre-conditions: 
	// Post-conditions:
	void setPrevNode(DoubleNode*);

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
	DoubleNode* getNextNode() const;

	// getPrevNode function
	// Purpose: get the prev "Node" in the list
	// Parameter: none
	// Return: Node*
	// Pre-conditions: at least one node in the list
	// Post-conditions: none
	DoubleNode* getPrevNode() const;

	// getValue funciton
	// Purpose: get the value
	// Parameter: none
	// Return: int
	// Pre-conditions: at least one node in the list that has quantity
	// Post-conditions:
	int getValue();



};

class DoubleLinkList
{
private:
	DoubleNode* head;
	int numbOfNodes;

public:

	// Default Constructor
	// Purpose: create a default link list
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: default list created
	DoubleLinkList();

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
	DoubleNode* getFirst() const;

	// traverse function
	// Purpose: traverse the list and use the print function
	// Parameter: a function and a node
	// Return: none
	// Pre-conditions: a List must exist
	// Post-conditions: none
	void traverse();

	// traversePrint function
	// Purpose: traverse the list and use the print function
	// Parameter: a function and a node
	// Return: none
	// Pre-conditions: a List must exist
	// Post-conditions: none
	void traversePrint(void(*passedFunction)(DoubleNode *));
};
