#include "ViewRecordList.h"
#include <iostream>
#include <Windows.h>


void ViewRecordList::consolInputRecord(char id) {
	//system("cls");
	string rec{ "" };
	this->stringCls(0, 5, 167);
	switch (id) {
	case 'G': cout << "��������� ����� ���� �������I� � ������ ���� ��� ����������"; break;
	case 'P': cout << "��������� ����� �������I� � ������ ��� ����������"; break;
	}
	for (;;) {
		this->stringCls(0, 6, 167);
		switch (id) {
		case 'G': cout << "����i�� ����� ���� ����� ��� '0' ��� ���i������ ��������� ���� � ������:\n"; break;
		case 'P': cout << "����i�� ����� ������ �������� ��� '0' ��� ���i������ ��������� �������i� � ������:\n"; break;
		}
		getline(cin, rec);
		if (rec == "0") {
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			this->stringCls(0, 5, 167);
			return;
		}
		if (this->searchRecord(rec)) {
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "���� ����� ��� i��� � ������!!!"; break;
			case 'P': cout << "����� ������� ��� i��� � ������!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
		else {
			this->addRecord(rec);
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "����� ������ �� ������!!!"; break;
			case 'P': cout << "������� ������ �� ������!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
	}
}

void ViewRecordList::consolDelRecord(char id) {
	//system("cls");
	string rec{ "" };
	this->stringCls(0, 5, 167);
	switch (id) {
	case 'G': cout << "��������� ����� �������I� I� ������� ���� ��� ����������"; break;
	case 'P': cout << "��������� �������� I� ������� ��� ����������"; break;
	}
	for (;;) {
		this->stringCls(0, 6, 167);
		switch (id) {
		case 'G': cout << "����i�� ����� ����� ��� ��������� i� ������ ��� '0' ��� ���i������ ���������:\n"; break;
		case 'P': cout << "����i�� ����� �������� ��� ��������� i� ������ ��� '0' ��� ���i������ ���������:\n"; break;
		}
		getline(cin, rec);
		if (rec == "0") {
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			this->stringCls(0, 5, 167);
			return;
		}
		if (!this->searchRecord(rec)) {
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "���� ����� �� �� � ������!!!"; break;
			case 'P': cout << "������ �������� �� �� � ������!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
		else {
			this->delRecord(rec);
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "����� �������� i� ������!!!"; break;
			case 'P': cout << "������� ��������� i� ������!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
	}
}

void ViewRecordList::consolShowListRecord(char id) {
	this->stringCls(0, 9, 167);
		switch (id) {
		case 'G': cout << "������ ���� �������I� ��� ����������"; break;
		case 'P': cout << "������ �������I� ����������"; break;
		}
	int n = 0;
	this->stringCls(0, 11, 167);
	for (auto it = this->listRecords.begin(); it != this->listRecords.end(); ++it, n++) {
		cout << *(it) << "   ";
		if (n == 11) { cout << "\n"; n = 0; }
	}
}

string ViewRecordList::consolShowListRecord(int pos) {
	int n = 0, i = 0;
	this->stringCls(0, pos + 2, 167);
	vector <string> ListRecords(this->listRecords.begin(), this->listRecords.end());
	for (auto it = ListRecords.begin(); it != ListRecords.end(); ++it, n++, i++) {
		cout << i + 1 << " " << *(it) << "   ";
		if (n == 10) { n = 0; }
	}
	int num = 0;
	this->stringCls(0, pos, 167);
	for (;;) {
		cin >> num;
		if (num >= 0 && num <= i) {
			this->stringCls(0, pos, 167);
			this->stringCls(0, pos + 2, 167);
			if (num != 0)
				return ListRecords[num - 1];
			else return "0";
		}
		else {
			this->stringCls(0, pos, 167);
			cout << "������� ����� �� ������� � ������� ������";
			Sleep(2000);
			this->stringCls(0, pos, 167);
		}
	}
}