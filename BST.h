#pragma once

#include "AbstractNode.h"
#include "TransactionNode.h"

class BST
{
public:
	//default constructor
	BST();
	//getter
	Node *& getPRoot();
	//setter
	void setPRoot(Node *& const newNode);
	//other member functions
	void insert(const string & newData, const int & newUnits); //will call insert() in private section
	void inOrderTraversal(); //call inOrderTraversal () in private section
	TransactionNode & findSmallest(); //will call findSmallest() in the private section
	TransactionNode & findLargest(); //will call findLargest() in the private section
	//destructor
	~BST(); // calls destroyTree ()
private:
	Node * mpRoot;

	//helper functions
	void destroyTree(Node *& pRoot); //visit each node in postOrder to delete them
	void insert(Node *& pRoot, TransactionNode &newNode); //inserts recursively in the correct subtree based on mUnits
	void inOrderTraversal(Node *& pRoot); //recursively visits and prints the contents (mData and mUnits) of each node in the tree in order
										  // contents should be printed on a separate line; must call the printData () function associated with the TransactionNode
	TransactionNode & findSmallest(Node * pRoot); //returns a reference to a TransactionNode with the smallest mUnits
	TransactionNode & findLargest(Node * pRoot); //returns a reference to a TransactionNode with the largest mUnits
};
