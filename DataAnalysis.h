#pragma once

#include <fstream>
#include <iomanip>
#include "BST.h"

using std::getline;
using std::setw;

class DataAnalysis
{
public:
	//member function
	void runAnalysis(); // operates the whole program
	//destructor
	~DataAnalysis(); //close the file
private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	/*********private functions/helper functions***********/

	//opens data.csv and must use mCsvStream to open the file
	//return true if the file is open successfully
	bool openFile(); 

	//reads one line from the file and splits the line into units, type, and transaction fields
	//return false if read line successfully, fasle otherwise
	bool readLine(int & units, string & type, string & transaction);

	//compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
	void insertToTree(const int & units, const string & type, const string & transaction);

	//read the file content into the two trees, then displays the current contents of both BSTs
	void load();

	//display the type and number of units that are least purchased and sold, and the most purchased and sold
	void displayReport();
};
