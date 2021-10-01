#include "RecordList.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool RecordList::fReadListRecords() {
    fstream fListRecords(this->path, ios::in | ios::binary);
    if (fListRecords.is_open()) {
        string record;
        auto it = listRecords.begin();
        while (!fListRecords.eof()) {
            fListRecords >> record;
            replace(record.begin(), record.end(), '_', ' ');
            it = listRecords.find(record);
            if (it == listRecords.end()) {
                this->listRecords.emplace(record);
            }
        }
        fListRecords.close();
        return true;
    }
    return false;
}

bool RecordList::fWriteListRecords() {
    fstream fListRecords(this->path, ios::out | ios::binary);
    if (fListRecords.is_open()) {
        string record;
        for (auto it = this->listRecords.begin(); it != this->listRecords.end(); ++it) {
            record = *(it);
            replace(record.begin(), record.end(), ' ', '_');
            if (it == this->listRecords.begin())
                fListRecords << record;
            else fListRecords << " " << record;
            //fListRecords << "\n";
        }
        fListRecords.close();
        return true;
    }
    return false;
}

void RecordList::setPath(string &path) {
    this->path = path;
}

//void recordListInFile::setRecord(string record) {
//	this->record = record;
//}

string RecordList::getPath() {
    return this->path;
}

//string recordListInFile::getRecord() {
//	return this->record;
//}

bool RecordList::addRecord(string &record) {
    if (this->listRecords.empty()) {
        this->listRecords.emplace(record);
        return true;
    }
    else {
        auto it = this->listRecords.find(record);
        if (it == this->listRecords.end()) {
            this->listRecords.emplace(record);
            return true;
        }
    }
    return false;
}

bool RecordList::delRecord(string &record) {
    if (this->listRecords.empty()) {
        return false;
    }
    else {
        auto it = this->listRecords.find(record);
        if (it == this->listRecords.end()) {
            return false;
        }
        else {
            this->listRecords.erase(it);
            return true;
        }
    }
}

bool RecordList::searchRecord(string &record) {
    if (this->listRecords.empty()) {
        return false;
    }
    else {
        auto it = this->listRecords.find(record);
        if (it == this->listRecords.end()) {
            return false;
        }
        else {
            return true;
        }
    }

    return false;
}

bool RecordList::clearListRecord() {
    this->listRecords.clear();
    if (this->listRecords.empty())
        return true;
    return false;
}

int RecordList::sizeListRecords() {
    return this->listRecords.size();
}


