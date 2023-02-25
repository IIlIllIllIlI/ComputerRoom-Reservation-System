#include "student.h"


Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	id_ = id;
	username_ = name;
	password_ = pwd;

	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);

	ComputerRoom cr;
	while (ifs >> cr.id_ && ifs >> cr.capacity_) {
		vRoom_.push_back(cr);
	}
	ifs.close();
}

void Student::printSubInterface()
{
	cout << endl;
	cout << "��ӭѧ��" << username_ << "��¼!" << endl;
	cout << endl;

	cout << "\t\t  --------------------------------------- \n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             1. ����ԤԼ               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             2. �鿴�����¼           |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             3. �鿴����ԤԼ           |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             4. ȡ��ԤԼ               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             0. ע����¼               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t  --------------------------------------- \n";
	cout << endl;

}

void Student::makeReservation()
{
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ��: " << endl;
	cout << "1. ��һ" << endl;
	cout << "2. �ܶ�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "5. ����" << endl;

	string date;
	string interval;  // ʱ���
	string roomId;

	while (1) {
		cin >> date;
		if (date == "1" || date == "2" || date == "3" || date == "4" || date == "5") {
			break;
		}
		cout << "��������, ����������" << endl;
	}

	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;

	while (1) {
		cin >> interval;
		if (interval == "1" || interval == "2") {
			break;
		}
		cout << "��������, ����������" << endl;
	}

	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vRoom_.size(); i++) {
		cout << vRoom_[i].id_ << "  �Ż���������Ϊ: " << vRoom_[i].capacity_ << endl;;
	}

	while (1) {
		cin >> roomId;

		if (roomId == "1" || roomId == "2" || roomId == "3") {
			break;
		}
		cout << "��������, ����������" << endl;
	}

	cout << "ԤԼ�ɹ�! �����" << endl;

	ofstream ofs;
	ofs.open(RECORD_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "userType:" << 1 << " ";   // ѧ��ԤԼ
	ofs << "userId:" << id_ << " ";
	ofs << "userName:" << username_ << " ";
	ofs << "roomId:" << roomId << " ";
	ofs << "status:" << 1 << endl;   // 1. �����

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyReservation()
{
	RecordManager rm;
	bool hasResult = false;

	for (int i = 0; i < rm.getSize(); i++) {
		Record* r = rm.vec_[i];
		if (r->userType_ == "1" && atoi(r->userId_.c_str()) == id_) {
			hasResult = true;
			r->printRecord();
		}
	}

	if (!hasResult) {
		cout << "δ�ҵ�ԤԼ��¼" << endl;
	}

	system("pause");
	system("cls");
}

void Student::showAllReservation()
{
	RecordManager rm;
	bool hasResult = false;

	for (int i = 0; i < rm.getSize(); i++) {
		Record* r = rm.vec_[i];
		if (r->userType_ == "1" && atoi(r->userId_.c_str()) == id_) {
			hasResult = true;
			r->printRecord();
		}
		else {
			r->printRecordPrivate();
		}
	}

	if (!hasResult) {
		cout << "δ�ҵ�ԤԼ��¼" << endl;
	}

	system("pause");
	system("cls");
}

void Student::cancelReservation()
{

}

void Student::printInfo()
{
	cout << "ѧ��: " << id_ << "\t\t ����: " << username_ << "\t\t ����: " << password_ << endl;
}
