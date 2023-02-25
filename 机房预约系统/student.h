#pragma once
#include <iostream>
#include "user.h"
#include <vector>
#include "computer_room.h"
#include <fstream>
#include "globalFIle.h"
#include "record_manager.h"

using namespace std; 
class Student : public AbstractUser
{

	vector<ComputerRoom> vRoom_;
public:
	int id_;  // Ñ§ºÅ

	Student();

	Student(int id, string name, string pwd);

	void printSubInterface();

	void makeReservation();

	void showMyReservation();

	void showAllReservation();

	void cancelReservation();

	void printInfo();
};

