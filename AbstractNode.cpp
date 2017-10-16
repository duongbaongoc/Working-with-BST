#include "AbstractNode.h"

/**************************************************/
/******Constructors, Destructor********************/
/**************************************************/

//constructor accepts a string to set the data in the node; each pointer in the node is set to nullptr
//if no string is passed in, the data will be set to ""
Node::Node(const string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
	std::cout << "Inside Node Destructor." << std::endl;
}

/**************************************************/
/******Getters*************************************/
/**************************************************/

const string & Node::getData() const
{
	return mData;
}

Node *& Node::getPLeft()
{
	return mpLeft;
}
Node *& Node::getPRight()
{
	return mpRight;
}

/**************************************************/
/******Setters*************************************/
/**************************************************/

void Node::setData(const string newData)
{
	mData = newData;
}

void Node::setPLeft(Node *& const newNode)
{
	mpLeft = newNode;
}

void Node::setPRight(Node *& const newNode)
{
	mpRight = newNode;
}

/**************************************************/
/******Other member functions**********************/
/**************************************************/
