#pragma once
#include "identity.h"
#include "computer_room.h"
#include <fstream>
#include "record_manager.h"
#include <iostream>
#include "globalFIle.h"
#include <vector>

using namespace std;

class AbstractUser : public AbstractIdentity
{
protected:
	vector<ComputerRoom> vRoom_;

public:
	virtual void makeReservation() = 0;
	virtual void showMyReservation() = 0;
	virtual void showAllReservation() = 0;
	virtual void cancelReservation() = 0;
	virtual void printInfo() = 0;
};