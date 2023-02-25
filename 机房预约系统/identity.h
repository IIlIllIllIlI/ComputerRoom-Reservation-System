#pragma once
#include <iostream>

using namespace std;

class AbstractIdentity
{
public:
	// ²Ù×÷²Ëµ¥
	virtual void printSubInterface() = 0;

	string username_;
	string password_;
};