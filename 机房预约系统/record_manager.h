#pragma once
#include <map>
#include "globalFIle.h"
#include <fstream>
#include "record.h"
using namespace std;
class RecordManager
{
	int size_;

public:

	map<int, Record*> map_;

	RecordManager(); 

	void writeFile();

	~RecordManager();

	int getSize();

private:
	string getVal(string str);

	void readFile();

	void sortRecord();
};

