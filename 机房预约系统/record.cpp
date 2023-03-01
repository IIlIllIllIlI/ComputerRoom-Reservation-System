#include "record.h"


Record::Record(string date, string interval, string userType, string userId,
	string username, string roomId, string status)
{
	date_ = date;
	interval_ = interval;
	userType_ = userType;
	userId_ = userId;
	username_ = username;
	roomId_ = roomId;
	status_ = status;
}

void Record::printRecord()
{
	string date;
	string interval;
	string userType;
	//string userId;
	//string username;
	//string roomId;
	string status;

	if (date_ == "1") {
		date = "��һ";
	}
	else if (date_ == "2") {
		date = "�ܶ�";
	}
	else if (date_ == "3") {
		date = "����";
	}
	else if (date_ == "4") {
		date = "����";
	}
	else if (date_ == "5") {
		date = "����";
	}
	else {
		date = "����";
	}

	if (interval_ == "1") {
		interval = "����";
	}
	else if (interval_ == "2") {
		interval = "����";
	}
	else {
		interval = "����";
	}

	if (userType_ == "1") {
		userType = "ͬѧ";
	}
	else if (userType_ == "2") {
		userType = "��ʦ";
	}
	else {
		userType = "����";
	}

	if (status_ == "1") {
		status = "�����";
	}
	else if (status_ == "2") {
		status = "����׼";
	}
	else if (status_ == "0") {
		status = "��ȡ��";
	}
	else {
		status = "����";
	}

	cout << date << "\t" << interval << "\t\t" << roomId_ << "�Ż���" <<
		"\t\tԤԼ��: " << username_ << userType << "\t\t��ǰ״̬: " << status << endl;

}

void Record::printRecordPrivate()
{
	string date;
	string interval;
	string userType;
	string status;

	if (date_ == "1") {
		date = "��һ";
	}
	else if (date_ == "2") {
		date = "�ܶ�";
	}
	else if (date_ == "3") {
		date = "����";
	}
	else if (date_ == "4") {
		date = "����";
	}
	else if (date_ == "5") {
		date = "����";
	}
	else {
		date = "����";
	}

	if (interval_ == "1") {
		interval = "����";
	}
	else if (interval_ == "2") {
		interval = "����";
	}
	else {
		interval = "����";
	}

	if (userType_ == "1") {
		userType = "ͬѧ";
	}
	else if (userType_ == "2") {
		userType = "��ʦ";
	}
	else {
		userType = "����";
	}

	if (status_ == "1") {
		status = "�����";
	}
	else if (status_ == "2") {
		status = "����׼";
	}
	else if (status_ == "0") {
		status = "��ȡ��";
	}
	else {
		status = "����";
	}

	cout << date << "\t" << interval << "\t\t" << roomId_ << "�Ż���" <<
		"\t\t�û����: "  << userType << "\t\t��ǰ״̬: " << status << endl;
}

bool Record::operator<(const Record& rec) const
{
	if (stoi(date_) < stoi(rec.date_)) {
		return true;
	}
	else if (stoi(date_) > stoi(rec.date_)) {
		return false;
	}
	else {
		return (stoi(interval_) < stoi(rec.interval_));
	}
}
