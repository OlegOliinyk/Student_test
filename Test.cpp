#include "Test.h"


//using namespace std;

string Test::getTestID() {
	return this->test_fields[TEST_ID];
}

void Test::inputConsolTest(string lecturerID) {
	system("cls");
	//ViewRecordList subject("sub.txt");
	//ViewRecordList group("gp.txt");
	this->test_fields[LECTURER_ID] = lecturerID;
	this->count = task.fReadCount(this->path) + 1;//�������� ���������� ������� � ����� �� ������� ������
	this->stringCls(0, 1, 167);
	cout << "��������� ����� �" << this->count;
	this->stringCls(0, 3, 167);
	cout << "����� �������� ��� ����� ����������� ���� (�����i�� i� ������): ";
	ViewRecordList recordListSub("sub.txt");
	this->test_fields[TEST_SUBJECT] = recordListSub.consolShowListRecord(4);
	//cin.ignore(1, '/n');
	//getline(cin, this->test_fields[TEST_SUBJECT], '\n');//����� �������� ����� ��� ������ ��������� �� ������ ��������� � �����
	this->stringCls(0, 3, 167);
	cout << "��� ��� ����� (�����i�� i� ������)?: ";
	ViewRecordList recordListGp("gp.txt");
	this->test_fields[TEST_FOR_GROUP] = recordListGp.consolShowListRecord(4);
	//cin >> this->test_fields[TEST_FOR_GROUP]; //����� ���������� ����� � ������������� ��� ������ ������ �� ���������� ������ � ����� �����
	//getline(cin, this->testForGroup);
	this->stringCls(0, 3, 167);
	cout << "���� �����?: ";
	cin.ignore(1, '/n');
	getline(cin, this->test_fields[TEST_NAME], '\n');
	this->test_fields[TEST_ID] = "test";
	if (this->count < 10) {
		this->test_fields[TEST_ID].push_back((char)(this->count + 48));
	}
	else {
		this->test_fields[TEST_ID].push_back((char)(this->count/10 + 48));
		this->test_fields[TEST_ID].push_back((char)(this->count%10 + 48));
	}
	std::cout << "\n";
}

void Test::showConsolTest() {
	cout << "\n\n���� ID" << this->test_fields[TEST_ID];
	cout << "\n� �������� " << this->test_fields[TEST_SUBJECT] << " ��� �������i� " << this->test_fields[TEST_FOR_GROUP] << " �����" << "\n���� ����� " << this->test_fields[TEST_NAME];
}

//������� ������ ������ �� ����� ��� ���������� �������������
int Test::showConsolTestListForLecturer(int posY, string lecturer) {
	cursorPosition(0, posY);
	cout << "������ ����i� ��������� " << lecturer << endl;
	cout << "\n�   �������   ��� �����   ���� �����\n\n";
	int size = this->test_list.size();
	for (int n = 0; n < size; n++) {
		cout << n + 1 << "   " << this->test_list[n][TEST_SUBJECT] 	<< "   " 
			<< this->test_list[n][TEST_FOR_GROUP] << "   " << this->test_list[n][TEST_NAME] << endl;
	}
	return size;
}

//������� ������ ������ �� ����� ��� ���������
void Test::showConsolTestListForStudent(int posY) {
	cursorPosition(0, posY);
	cout << "������ ����i� ��� ����� " << this->test_list[0][TEST_FOR_GROUP];
	int size = this->test_list.size();
	for (int n = 0; n < size; n++) {
		cout << n + 1 << "   " << this->test_list[n][TEST_SUBJECT] << "   " << this->test_list[n][TEST_NAME] << endl;
	}
}

void Test::showConsolTestList(int posY) {
	cursorPosition(0, posY);
	int size = this->test_list.size();
	for (int n = 0; n < size; n++) {
		cout << n + 1 << "   " << this->test_list[n][TEST_ID] << "   " << this->test_list[n][LECTURER_ID]
			<< "   " << this->test_list[n][TEST_SUBJECT] << "   " << this->test_list[n][TEST_FOR_GROUP]
			<< "   " << this->test_list[n][TEST_NAME] << endl;
	}
}

