#include "DataAnalysis.h"

/**************************************************/
/********************destructor********************/
/**************************************************/

//close the file
DataAnalysis::~DataAnalysis()
{
	cout << "Inside DataAnalysis destructor." << endl;
	if (mCsvStream.is_open())
		mCsvStream.close();
}

/**************************************************/
/*************public member function***************/
/**************************************************/

// operates the whole program
void DataAnalysis::runAnalysis()
{
	if (openFile())
	{
		load();
		displayReport();
	}
}

/**************************************************/
/******Private member functions********************/
/**************************************************/

//opens data.csv and must use mCsvStream to open the file
//return true if the file is open successfully
bool DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
	return mCsvStream.is_open();
}

//reads one line from the file and splits the line into units, type, and transaction fields
//return false if read line successfully, fasle otherwise
bool DataAnalysis::readLine(int & units, string & type, string & transaction)
{
	getline(mCsvStream, type, ',');
	if (type == "")
		return false;
	else
	{
		units = std::stoi(type);
		getline(mCsvStream, type, ',');
		getline(mCsvStream, transaction);
	}
	return true;
}

//compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
void DataAnalysis::insertToTree(const int & units, const string & type, const string & transaction)
{
	if (transaction == "Sold")
		mTreeSold.insert(type, units);
	else
		mTreePurchased.insert(type, units);
}

//read the file content into the two trees, then displays the current contents of both BSTs using inOrderTraversal ()
void DataAnalysis::load()
{
	int units = 0;
	string type, transaction;
	bool successReadLine = false;

	getline(mCsvStream, type); //ignore the header in the file
	while (!mCsvStream.eof())
	{
		successReadLine = readLine(units, type, transaction);
		if (successReadLine)
			insertToTree(units, type, transaction);
	}

	//display the two trees
	cout << "*******TREE OF SOLD ITEMS********" << endl;
	mTreeSold.inOrderTraversal();
	cout << "*****TREE OF PURCHASED ITEMS*****" << endl;
	mTreePurchased.inOrderTraversal();
}

//display the type and number of units that are least purchased and sold, and the most purchased and sold
void DataAnalysis::displayReport()
{
	cout << "     *******TREND REPORT**********" << endl;
	cout << setw(20) << "TREND" << setw(20) << "PRODUCT TYPE" << setw(20) << "UNITS" << endl;
	cout << "     --------------------------------------------------------" << endl;
	cout << setw(20) << "Least purchased:"  << 
		setw(20) <<  mTreePurchased.findSmallest().getData() << 
		setw(20) << mTreePurchased.findSmallest().getUnits() << endl;
	cout << setw(20) << "Most purchased:" << 
		setw(20) << mTreePurchased.findLargest().getData() << 
		setw(20) << mTreePurchased.findLargest().getUnits() << endl;
	cout << setw(20) << "Least sold:" << 
		setw(20) << mTreeSold.findSmallest().getData() << 
		setw(20) << mTreeSold.findSmallest().getUnits() << endl;
	cout << setw(20) << "Most sold:" << 
		setw(20) << mTreeSold.findLargest().getData() << 
		setw(20) << mTreeSold.findLargest().getUnits() << endl;
	cout << "     ********************************" << endl << endl << endl;
}