#pragma once
#include "identity.h"
#include "iostream"
#include "fstream"
#include "globalFIle.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computer_room.h"
#include <algorithm>

using namespace std;
class Administrator : public AbstractIdentity
{
	vector<Student> vStudent_;
	vector<Teacher> vTeacher_;
	vector<ComputerRoom> vRoom_;

public:
	Administrator();

	Administrator(string name, string pwd);

	void printSubInterface();

	void createAccount();

	void showAccount();

	void showRoomInfo();

	void cleanRecords();

	void examineAppointment();

	void showAllReservation();

private:
	void readData();

	void readStudentData();

	void readTeacherData();

	void readRoomData();

	// type 1 = 学生，  type 2 = 教师
	bool checkRepeat(int id, int type);

	void printAllInfo(AbstractUser* user);

	//void printTeacherInfo(Teacher s);
};

