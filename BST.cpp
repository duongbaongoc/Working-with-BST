#include "BST.h"

/**************************************************/
/******Constructors, getters, setters, destructor**/
/**************************************************/

BST::BST() //default
{
	mpRoot = nullptr;
}

Node *& BST::getPRoot()
{
	return mpRoot;
}

void BST::setPRoot(Node *& const newNode)
{
	mpRoot = newNode;
}

BST::~BST() // calls destroyTree ()
{
	std::cout << "Inside BST destructor." << std::endl;
	destroyTree(mpRoot);
}

/**************************************************/
/******Other public member functions***************/
/**************************************************/

//dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on mUnits
void BST::insert(const string & newData, const int & newUnits) 
{
	TransactionNode * pMem = new TransactionNode(newData, newUnits);
	if (pMem == nullptr)
		cout << "Could not allocate new node successfully." << endl;
	else
		insert(mpRoot, *pMem);
}

//prints the contents (mData and mUnits) of each node in the tree in order
//contents should be printed on a separate line; must call the printData () function associated with the TransactionNode
void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

//returns a reference to a TransactionNode with the smallest mUnits
TransactionNode & BST::findSmallest()
{
	//the smallest node is the left most node
	return findSmallest(mpRoot);
}

//returns a reference to a TransactionNode with the largest mUnits
TransactionNode & BST::findLargest()
{
	//the largest node is the right most node
	return findLargest(mpRoot);
}

/**************************************************/
/******Private member functions********************/
/**************************************************/

//helper of BST class destruction
//visit each node in postOrder to delete them
void BST::destroyTree(Node *& pRoot) 
{
	if (pRoot != nullptr)
	{
		destroyTree(pRoot->getPLeft());
		destroyTree(pRoot->getPRight());
		delete pRoot;
	}
}

//helper of insert() in public section
//dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on mUnits
void BST::insert(Node *& pRoot, TransactionNode &newNode)
{
	if (pRoot == nullptr) //empty tree
		pRoot = &newNode;
	else
	{
		if (newNode.getUnits() < ((TransactionNode *) pRoot)->getUnits()) //to the left
			insert(pRoot->getPLeft(), newNode);
		else if (newNode.getUnits() > ((TransactionNode *)pRoot)->getUnits()) //to the right
			insert(pRoot->getPRight(), newNode);
		else
			cout << "Duplicated item. No insertion is made." << endl;
	}
}

//helper of inOrderTraversal() in public section
//recursively visits and prints the contents (mData and mUnits) of each node in the tree in order
//contents should be printed on a separate line; must call the printData () function associated with the TransactionNode
void BST::inOrderTraversal(Node *& pRoot)
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getPLeft());
		pRoot-> printData();
		inOrderTraversal(pRoot->getPRight());
	}
}

//helper of findSmallest() in public section
//returns a reference to a TransactionNode with the smallest mUnits
TransactionNode & BST::findSmallest(Node * pRoot)
{
	//the smallest node is the left most node
	while (pRoot->getPLeft() != nullptr)
		pRoot = pRoot->getPLeft();
	return *((TransactionNode *) pRoot);
}

//helper of findLargest() in public section
//returns a reference to a TransactionNode with the largest mUnits
TransactionNode & BST::findLargest(Node * pRoot)
{
	//the largest node is the right most node
	while (pRoot->getPRight() != nullptr)
		pRoot = pRoot->getPRight();
	return *((TransactionNode *)pRoot);
}