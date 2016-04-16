// Author: Miles Meacham
// Date: 03/06/2016
// Contents: AVL Tree


#include "AVLTree.h"



AVLTree::AVLTree()
{
	count = 0;
	root = nullptr;
	unbalanancedNode = nullptr;
}


AVLTree::~AVLTree()
{
	clear(root);
}

void AVLTree::clear(Node* p)
{
	if (p != nullptr)   //if p is null the tree is empty
	{
		clear(p->getLeftChild());	// Delete everything in left child
		clear(p->getRightChild());	// Delete everything in right child
		
		// Delete this node
		delete p;					
		p = nullptr;				
	}

}

Node* AVLTree::insertRecursive(Node* p, int data)
{
	if (p == nullptr)			// Once an empty space for new data is found
		return new Node(data);	// Insert new data


	// Send data left or right depending on its size
	if (data < p->getData())
		p->setLeftChild(insertRecursive(p->getLeftChild(), data));
	else if (data > p->getData())
		p->setRightChild(insertRecursive(p->getRightChild(), data));
	else
		cout << "-Duplicate Data";

	// Balance this node and return  **Will only balance if BF is 2 or -2
	return balance(p, data);
}

void AVLTree::insert(int data)
{
	// Call the recursive insert function and set root equal to whatever it returns
	root = insertRecursive(root, data);
}

Node* AVLTree::getRoot()
{
	return root;
}

int AVLTree::max(int a, int b)
{
	// Figure out wether a or b is larger
	int c = a;

	if (a < b)
		c = b;

	return c;
}

int AVLTree::height(Node * p)
{
	
	if (p == nullptr)
		return 0;
	
	// Figure out height using this recursive function
	if (p->getRightChild() == nullptr && p->getLeftChild() == nullptr)
		return 1;
	else
		return 1 + max(height(p->getRightChild()), height(p->getLeftChild()));
}

int AVLTree::balFactor(Node * p)
{
	// Set balance factor equal to left side minus right side
	p->setBalanceFactor(height(p->getLeftChild()) - height(p->getRightChild()));

	return p->getBalanceFactor();
}

Node* AVLTree::balance(Node* & p, int data)
{
	// Find the balance factor of p
	balFactor(p);

	// If balance factor is -2 or 2 it needs to be balanced
	if (p->getBalanceFactor() == -2)			// data went right
	{
		if (balFactor(p->getRightChild()) < 0)	// data went right again
			return rr_rotation(p);
		else									// data went right then left
			return rl_rotation(p);
	}
	else if (p->getBalanceFactor() == 2)		// data went left
	{
		if (balFactor(p->getLeftChild()) > 0)	// data went left again
			return ll_rotation(p);
		else									// data went left then right
			return lr_rotation(p);
	}

	return p;
}

Node* AVLTree::ll_rotation(Node * & parent)
{
	// Rotate for LL Case
	Node * child = parent->getLeftChild();
	parent->setLeftChild(child->getRightChild());
	child->setRightChild(parent);

	return child;
}

Node* AVLTree::rr_rotation(Node * & p)
{
	// Rotate for RR Case
	Node * parent = p;
	Node * child = parent->getRightChild();
	parent->setRightChild(child->getLeftChild());
	child->setLeftChild(parent);

	p = child;

	return child;
}

Node* AVLTree::lr_rotation(Node * & parent)
{
	// Rotate for LR Case
	Node * grandChild = parent->getLeftChild()->getRightChild();
	parent->getLeftChild()->setRightChild(grandChild->getLeftChild());

	grandChild->setLeftChild(parent->getLeftChild());
	parent->setLeftChild(grandChild->getRightChild());

	grandChild->setRightChild(parent);

	return grandChild;
}

Node* AVLTree::rl_rotation(Node * & parent)
{
	// Rotate for RL Case
	Node * grandChild = parent->getRightChild()->getLeftChild();

	parent->getRightChild()->setLeftChild(grandChild->getRightChild());

	grandChild->setRightChild(parent->getRightChild());
	parent->setRightChild(grandChild->getLeftChild());

	grandChild->setLeftChild(parent);

	return grandChild;
}


void AVLTree::inorderTraverse(Node * r)
{
	// Output data of tree Inorder
	if (r != nullptr)   
	{
		inorderTraverse(r->getLeftChild());
		cout << r->getData() << " ";
		inorderTraverse(r->getRightChild());
	}
}

void AVLTree::postorderTraverse(Node * r)
{
	// Output data of tree Postorder
	if (r != nullptr) 
	{
		postorderTraverse(r->getLeftChild());
		postorderTraverse(r->getRightChild());
		cout << r->getData() << " ";
	}
}

void AVLTree::preorderTraverse(Node * r)
{
	// Output data of tree PreOrder
	if (r != nullptr) 
	{
		cout << r->getData() << " ";
		preorderTraverse(r->getLeftChild());
		preorderTraverse(r->getRightChild());
	}
}

void AVLTree::preorderTraverseNonRecursive(Node * r)
{
	Node * p = r;
	stack<Node*> s;

	// Run down the left children and put each one in a stack
	while (p != nullptr)
	{
		cout << p->getData() << " ";
		s.push(p);   
		p = p->getLeftChild();
	}

	while (!s.empty())
	{
		// pop the top of the stack
		p = s.top();
		s.pop();
		
		// get the right child
		p = p->getRightChild();

		// Using this while loop again so I don't have to use a "goto"
		while (p != nullptr)
		{
			// output the node first, then get the others
			cout << p->getData() << " ";
			s.push(p); 
			p = p->getLeftChild();
		}

	}

	cout << endl << endl;
}

