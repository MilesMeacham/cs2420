// Author: Miles Meacham
// Date: 02/12/2016
// Contents: Stacks and Queues

#include "Queue.h"

NodeQueue::NodeQueue()
{
	// set the next node to null
	next = nullptr;
}

NodeQueue::NodeQueue(int x)
{
	// set the value
	value = x;
	// set the next node to null
	next = nullptr;
}


void NodeQueue::setNextNode(NodeQueue* p)
{
	// set the next node to p
	next = p;
}

NodeQueue* NodeQueue::getNextNode() const
{
	return next;
}

int NodeQueue::getValue()
{
	return value;
}

void NodeQueue::setValue(int val)
{
	// set the value to val
	value = val;
}

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}


Queue::~Queue()
{
	
}

ErrorCodeQueue Queue::Append(const int & _ADD)
{
	// Create a new node
	NodeQueue * newNode = new NodeQueue(_ADD);

	// If Queue is empty, assigne the front and rear to the new node.
	if (rear == nullptr)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		// Otherwise, set rear to the new node. Front will always point at the first node so don't change it here
		rear->setNextNode(newNode);
		rear = newNode;
	}

	return successQueue;
	

}

ErrorCodeQueue Queue::Serve()
{
	// If the Queue is empty return the error Underflow
	if (front == nullptr)
		return underflowQueue;
	else
	{
		// If stack is not empty, remove the Node from the front of the list
		NodeQueue * oldFront = front;
		front = oldFront->getNextNode();

		delete oldFront;

		return successQueue;
	}

}
