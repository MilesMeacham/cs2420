// Author: Miles Meacham
// Date: 02/12/2016
// Contents: AVL Tree

#pragma once
#include <iostream>

using namespace std;

class NodeQueue
{
private:

	//declaring variables
	NodeQueue* next;
	int value;

public:

	// Default Constructor
	// Purpose: create a default "NodeQueue"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default "NodeQueue" created
	NodeQueue();

	// Parameterized Constructor
	// Purpose: create a "NodeQueue" using the parameters given
	// Parameter: int
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 parameterized "NodeQueue" created
	NodeQueue(int);

	// setNextNode function
	// Purpose: set the next "NodeQueue" in the list
	// Parameter: NodeQueue*
	// Return: None
	// Pre-conditions: 
	// Post-conditions:
	void setNextNode(NodeQueue*);

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
	// Return: NodeQueue*
	// Pre-conditions: at least one node in the list
	// Post-conditions: none
	NodeQueue* getNextNode() const;

	// getValue funciton
	// Purpose: get the value
	// Parameter: none
	// Return: int
	// Pre-conditions: at least one node in the list that has quantity
	// Post-conditions:
	int getValue();
};

// This had to be different than the stack enum. Couldn't repeat the same names
enum ErrorCodeQueue { successQueue, overflowQueue, underflowQueue };


class Queue
{

private:
	NodeQueue * front;
	NodeQueue * rear;
public:

	// Default Constructor
	// Purpose: create a default "queue"
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default "queue" created
	Queue();

	// Deconstructor
	// Purpose: Deconstruct the Queue
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Queue will be null
	~Queue();

	// Append Function
	// Purpose: Add element to end of the queue
	// Parameter: int
	// Return: ErrorCode
	// Pre-conditions: none
	// Post-conditions: 1 element will be added to the queue
	ErrorCodeQueue Append(const int &);

	// Serve Function
	// Purpose: Serve element from front of queue
	// Parameter: none
	// Return: ErrorCode
	// Pre-conditions: none
	// Post-conditions: 1 element will be removed
	ErrorCodeQueue Serve();
};