bool Test::fSaveTest() {//���������� �������� ����� �������� � ��������� �����
	fstream fSave;
	string pathC = this->path;
	string str{ "" };
	int pos = pathC.find('.');
	if (pos != -1)
		pathC.erase(pos, 4);
	pathC += "Count";
	pathC += ".txt";
	fSave.open(pathC, ios::out);
	if (fSave.is_open()) {
		fSave.write((char*)&this->count, sizeof(int));
		fSave.close();
	}
	else {
		cout << "\n\n������� �i������� ����� " << pathC;
	}/////////////////////////////////////////////////////////////////////////////////////

	fSave.open(this->path, ios::out | ios::binary | ios::app);
	if (fSave.is_open()) {
		str = this->test_fields[TEST_SUBJECT];
		replace(str.begin(), str.end(), ' ', '_');
		fSave << this->test_fields[TEST_ID] << " " << this->test_fields[LECTURER_ID] << " " << str << " " << this->test_fields[TEST_FOR_GROUP];
			str = this->test_fields[TEST_NAME];
			replace(str.begin(), str.end(), ' ', '_');
			fSave << " " << str << "\n";
		fSave.close();
		return true;
	}
	else {
		cout << "\n\n������� �i������� ����� " << this->path;
		return false;
	}
}

//����� �������������� � ���� ������ ������. ������������ ��� �������� �����
bool Test::fSaveTestList() {
	fstream fSave;
	string str{ "" };
	int size = test_list.size();
	fSave.open(this->path, ios::out | ios::binary);
	if (fSave.is_open()) {
		for (int i = 0; i < size; i++) {
			str = this->test_list[i][TEST_SUBJECT];
			replace(str.begin(), str.end(), ' ', '_');
			fSave << this->test_list[i][TEST_ID] << " " << this->test_list[i][LECTURER_ID] << " " << str << " " << this->test_list[i][TEST_FOR_GROUP];
			str = this->test_list[i][TEST_NAME];
			replace(str.begin(), str.end(), ' ', '_');
			fSave << " " << str << "\n";
		}
		fSave.close();
		return true;
	}
	else {
		cout << "\n\n������� �i������� ����� " << this->path;
		return false;
	}
	return false;
}

//����� ��������� ������ �� ����� � ��������� ������ ������ (� vector test_list) ��� ��������� ������ (TEST_FOR_GROUP, ������� ��� �����)
//���� ��� ���������� id ������������� (LECTURER_ID, ������� �������� ��� �����) 
//���� ������������ ���� ������ �� ����� � vector test_list
bool Test::fReadTestListSelectively(TEST_FIELDS select = TEST_ID, string id = "") {
	fstream fRead(this->path, ios::in | ios::binary);
	if (fRead.is_open()) {
		while (!fRead.eof()) {
			fRead >> this->test_fields[TEST_ID] >> this->test_fields[LECTURER_ID] >> this->test_fields[TEST_SUBJECT] >> this->test_fields[TEST_FOR_GROUP] >> this->test_fields[TEST_NAME];

			replace(this->test_fields[TEST_SUBJECT].begin(), this->test_fields[TEST_SUBJECT].end(), '_', ' ');
			replace(this->test_fields[TEST_NAME].begin(), this->test_fields[TEST_NAME].end(), '_', ' ');

			if (!fRead.eof())
				switch (select) {
				case LECTURER_ID: {
					if(this->test_fields[LECTURER_ID] == id)
						this->test_list.push_back(this->test_fields);
					break;
				}
				case TEST_FOR_GROUP: {
					if (this->test_fields[TEST_FOR_GROUP] == id)
						this->test_list.push_back(this->test_fields);
					break;
				}
				default: {
					this->test_list.push_back(this->test_fields);
				}
				}
		}
		fRead.close();
		return true;
	}
	else {
		cout << "\n\n������� �i������� ����� " << this->path;
		return false;
	}
}

bool Test::fReadShowTests(string path) {

	return false;
}

void Test::clearsTestList() {
	this->test_list.clear();
}

