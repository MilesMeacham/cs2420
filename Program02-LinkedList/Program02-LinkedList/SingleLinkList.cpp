// Author: Miles Meacham
// Date: 01/27/2016
// Contents: program 2 - linked lists

#include "SingleLinkList.h"

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




SingleLinkList::SingleLinkList()
{
	head = NULL;
	numbOfNodes = 0;
}

void SingleLinkList::addNode(int num)
{
	// if the list is empty
	if (head == NULL)
	{
		// create a new node that is the head
		head = new Node(num);
	}
	else
	{
		// declaring variables
		Node *p, *q;
		p = head;
		q = new Node(num);

		// traverse the list until p is the last node
		while (p->getNextNode() != NULL)
		{
			p = p->getNextNode();
		}

		// set the next node of p to q
		p->setNextNode(q);

	}

	// increment the number of nodes in the list
	numbOfNodes++;

}

Node* SingleLinkList::getFirst() const
{
	return head;
}

void SingleLinkList::traverse(DoubleLinkList *dll)
{
	// Declaring Variables
	Node *p;
	p = head;

	// Traverse the list and pass each node to the doubleLinkList
	while (p != NULL)
	{
		dll->addNode(p->getValue());
		p = p->getNextNode();
	}

}

void SingleLinkList::traversePrint(void(*passedFunction)(Node *))
{
	// Declaring Variables
	Node *p;
	p = head;

	// Traverse the list and print out each node using the passed print function
	while (p != NULL)
	{
		(*passedFunction) (p);
		p = p->getNextNode();
	}

}


