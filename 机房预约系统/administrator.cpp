#include "administrator.h"

Administrator::Administrator()
{

}

Administrator::Administrator(string name, string pwd)
{
	username_ = name;
	password_ = pwd;

	readData();
}

void Administrator::printSubInterface()
{
	cout << endl;
	cout << "欢迎管理员" << username_ << "登录!" << endl;
	cout << endl;

	cout << "\t\t  ----------------------------------- \n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             1. 添加账号           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             2. 查看账号           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             3. 查看机房           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             4. 审核预约           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             5. 清空记录           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             6. 查看所有预约       |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             0. 注销登录           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t  ----------------------------------- \n";
	cout << endl;
}

void Administrator::createAccount()
{

	string filename;
	string idPrompt;
	string idRepeatPrompt;
	ofstream ofs;
	
	cout << endl;
	cout << "请输入要创建的账户类型" << endl;
	cout << "1. 学生账户" << endl;
	cout << "2. 教师账户" << endl;
	cout << "0. 返回上一级" << endl;

	string option;
	cin >> option;

	if (option == "1") {
		filename = STUDENT_FILE;
		idPrompt = "请输入学号: ";
		idRepeatPrompt = "学号重复，请重新输入";
	}
	else if (option == "2") {
		filename = TEACHER_FILE;
		idPrompt = "请输入教职工号: ";
		idRepeatPrompt = "教职工号重复，请重新输入";
	}
	else if (option == "0") {
		system("cls");
		return;
	}
	else {
		cout << "输入有误，请重新输入!" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << idPrompt << endl;
	
	int type;
	if (option == "1") {
		type = 1;
	}
	else {
		type = 2;
	}

	while (1) {
		cin >> id;
		bool result = checkRepeat(id, type);

		if (result) {
			cout << idRepeatPrompt << endl;
		}
		else {
			break;
		}
	}
	

	cout << "请输入姓名: " << endl;
	cin >> name;

	cout << "请输入密码: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "创建成功！" << endl;
	
	system("pause");
	system("cls");

	ofs.close();

	// 更新容器
	readData();
}

void Administrator::showAccount()
{
	while (1) {
		cout << "请选择查看内容: " << endl;
		cout << "1. 查看所有学生" << endl;
		cout << "2. 查看所有老师" << endl;
		cout << "0. 返回上一级" << endl;

		string option;
		cin >> option;
		if (option == "1") {
			cout << "所有学生的账户信息如下: " << endl;
			for (vector<Student>::iterator it = vStudent_.begin(); it != vStudent_.end(); it++) {
				printAllInfo(&(*it));
			}

			system("pause");
			system("cls");
			break;
		}
		else if (option == "2") {
			cout << "所有教师的账户信息如下: " << endl;
			for (vector<Teacher>::iterator it = vTeacher_.begin(); it != vTeacher_.end(); it++) {
				printAllInfo(&(*it));
			}

			system("pause");
			system("cls");
			break;
		}
		else if (option == "0") {
			system("cls");
			return;
		}
		else {
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");
		}
	}
	
}

void Administrator::showRoomInfo()
{
	cout << "机房信息如下" << endl;

	for (vector<ComputerRoom>::iterator it = vRoom_.begin(); it != vRoom_.end(); it++) {
		cout << "机房编号: " << it->id_ << "\t\t 机房容量: " << it->capacity_ << endl;
	}

	system("pause");
	system("cls");
}

void Administrator::cleanRecords()
{
	cout << "数据不可恢复，您确定要清空所有预约记录吗？" << endl;
	cout << "1. 确认清空" << endl;
	cout << "按其他任意键取消" << endl;

	string option;
	cin >> option;
	if (option == "1") {
		ofstream ofs(RECORD_FILE, ios::trunc);
		ofs.close();

		cout << "预约记录清空成功!" << endl;
		
	}
	else {
		cout << "已取消清空" << endl;
	}

	system("pause");
	system("cls");
	
	
}

void Administrator::examineAppointment()
{
	cout << "审核预约" << endl;
}

void Administrator::showAllReservation()
{
	RecordManager rm;
	bool hasResult = false;

	for (int i = 0; i < rm.getSize(); i++) {
		Record* r = rm.vec_[i];
		hasResult = true;
		r->printRecord();
	}

	if (!hasResult) {
		cout << "未找到预约记录" << endl;
	}

	system("pause");
	system("cls");
}

void Administrator::readData()
{
	vStudent_.clear();
	vTeacher_.clear();
	vRoom_.clear();

	readStudentData();
	readTeacherData();
	readRoomData();
}

void Administrator::readStudentData()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	Student s;
	while (ifs >> s.id_ && ifs >> s.username_ && ifs >> s.password_) {
		vStudent_.push_back(s);
	}

	cout << "当前已录入的学生数量为：" << vStudent_.size() << endl;
	ifs.close();
}

void Administrator::readTeacherData()
{
	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	Teacher t;
	while (ifs >> t.id_ && ifs >> t.username_ && ifs >> t.password_) {
		vTeacher_.push_back(t);
	}

	cout << "当前已录入的教师数量为：" << vTeacher_.size() << endl;
	ifs.close();
}

void Administrator::readRoomData()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	ComputerRoom r;
	while (ifs >> r.id_ && ifs >> r.capacity_) {
		vRoom_.push_back(r);
	}

	cout << "当前机房数量为：" << vRoom_.size() << endl;
	ifs.close();
}

bool Administrator::checkRepeat(int id, int type)
{
	if (type == 1) {
		for (vector<Student>::iterator it = vStudent_.begin(); it != vStudent_.end(); it++)
		{
			if (it->id_ == id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTeacher_.begin(); it != vTeacher_.end(); it++)
		{
			if (it->id_ == id) {
				return true;
			}
		}
	}

	return false;
}

void Administrator::printAllInfo(AbstractUser* user)
{
	user->printInfo();
}