string Test::editTest(int num) {
	this->test_fields[TEST_ID] = this->test_list[num][TEST_ID];
	this->test_fields[LECTURER_ID] = this->test_list[num][LECTURER_ID];
	this->test_fields[TEST_SUBJECT] = this->test_list[num][TEST_SUBJECT];
	this->test_fields[TEST_FOR_GROUP] = this->test_list[num][TEST_FOR_GROUP];
	this->test_fields[TEST_NAME] = this->test_list[num][TEST_NAME];
	string tempTestID = this->test_fields[TEST_ID];
	system("cls");
	this->cursorPosition(0, 1);
	cout << "����������� �����";
	this->cursorPosition(0, 3);
	cout << "��� ��i�� ����� ����� �����i��� ������ (�������) ���i �������� �� ������ �����i� ��� '0' - ��� ���";
	this->cursorPosition(0, 5);
	cout << "������� ����� " << this->test_fields[TEST_SUBJECT];
	//cin >> temp;
	bool tempBool = false;
	ViewRecordList recordListSub("sub.txt");
	string tempTestSubject = recordListSub.consolShowListRecord(7);
	if (tempTestSubject != "0") {
		tempBool = true;
	}
	this->stringCls(0, 5, 167);
	cout << "���� ��� �����: " << this->test_fields[TEST_FOR_GROUP];
	ViewRecordList recordListGp("gp.txt");
	string tempTestForGroup = recordListGp.consolShowListRecord(7);
	if (tempTestForGroup != "0") {
		tempBool = true;
	}
	this->stringCls(0, 5, 167);
	cout << "���� �����: " << this->test_fields[TEST_NAME] << "\n";
	cin.ignore(1, '/n');
	string tempTestName = "";
	getline(cin, tempTestName, '\n');
	if (tempTestName != "0") {
		tempBool = true;
	}
	if (tempBool == true) { //���� ���� ���������
		this->clearsTestList();
		this->fReadTestListSelectively();

		//int size = test_list.size();
		//for (int i = 0; i < size; i++);
		int n = 0;
		while (tempTestID != this->test_list[n][TEST_ID]) {
			n++;
		}
		if (tempTestSubject != "0") {
			this->test_list[n][TEST_SUBJECT] = tempTestSubject;
		}
		if (tempTestForGroup != "0") {
			this->test_list[n][TEST_FOR_GROUP] = tempTestForGroup;
		}
		if (tempTestName != "0") {
			this->test_list[n][TEST_NAME] = tempTestName;
		}

		for (int i = 0; i < 5; i++) {
			this->test_fields[i] = this->test_list[n][i];
		}
		this->fSaveTestList();
	}
	return tempTestID;
}

//string Test::testIdFromTestList(int num) {
//	return this->test_list[num][TEST_ID];
//}

//������� ��� ������ � ��������� ������������ �����. ��������� ������ �� ������ view,
//��� ��������� � ������� main, � ������ �� ������ test ��������� � ������� lecturerTest
void Test::lecturerTestTask(string path, View& view) {
	//string path{ "Task.txt" };
	char symb = ' ';
	int num = 0;

	do {
		symb = view.lecturerTaskMenu(this->test_fields[TEST_NAME]);
		switch (symb) {
		case 49: {
			this->task.setTaskID(this->task.fReadCount(path) + 1);
			this->task.inputConsolTask();
			system("cls");
			this->task.showConsolTask();
			this->task.fSaveTask(path);
			//cout << "\n\n";
			//task.fReadAll(path);
			//cout << "\n\n";
			break;
		}
		case 50: {
			system("cls");
			this->task.fReadShowTasks(path);
			Sleep(2000);
			break;
		}
		case 51: {
			system("cls");

			for (;;) {
				cout << "\n����i�� ����� ��������, ��� �����i��� ������� �� �����: ";
				cin >> num;
				if (num > this->task.fReadCount(path)) {
					cout << "\n�������, �i���i��� ������� ������ " << num;
				}
				else break;
			}
			this->task.fReadTask(path, num);
			this->task.showConsolTask();
			Sleep(2000);
			break;
		}
		default: {}
		}

	} while (symb != '0');
}
