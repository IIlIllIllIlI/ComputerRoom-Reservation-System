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
	cout << "��ӭ����Ա" << username_ << "��¼!" << endl;
	cout << endl;

	cout << "\t\t  ----------------------------------- \n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             1. ����˺�           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             2. �鿴�˺�           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             3. �鿴����           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             4. ���ԤԼ           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             5. ��ռ�¼           |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             6. �鿴����ԤԼ       |\n";
	cout << "\t\t |                                   |\n";
	cout << "\t\t |             0. ע����¼           |\n";
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
	cout << "������Ҫ�������˻�����" << endl;
	cout << "1. ѧ���˻�" << endl;
	cout << "2. ��ʦ�˻�" << endl;
	cout << "0. ������һ��" << endl;

	string option;
	cin >> option;

	if (option == "1") {
		filename = STUDENT_FILE;
		idPrompt = "������ѧ��: ";
		idRepeatPrompt = "ѧ���ظ�������������";
	}
	else if (option == "2") {
		filename = TEACHER_FILE;
		idPrompt = "�������ְ����: ";
		idRepeatPrompt = "��ְ�����ظ�������������";
	}
	else if (option == "0") {
		system("cls");
		return;
	}
	else {
		cout << "������������������!" << endl;
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
	

	cout << "����������: " << endl;
	cin >> name;

	cout << "����������: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "�����ɹ���" << endl;
	
	system("pause");
	system("cls");

	ofs.close();

	// ��������
	readData();
}

void Administrator::showAccount()
{
	while (1) {
		cout << "��ѡ��鿴����: " << endl;
		cout << "1. �鿴����ѧ��" << endl;
		cout << "2. �鿴������ʦ" << endl;
		cout << "0. ������һ��" << endl;

		string option;
		cin >> option;
		if (option == "1") {
			cout << "����ѧ�����˻���Ϣ����: " << endl;
			for (vector<Student>::iterator it = vStudent_.begin(); it != vStudent_.end(); it++) {
				printAllInfo(&(*it));
			}

			system("pause");
			system("cls");
			break;
		}
		else if (option == "2") {
			cout << "���н�ʦ���˻���Ϣ����: " << endl;
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
			cout << "������������������!" << endl;
			system("pause");
			system("cls");
		}
	}
	
}

void Administrator::showRoomInfo()
{
	cout << "������Ϣ����" << endl;

	for (vector<ComputerRoom>::iterator it = vRoom_.begin(); it != vRoom_.end(); it++) {
		cout << "�������: " << it->id_ << "\t\t ��������: " << it->capacity_ << endl;
	}

	system("pause");
	system("cls");
}

void Administrator::cleanRecords()
{
	cout << "���ݲ��ɻָ�����ȷ��Ҫ�������ԤԼ��¼��" << endl;
	cout << "1. ȷ�����" << endl;
	cout << "�����������ȡ��" << endl;

	string option;
	cin >> option;
	if (option == "1") {
		ofstream ofs(RECORD_FILE, ios::trunc);
		ofs.close();

		cout << "ԤԼ��¼��ճɹ�!" << endl;
		
	}
	else {
		cout << "��ȡ�����" << endl;
	}

	system("pause");
	system("cls");
	
	
}

void Administrator::examineAppointment()
{
	cout << "���ԤԼ" << endl;
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
		cout << "δ�ҵ�ԤԼ��¼" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	Student s;
	while (ifs >> s.id_ && ifs >> s.username_ && ifs >> s.password_) {
		vStudent_.push_back(s);
	}

	cout << "��ǰ��¼���ѧ������Ϊ��" << vStudent_.size() << endl;
	ifs.close();
}

void Administrator::readTeacherData()
{
	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	Teacher t;
	while (ifs >> t.id_ && ifs >> t.username_ && ifs >> t.password_) {
		vTeacher_.push_back(t);
	}

	cout << "��ǰ��¼��Ľ�ʦ����Ϊ��" << vTeacher_.size() << endl;
	ifs.close();
}

void Administrator::readRoomData()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	ComputerRoom r;
	while (ifs >> r.id_ && ifs >> r.capacity_) {
		vRoom_.push_back(r);
	}

	cout << "��ǰ��������Ϊ��" << vRoom_.size() << endl;
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
