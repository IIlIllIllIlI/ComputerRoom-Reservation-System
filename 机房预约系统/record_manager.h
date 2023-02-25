#pragma once
#include <vector>
#include "globalFIle.h"
#include <fstream>
#include "record.h"
#include <algorithm>

using namespace std;
class RecordManager
{
	int size_;

public:

	vector<Record*> vec_;

	RecordManager(); 

	void writeFile();

	~RecordManager();

	int getSize();
	
	//void addRecord(string date, string interval, string userType, string userId,
	//	string username, string roomId, string status);

private:
	string getVal(string str);

	void readFile();

	void sortRecord();

};

