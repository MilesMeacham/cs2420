// Author: Miles Meacham
// Date: 02/12/2016
// Contents: Stacks and Queues

#include "Stack.h"

Node::Node()
{
	// set the next node to null
	next = nullptr;
}

Node::Node(int x)
{
	// set the value
	value = x;
	// set the next node to null
	next = nullptr;
}


void Node::setNextNode(Node* p)
{
	// set the next node to p
	next = p;
}

Node* Node::getNextNode() const
{
	return next;
}

int Node::getValue()
{
	return value;
}

void Node::setValue(int val)
{
	// set the value to val
	value = val;
}


Stack::Stack()
{
	top = nullptr;
}


Stack::~Stack()
{
	// empty the stack
	while (top != nullptr)
	{
		this->Pop();
	}
}


ErrorCode Stack::Push(const int & _ADD)
{
	// Create a new node
	Node * newNode = new Node(_ADD);

	if (top == nullptr)
		top = newNode;	// If the stack was empty, the newNode is the top and nothing else is needed.
	else
	{
		newNode->setNextNode(top);  // Set the nextNode of the newNode to top
		top = newNode;				// top is now equal to the newNode
	}

	return success;

}

ErrorCode Stack::Pop()
{
	// Create a new node that is the top
	Node * oldTop = top;

	if (top == NULL)
		return underflow; // if top is empty there is nothing to remove, return underflow
	else
	{
		top = oldTop->getNextNode();	// Set the top down 1 node 
		delete oldTop;					// Delete the old top
		return success;
	}

}
