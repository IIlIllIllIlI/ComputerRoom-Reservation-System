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
		date = "周一";
	}
	else if (date_ == "2") {
		date = "周二";
	}
	else if (date_ == "3") {
		date = "周三";
	}
	else if (date_ == "4") {
		date = "周四";
	}
	else if (date_ == "5") {
		date = "周五";
	}
	else {
		date = "错误";
	}

	if (interval_ == "1") {
		interval = "上午";
	}
	else if (interval_ == "2") {
		interval = "下午";
	}
	else {
		interval = "错误";
	}

	if (userType_ == "1") {
		userType = "同学";
	}
	else if (userType_ == "2") {
		userType = "老师";
	}
	else {
		userType = "错误";
	}

	if (status_ == "1") {
		status = "审核中";
	}
	else if (status_ == "2") {
		status = "已批准";
	}
	else if (status_ == "0") {
		status = "已取消";
	}
	else {
		status = "错误";
	}

	cout << date << "\t" << interval << "\t\t" << roomId_ << "号机房" <<
		"\t\t预约人: " << username_ << userType << "\t\t当前状态: " << status << endl;

}

void Record::printRecordPrivate()
{
	string date;
	string interval;
	string userType;
	string status;

	if (date_ == "1") {
		date = "周一";
	}
	else if (date_ == "2") {
		date = "周二";
	}
	else if (date_ == "3") {
		date = "周三";
	}
	else if (date_ == "4") {
		date = "周四";
	}
	else if (date_ == "5") {
		date = "周五";
	}
	else {
		date = "错误";
	}

	if (interval_ == "1") {
		interval = "上午";
	}
	else if (interval_ == "2") {
		interval = "下午";
	}
	else {
		interval = "错误";
	}

	if (userType_ == "1") {
		userType = "同学";
	}
	else if (userType_ == "2") {
		userType = "老师";
	}
	else {
		userType = "错误";
	}

	if (status_ == "1") {
		status = "审核中";
	}
	else if (status_ == "2") {
		status = "已批准";
	}
	else if (status_ == "0") {
		status = "已取消";
	}
	else {
		status = "错误";
	}

	cout << date << "\t" << interval << "\t\t" << roomId_ << "号机房" <<
		"\t\t用户身份: "  << userType << "\t\t当前状态: " << status << endl;
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
