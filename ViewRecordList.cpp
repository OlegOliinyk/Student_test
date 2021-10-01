#include "ViewRecordList.h"
#include <iostream>
#include <Windows.h>


void ViewRecordList::consolInputRecord(char id) {
	//system("cls");
	string rec{ "" };
	this->stringCls(0, 5, 167);
	switch (id) {
	case 'G': cout << "ÄÎÄÀÂÀÍÍß ÍÎÂÈÕ ÃÐÓÏ ÑÒÓÄÅÍÒIÂ Â ÑÏÈÑÎÊ ÃÐÓÏ ÄËß ÒÅÑÒÓÂÀÍÍß"; break;
	case 'P': cout << "ÄÎÄÀÂÀÍÍß ÍÎÂÈÕ ÏÐÅÄÌÅÒIÂ Â ÑÏÈÑÎÊ ÄËß ÒÅÑÒÓÂÀÍÍß"; break;
	}
	for (;;) {
		this->stringCls(0, 6, 167);
		switch (id) {
		case 'G': cout << "Ââåäiòü íàçâó íîâî¿ ãðóïè àáî '0' äëÿ çàêií÷åííÿ äîäàâàííÿ ãðóï â ñïèñîê:\n"; break;
		case 'P': cout << "Ââåäiòü íàçâó íîâîãî ïðåäìåòó àáî '0' äëÿ çàêií÷åííÿ äîäàâàííÿ ïðåäìåòiâ â ñïèñîê:\n"; break;
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
			case 'G': cout << "Òàêà ãðóïà âæå iñíóº â ñïèñêó!!!"; break;
			case 'P': cout << "Òàêèé ïðåäìåò âæå iñíóº â ñïèñêó!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
		else {
			this->addRecord(rec);
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "Ãðóïà äîäàíà äî ñïèñêó!!!"; break;
			case 'P': cout << "Ïðåäìåò äîäàíî äî ñïèñêó!!!"; break;
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
	case 'G': cout << "ÂÈÄÀËÅÍÍß ÃÐÓÏÈ ÑÒÓÄÅÍÒIÂ IÇ ÑÏÈÑÎÊÓ ÃÐÓÏ ÄËß ÒÅÑÒÓÂÀÍÍß"; break;
	case 'P': cout << "ÂÈÄÀËÅÍÍß ÏÐÅÄÌÅÒÓ IÇ ÑÏÈÑÎÊÓ ÄËß ÒÅÑÒÓÂÀÍÍß"; break;
	}
	for (;;) {
		this->stringCls(0, 6, 167);
		switch (id) {
		case 'G': cout << "Ââåäiòü íàçâó ãðóïè äëÿ âèäàëåííÿ iç ñïèñêó àáî '0' äëÿ çàêií÷åííÿ âèäàëåííÿ:\n"; break;
		case 'P': cout << "Ââåäiòü íàçâó ïðåäìåòó äëÿ âèäàëåííÿ iç ñïèñêó àáî '0' äëÿ çàêií÷åííÿ âèäàëåííÿ:\n"; break;
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
			case 'G': cout << "Òàêî¿ ãðóïè íå ìàº â ñïèñêó!!!"; break;
			case 'P': cout << "Òàêîãî ïðåäìåòó íå ìàº â ñïèñêó!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
		else {
			this->delRecord(rec);
			this->stringCls(0, 7, 167);
			this->stringCls(0, 6, 167);
			switch (id) {
			case 'G': cout << "Ãðóïà âèäàëåíà iç ñïèñêó!!!"; break;
			case 'P': cout << "Ïðåäìåò âèäàëåíèé iç ñïèñêó!!!"; break;
			}
			Sleep(1500);
			this->stringCls(0, 6, 167);
		}
	}
}

void ViewRecordList::consolShowListRecord(char id) {
	this->stringCls(0, 9, 167);
		switch (id) {
		case 'G': cout << "ÑÏÈÑÎÊ ÃÐÓÏ ÑÒÓÄÅÍÒIÂ ÄËß ÒÅÑÒÓÂÀÍÍß"; break;
		case 'P': cout << "ÑÏÈÑÎÊ ÏÐÅÄÌÅÒIÂ ÒÅÑÒÓÂÀÍÍß"; break;
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
			cout << "Ââåäåíå ÷èñëî íå âõîäèòü â ïðîì³æîê âèáîðó";
			Sleep(2000);
			this->stringCls(0, pos, 167);
		}
	}
}