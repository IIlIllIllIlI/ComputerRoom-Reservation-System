#include "identity.h"
#pragma once
#include <iostream>
using namespace std;

class AbstractUser : public AbstractIdentity
{
public:
	virtual void makeReservation() = 0;
	virtual void showMyReservation() = 0;
	virtual void showAllReservation() = 0;
	virtual void cancelReservation() = 0;
	virtual void printInfo() = 0;
};