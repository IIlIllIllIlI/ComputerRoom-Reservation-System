#pragma once
#include <iostream>

using namespace std;

class AbstractIdentity
{
public:
	// ?????˵?
	virtual void printSubInterface() = 0;
	virtual void showAllReservation() = 0;

	string username_;
	string password_;
};