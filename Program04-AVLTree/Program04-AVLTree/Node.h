// Author: Miles Meacham
// Date: 03/06/2016
// Contents: AVL Tree

#pragma once

class Node
{
private:
	int entry;
	Node * lchild;
	Node * rchild;
	int balanceFactor;

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

	// setData Function
	// Purpose: Sets data equal to the int passed
	// Parameter: int
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Data has value of int
	void setData(int);

	// Set Right Child Function
	// Purpose: Sets the right child equal to the pointer that is passed
	// Parameter: Node*
	// Return: none
	// Pre-conditions: none
	// Post-conditions: RightChild is equal to pointer
	void setRightChild(Node*);

	// Set Left Child Function
	// Purpose: Sets the left child equal to the pointer that is passed
	// Parameter: Node*
	// Return: none
	// Pre-conditions: none
	// Post-conditions: LeftChild is equal to pointer
	void setLeftChild(Node*);

	// Set Balance Factor Function
	// Purpose: Balance factor is equal to the int passed
	// Parameter: int
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Balance Factor is equal to the int passed
	void setBalanceFactor(int);

	// Get Data Function
	// Purpose: The value of data is returned
	// Parameter: none
	// Return: int
	int getData();

	// Get Right Child Function
	// Purpose: The value of Right Child is returned
	// Parameter: none
	// Return: Node*
	Node* getRightChild();

	// Get Left Child Function
	// Purpose: The value of Left Child is returned
	// Parameter: none
	// Return: Node*
	Node* getLeftChild();

	// Get Balance Factor Function
	// Purpose: The value of Balance Factor is returned
	// Parameter: none
	// Return: int
	int getBalanceFactor();

};

