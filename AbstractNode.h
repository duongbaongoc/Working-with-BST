#pragma once
#include <iostream>
#include <string>

using std::string;

class Node
{
public:
	//constructor
	Node(const string newData = ""); //accept a string to set the data in the node; each pointer in the node is set to nullptr
	//getters
	const string & getData() const;
	Node *& getPLeft();
	Node *& getPRight();
	//setters
	void setData(const string newData);
	void setPLeft(Node *& const newNode);
	void setPRight(Node *& const newNode);
	//member functions
	virtual void printData() = 0; //must be overridden in class TransactionNode
		//destructor
	virtual ~Node();
protected:
	string mData;
	Node *mpLeft;
	Node * mpRight;
};