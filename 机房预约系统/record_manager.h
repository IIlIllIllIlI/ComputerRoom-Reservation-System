#pragma once
#include <vector>
#include "globalFIle.h"
#include <fstream>
#include "record.h"
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

private:
	string getVal(string str);

	void readFile();

	//void sortRecord();
};

