#include "TransactionNode.h"

/**************************************************/
/******Constructors, getters, setters, destructor**/
/**************************************************/

TransactionNode::TransactionNode(const string & newData, 
	const int & newUnits) : Node(newData)
{
	mUnits = newUnits;
}

const int & TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::setUnits(const int & newUnits)
{
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{
	cout << "Inside TransactionNode destructor." << endl;
}

/**************************************************/
/******Other member functions**********************/
/**************************************************/

void TransactionNode::printData()
{
	cout << mData << endl;
	cout << mUnits << endl << endl;
}