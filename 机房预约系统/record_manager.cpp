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
		ofs << "data:" << map_[i]->date_ << " ";
		ofs << "interval:" << map_[i]->interval_ << " ";
		ofs << "userType:" << map_[i]->userType_ << " ";
		ofs << "userId:" << map_[i]->userId_ << " ";
		ofs << "userName:" << map_[i]->username_ << " ";
		ofs << "roomId:" << map_[i]->roomId_ << " ";
		ofs << "status:" << map_[i]->status_ << endl;
	}

	ofs.close();
}

RecordManager::~RecordManager()
{
	for (map<int, Record*>::iterator it = map_.begin(); it != map_.end(); it++) {
		delete (*it).second;
	}
}

int RecordManager::getSize()
{
	return size_;
}

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

		map_.insert(make_pair(size_, r));
		size_++;
	}

	ifs.close();


	/*for (map<int, Record>::iterator it = map_.begin(); it != map_.end(); it++) {
		(*it).second.printRecord();
	}*/
}
