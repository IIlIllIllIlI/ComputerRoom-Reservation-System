#include <iostream>
#include <string>
#include "identity.h"
#include <fstream>
#include "globalFIle.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

using namespace std;

// ����Ա�Ӳ˵�
void adminMenu(AbstractIdentity*& person)
{
	while (1)
	{
		person->printSubInterface();

		Administrator* admin = (Administrator*)person;

		string option;
		cin >> option;

		if (option == "1") {
			// ����˺�
			admin->createAccount();
		}
		else if (option == "2") {
			// �鿴�˺�
			admin->showAccount();
		}
		else if (option == "3") {
			// �鿴������Ϣ
			admin->showRoomInfo();
		}
		else if (option == "4") {
			// ���ԤԼ
			admin->examineAppointment();
		}
		else if (option == "5") {
			// ���ԤԼ
			admin->cleanRecords();
		}
		else if (option == "6") {
			// �鿴����ԤԼ
			admin->showAllReservation();
		}
		else if (option == "0") {
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "�������������ѡ��!" << endl;
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
			// ����ԤԼ
			stu->makeReservation();
		}
		else if (option == "2") {
			// �鿴����ԤԼ��¼
			stu->showMyReservation();
		}
		else if (option == "3") {
			// �鿴����ԤԼ
			stu->showAllReservation();
		}
		else if (option == "4") {
			// ȡ������ԤԼ
			stu->cancelReservation();
		}
		else if (option == "0") {
			// ע���˻�
			delete stu;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "�������������ѡ��!" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id;
	string pwd;
	string username;

	if (type == 1) {
		// ѧ�����
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	else if (type == 3) {
		cout << "�������û���" << endl;
		cin >> username;
	}

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		// ѧ�������֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fPwd == pwd) {
				cout << "ѧ���˻���֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Student(id, fName, pwd);
				ifs.close();
				// ����ѧ�����ӽ���
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		// ��ʦ �����֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fPwd == pwd) {
				cout << "��ʦ�˻���֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, fName, pwd);
				ifs.close();
				// �����ʦ���ӽ���

				return;
			}
		}
	}
	else if (type == 3) {
		// ����Ա�����֤
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			if (fName == username && fPwd == pwd) {
				cout << "����Ա�˻���֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Administrator(fName, pwd);
				ifs.close();
				// �������Ա���ӽ���
				adminMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
}


void printStartInterface()
{
	cout << endl;
	cout << string(25, '=') << "��ӭ��������ԤԼϵͳ" << string(25, '=') << endl;
	cout << endl;
	
	cout << "\t\t  ----------------------------------- \n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             1. ѧ��               |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             2. ��ʦ               |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             3. ����Ա             |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             0. �˳�ϵͳ           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t  ----------------------------------- \n";
	cout << endl;
	cout << "�������������" << endl;
}

int main()
{
	string option = "";
	while (1) {
		printStartInterface();

		cin >> option;
		if (option == "1") {
			// ѧ��
			login(STUDENT_FILE, 1);
		}
		else if (option == "2") {
			// ��ʦ
			login(TEACHER_FILE, 2);
		}
		else if (option == "3") {
			// ����Ա
			login(ADMIN_FILE, 3);
		}
		else if (option == "0") {
			// �˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "������������������!" << endl;
			system("pause");
			system("cls");
		}
	}
	
}