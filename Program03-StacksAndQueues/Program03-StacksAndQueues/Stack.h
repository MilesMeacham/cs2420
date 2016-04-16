// Author: Miles Meacham
// Date: 02/12/2016
// Contents: Stacks and Queues

#pragma once
#include <iostream>

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


enum ErrorCode{ success, overflow, underflow };

class Stack
{
private:
	// Will point at the top of the stack
	Node * top;
public:

	// Default Constructor
	// Purpose: create a default "Stack"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default "Stack" created
	Stack();

	// Deconstructor
	// Purpose: Deconstruct the stack
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Stack will be null
	~Stack();

	// Push Function
	// Purpose: Put an element at the top of the stack
	// Parameter: int
	// Return: the ErrorCode
	// Pre-conditions: None
	// Post-conditions: 1 element added to the stack
	ErrorCode Push(const int &);

	// Pop Function
	// Purpose: Put an element at the top of the stack
	// Parameter: none
	// Return: the ErrorCode
	// Pre-conditions: None
	// Post-conditions: 1 element removed to the stack, Will send underflow error if stack is empty
	ErrorCode Pop();


};

