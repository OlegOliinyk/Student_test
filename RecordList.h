#pragma once
#include <string>
#include <set>
#include <vector>
#include <conio.h>

using namespace std;

class RecordList {
protected:
	string path;
	set<string> listRecords;

	bool fReadListRecords();
	bool fWriteListRecords();
public:
	RecordList(string path) { this->setPath(path); this->fReadListRecords(); }
	~RecordList() { this->fWriteListRecords(); }

	void setPath(string &path);
	string getPath();
	bool addRecord(string &record);
	bool delRecord(string &record);
	bool searchRecord(string &record);
	bool clearListRecord();
	int sizeListRecords();
};


