#pragma once
#include <iostream>
#include <string>

using namespace std;
class Record
{
public:
	string date_;
	string interval_;
	string userType_;
	string userId_;
	string username_;
	string roomId_;
	string status_;

	Record(string date, string interval, string userType,
		string userId, string username, string roomId, string status);

	void printRecord();

	void printRecordPrivate();

	bool operator<(const Record& rec) const;
};

