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
	cout << "欢迎学生" << username_ << "登录!" << endl;
	cout << endl;

	cout << "\t\t  --------------------------------------- \n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             1. 申请预约               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             2. 查看自身记录           |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             3. 查看所有预约           |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             4. 取消预约               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t |             0. 注销登录               |\n";
	cout << "\t\t |                                       |\n";
	cout << "\t\t  --------------------------------------- \n";
	cout << endl;

}

void Student::makeReservation()
{
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间: " << endl;
	cout << "1. 周一" << endl;
	cout << "2. 周二" << endl;
	cout << "3. 周三" << endl;
	cout << "4. 周四" << endl;
	cout << "5. 周五" << endl;

	string date;
	string interval;  // 时间段
	string roomId;

	while (1) {
		cin >> date;
		if (date == "1" || date == "2" || date == "3" || date == "4" || date == "5") {
			break;
		}
		cout << "输入有误, 请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段" << endl;
	cout << "1. 上午" << endl;
	cout << "2. 下午" << endl;

	while (1) {
		cin >> interval;
		if (interval == "1" || interval == "2") {
			break;
		}
		cout << "输入有误, 请重新输入" << endl;
	}

	cout << "请选择机房" << endl;
	for (int i = 0; i < vRoom_.size(); i++) {
		cout << vRoom_[i].id_ << "  号机房的容量为: " << vRoom_[i].capacity_ << endl;;
	}

	while (1) {
		cin >> roomId;

		if (roomId == "1" || roomId == "2" || roomId == "3") {
			break;
		}
		cout << "输入有误, 请重新输入" << endl;
	}

	cout << "预约成功! 审核中" << endl;

	ofstream ofs;
	ofs.open(RECORD_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "userType:" << 1 << " ";   // 学生预约
	ofs << "userId:" << id_ << " ";
	ofs << "userName:" << username_ << " ";
	ofs << "roomId:" << roomId << " ";
	ofs << "status:" << 1 << endl;   // 1. 审核中

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
		cout << "未找到预约记录" << endl;
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
		cout << "未找到预约记录" << endl;
	}

	system("pause");
	system("cls");
}

void Student::cancelReservation()
{

}

void Student::printInfo()
{
	cout << "学号: " << id_ << "\t\t 姓名: " << username_ << "\t\t 密码: " << password_ << endl;
}
