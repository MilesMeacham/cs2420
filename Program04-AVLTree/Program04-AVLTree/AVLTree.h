// Author: Miles Meacham
// Date: 03/06/2016
// Contents: AVL Tree

#pragma once
#include "Node.h"
#include <iostream>
#include <stack>

using namespace std;

class AVLTree
{
private:
	int count;
	Node* root;
	Node* unbalanancedNode;

public:

	// Default Constructor
	// Purpose: create a default AVL Tree
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: 1 default AVL Tree created
	AVLTree();

	// Destructor
	// Purpose: Delete the tree
	// Parameter: none
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Tree will be emptied and deleted
	~AVLTree();

	// Clear Function
	// Purpose: Called by the destructor. 
	// Parameter: Node*
	// Return: none
	// Pre-conditions: none
	// Post-conditions: Deletes each node in the tree
	void clear(Node*);

	// Inster Function
	// Purpose: Insert a node into a tree (Recursive function)
	// Parameter: Node*, Int
	// Return: Node*
	// Pre-conditions: none
	// Post-conditions: Inserts a Node into the tree
	Node* insertRecursive(Node*, int);

	// Insert Function
	// Purpose: Insert a node into a tree, this call the recursive function
	// Parameter: Node*
	// Return: void
	// Pre-conditions: none
	// Post-conditions: none
	void insert(int);

	// GetRoot Function
	// Purpose: Return the root of the tree
	// Parameter: none
	// Return: Node*
	// Pre-conditions: none
	// Post-conditions: none
	Node* getRoot();

	// Balance Factor Function
	// Purpose: Calculate the Balance Factor of the node
	// Parameter: Node*
	// Return: int
	// Pre-conditions: none
	// Post-conditions: Balance Factor will have a value
	int balFactor(Node*);

	// Height Function
	// Purpose: Calculate the height of a nodes childs
	// Parameter: Node*
	// Return: int
	// Pre-conditions: none
	// Post-conditions: none
	int height(Node*);

	// Max Function
	// Purpose: Get the larger of two numbers
	// Parameter: int, int
	// Return: int
	int max(int, int);

	// Balance Function
	// Purpose: balance the tree
	// Parameter: Node*, int
	// Return: Node*
	// Pre-conditions: Node will have a balance factor of 2 or -2
	// Post-conditions: Nodes will be rotated accordingly and balanced
	Node* balance(Node* &, int);

	// LL Rotation Function
	// Purpose: Rotate nodes for LL case
	// Parameter: Node*
	// Return: Node*
	// Pre-conditions: Node will be unbalanced
	// Post-conditions: Nodes will be rotated accordingly and balanced
	Node* ll_rotation(Node* &);

	// RR Rotation Function
	// Purpose: Rotate nodes for RR case
	// Parameter: Node*
	// Return: Node*
	// Pre-conditions: Node will be unbalanced
	// Post-conditions: Nodes will be rotated accordingly and balanced
	Node* rr_rotation(Node* &);

	// LR Rotation Function
	// Purpose: Rotate nodes for LR case
	// Parameter: Node*
	// Return: Node*
	// Pre-conditions: Node will be unbalanced
	// Post-conditions: Nodes will be rotated accordingly and balanced
	Node* lr_rotation(Node* &);

	// RL Rotation Function
	// Purpose: Rotate nodes for RL case
	// Parameter: Node*
	// Return: Node*
	// Pre-conditions: Node will be unbalanced
	// Post-conditions: Nodes will be rotated accordingly and balanced
	Node* rl_rotation(Node* &);

	// Inorder Traverse Function
	// Purpose: Print the content of the tree Inorder
	// Parameter: Node*
	// Return: void
	void inorderTraverse(Node *);

	// Postorder Traverse Function
	// Purpose: Print the content of the tree PostOrder
	// Parameter: Node*
	// Return: void
	void postorderTraverse(Node *);

	// Preorder Traverse Function
	// Purpose: Print the content of the tree Preorder
	// Parameter: Node*
	// Return: void
	void preorderTraverse(Node *);

	// Preorder Traverse Non-Recursive Function
	// Purpose: Print the content of the tree Preorder NOT using recursion
	// Parameter: Node*
	// Return: void
	void preorderTraverseNonRecursive(Node *);

	


};

