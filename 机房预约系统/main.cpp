#include <iostream>
#include <string>
#include "identity.h"
#include <fstream>
#include "globalFIle.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

using namespace std;

// 管理员子菜单
void adminMenu(AbstractIdentity*& person)
{
	while (1)
	{
		person->printSubInterface();

		Administrator* admin = (Administrator*)person;

		string option;
		cin >> option;

		if (option == "1") {
			// 添加账号
			admin->createAccount();
		}
		else if (option == "2") {
			// 查看账号
			admin->showAccount();
		}
		else if (option == "3") {
			// 查看机房信息
			admin->showRoomInfo();
		}
		else if (option == "4") {
			// 审核预约
			admin->examineAppointment();
		}
		else if (option == "5") {
			// 清空预约
			admin->cleanRecords();
		}
		else if (option == "6") {
			// 查看所有预约
			admin->showAllReservation();
		}
		else if (option == "0") {
			delete admin;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入错误，请重新选择!" << endl;
			system("pause");
			system("cls");
		}
	}
}

void studentMenu(AbstractIdentity*& person)
{
	while (1) {
		person->printSubInterface();

		Student* stu = (Student*)person;

		string option;
		cin >> option;

		if (option == "1") {
			// 申请预约
			stu->makeReservation();
		}
		else if (option == "2") {
			// 查看自身预约记录
			stu->showMyReservation();
		}
		else if (option == "3") {
			// 查看所有预约
			stu->showAllReservation();
		}
		else if (option == "4") {
			// 取消自身预约
			stu->cancelReservation();
		}
		else if (option == "0") {
			// 注销账户
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "输入错误，请重新选择!" << endl;
			system("pause");
			system("cls");
		}

	}
}


void login(string fileName, int type)
{
	AbstractIdentity* person = nullptr;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id;
	string pwd;
	string username;

	if (type == 1) {
		// 学生身份
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	else if (type == 3) {
		cout << "请输入用户名" << endl;
		cin >> username;
	}

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		// 学生身份验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fPwd == pwd) {
				cout << "学生账户验证登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Student(id, fName, pwd);
				ifs.close();
				// 进入学生的子界面
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		// 教师 身份验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fPwd == pwd) {
				cout << "教师账户验证登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, fName, pwd);
				ifs.close();
				// 进入教师的子界面

				return;
			}
		}
	}
	else if (type == 3) {
		// 管理员身份验证
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			if (fName == username && fPwd == pwd) {
				cout << "管理员账户验证登录成功!" << endl;
				system("pause");
				system("cls");

				person = new Administrator(fName, pwd);
				ifs.close();
				// 进入管理员的子界面
				adminMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
}


void printStartInterface()
{
	cout << endl;
	cout << string(25, '=') << "欢迎来到机房预约系统" << string(25, '=') << endl;
	cout << endl;
	
	cout << "\t\t  ----------------------------------- \n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             1. 学生               |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             2. 教师               |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             3. 管理员             |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             0. 退出系统           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t  ----------------------------------- \n";
	cout << endl;
	cout << "请输入您的身份" << endl;
}

int main()
{
	string option = "";
	while (1) {
		printStartInterface();

		cin >> option;
		if (option == "1") {
			// 学生
			login(STUDENT_FILE, 1);
		}
		else if (option == "2") {
			// 教师
			login(TEACHER_FILE, 2);
		}
		else if (option == "3") {
			// 管理员
			login(ADMIN_FILE, 3);
		}
		else if (option == "0") {
			// 退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");
		}
	}
	
}