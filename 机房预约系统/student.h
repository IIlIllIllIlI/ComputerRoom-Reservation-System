#pragma once
#include "user.h"
using namespace std; 
class Student : public AbstractUser
{


public:
	int id_;  // ѧ��

	Student();

	Student(int id, string name, string pwd);

	void printSubInterface();

	void makeReservation();

	void showMyReservation();

	void showAllReservation();

	void cancelReservation();

	void printInfo();
};

