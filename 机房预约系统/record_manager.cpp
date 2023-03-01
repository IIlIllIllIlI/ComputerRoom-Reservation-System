#include "record_manager.h"

RecordManager::RecordManager()
{
	size_ = 0;
	readFile();
}

void RecordManager::writeFile()
{
	if (size_ == 0) {
		return;
	}

	ofstream ofs(RECORD_FILE, ios::out | ios::trunc);
	for (int i = 0; i < size_; i++)
	{
		ofs << "data:" << vec_[i]->date_ << " ";
		ofs << "interval:" << vec_[i]->interval_ << " ";
		ofs << "userType:" << vec_[i]->userType_ << " ";
		ofs << "userId:" << vec_[i]->userId_ << " ";
		ofs << "userName:" << vec_[i]->username_ << " ";
		ofs << "roomId:" << vec_[i]->roomId_ << " ";
		ofs << "status:" << vec_[i]->status_ << endl;
	}

	ofs.close();
}

RecordManager::~RecordManager()
{
	for (vector<Record*>::iterator it = vec_.begin(); it != vec_.end(); it++) {
		delete (*it);
	}
}

int RecordManager::getSize()
{
	return size_;
}

//void RecordManager::addRecord(string date, string interval, string userType, string userId, string username, string roomId, string status)
//{
//	Record* r = new Record(date, interval, userType, userId, username, roomId, status);
//	vec_.push_back(r);
//	size_++;
//	writeFile();
//}

string RecordManager::getVal(string str)
{
	int pos = str.find(":");
	if (pos != -1) {
		return str.substr(pos + 1, str.size() - 1 - pos);
	}
	return "";
}

void RecordManager::readFile()
{
	ifstream ifs;
	ifs.open(RECORD_FILE, ios::in);

	string date;
	string interval;
	string userType;
	string userId;
	string username;
	string roomId;
	string status;

	while (ifs >> date && ifs >> interval && ifs >> userType && ifs >> userId
		&& ifs >> username && ifs >> roomId && ifs >> status)
	{
		Record* r = new Record(getVal(date), getVal(interval), getVal(userType),
			getVal(userId), getVal(username), getVal(roomId), getVal(status));

		vec_.push_back(r);
		size_++;
	}

	ifs.close();

	sortRecord();
	/*for (map<int, Record>::iterator it = map_.begin(); it != map_.end(); it++) {
		(*it).second.printRecord();
	}*/
}

void RecordManager::sortRecord()
{
	sort(vec_.begin(), vec_.end(), [](const Record* lhs, const Record* rhs)
		{
			return (*lhs < *rhs);
		});
}