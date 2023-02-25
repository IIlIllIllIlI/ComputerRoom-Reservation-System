#pragma once
#include <iostream>

#include "user.h"
using namespace std;

class Teacher : public AbstractUser
{
public:
	int id_;   // Ö°¹¤±àºÅ

	Teacher();

	Teacher(int id, string name, string pwd);

	void printSubInterface();

	void makeReservation();

	void showMyReservation();

	void showAllReservation();

	void cancelReservation();

	void printInfo();
};

