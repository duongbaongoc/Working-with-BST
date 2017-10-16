#pragma once
 
#include "AbstractNode.h"

using std::cout;
using std::endl;

class TransactionNode : public Node
{
public:
	//constructor
	TransactionNode(const string & newData, const int & newUnits);
	//getter
	const int & getUnits() const;
	//setter
	void setUnits(const int & newUnits);
	//other member functions
	void printData();
	//destructor
	~TransactionNode();
private:
	int mUnits;
};
