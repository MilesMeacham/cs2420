// Author: Miles Meacham
// Date: 01/27/2016
// Contents: program 2 - linked lists

#include "DoubleLinkList.h"

DoubleNode::DoubleNode()
{
	next = nullptr; // set pointers to null
	prev = nullptr;
}

DoubleNode::DoubleNode(int x)
{
	value = x;		// set value
	next = nullptr; // set pointers to null
	prev = nullptr;
}


void DoubleNode::setNextNode(DoubleNode* p)
{
	next = p;		// Set the next node to p
}

DoubleNode* DoubleNode::getNextNode() const
{
	return next;
}

void DoubleNode::setPrevNode(DoubleNode* p)
{
	prev = p;		// Set the prev node to p
}

DoubleNode* DoubleNode::getPrevNode() const
{
	return prev;
}

int DoubleNode::getValue()
{
	return value;
}

void DoubleNode::setValue(int val)
{
	value = val;	// Set the value to val
}




DoubleLinkList::DoubleLinkList()
{
	head = NULL;
	numbOfNodes = 0;
}

void DoubleLinkList::addNode(int num)
{
	// If there are no nodes in the list
	if (head == NULL)
	{
		// Create a node using "num" as the head
		head = new DoubleNode(num);
	}
	else
	{
		// Declaring Variables
		DoubleNode *p, *q;
		p = head;
		q = NULL;

		// Find the correct spot for the value in the list
		// This will be an ordered list
		while (p != NULL && p->getValue() <= num)
		{
			q = p;
			p = p->getNextNode();
		}

		// If the node being added is smaller than the head
		if (q == NULL)
		{
			p = new DoubleNode(num);	// create a new node with num
			p->setNextNode(head);		// set the next node for p to head
			head->setPrevNode(p);		// set the prev node for head to p
			head = p;					// the new beginning of the list is the new node

		}
		else		// If the node is to be added anywhere else
		{
			p = new DoubleNode(num);			// create a new node with num
			p->setPrevNode(q);					// the prev node of p is q
			p->setNextNode(q->getNextNode());	// the next node of p is the node q is pointing at
			q->setNextNode(p);					// the new next node for q is now p

			// check to see if p is now last in the list
			if (p->getNextNode() != NULL)
			{
				// the prev node of the node p is pointing at is p
				p->getNextNode()->setPrevNode(p);
			}

		}

	}

	// increment number of nodes in the list
	numbOfNodes++;

}

DoubleNode* DoubleLinkList::getFirst() const
{
	return head;
}

void DoubleLinkList::traverse()
{
	// Declaring Variables
	DoubleNode *p;
	p = head;

	// traverse the list
	while (p != NULL)
	{
		p = p->getNextNode();
	}

}

void DoubleLinkList::traversePrint(void(*passedFunction)(DoubleNode *))
{
	// Declaring Variables
	DoubleNode *p;
	p = head;

	// Traverse the list and output the value of each node using the passed print function
	while (p != NULL)
	{
		(*passedFunction) (p);
		p = p->getNextNode();
	}

}


