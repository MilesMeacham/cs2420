// Author: Miles Meacham
// Date: 03/06/2016
// Contents: AVL Tree


#include "Node.h"



Node::Node()
{
	rchild = nullptr;
	lchild = nullptr;
	balanceFactor = 0;
}


Node::Node(int data)
{
	entry = data;
	rchild = nullptr;
	lchild = nullptr;
	balanceFactor = 0;
}

void Node::setData(int data)
{
	entry = data;
}

void Node::setRightChild(Node* p)
{
	rchild = p;
}

void Node::setLeftChild(Node* p)
{
	lchild = p;
}

void Node::setBalanceFactor(int bf)
{
	balanceFactor = bf;
}

int Node::getData()
{
	return entry;
}

Node* Node::getRightChild()
{
	return rchild;
}

Node* Node::getLeftChild()
{
	return lchild;
}

int Node::getBalanceFactor()
{
	return balanceFactor;
}
