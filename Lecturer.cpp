#include "Lecturer.h"

void Lecturer::inputUserData() {
    cout << "\n������: ";
    cin >> this->user[PASSWORD];
    //getline (cin, this->user[PASSWORD]);
    cout << "\n����i�� ���i�i�: ";
    cin >> this->user[SURNAME];
    //getline(cin, this->user[SURNAME]);
    cout << "\n���: ";
    cin >> this->user[NAME];
    //getline(cin, this->user[NAME]);
    cout << "\n�� �������i: ";
    cin >> this->user[PATRONYMIC];
    //getline(cin, this->user[PATRONYMIC]);
    cout << "\n���������: ";
    cin.ignore(1, '\n');
    getline(cin, user[FACULTY], '\n');
    cout << "\n�������: ";
    getline(cin, user[SUBJECT], '\n');
}

void Lecturer::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "����������� ������������";
    for (;;) {
        cout << "\n\n����i�� ���i� ������ �����������: ";
        cin >> this->login;
        if (this->login == "0") break;
        //cin.ignore(1, '\n');
        //getline(cin, this->login);
        if (this->listUsers.size() == 0 || this->listUsers.count(this->login) == 0) {
            this->inputUserData();
            this->listUsers.emplace(this->login, this->user);
            break;
        }
        else {
            cout << "\n����� ���� ��� ����!!!";
        }
    }
    this->fWriteListUsers();
}

void Lecturer::consolShowListUsers() {

}

////������� ��� ������ � ��������� ������������ �����. ��������� ������ �� ������ view,
////��� ��������� � ������� main, � ������ �� ������ test ��������� � ������� lecturerTest
//void Lecturer::lecturerTestTask(Test& test, View& view) {
//	string path{ "Task.txt" };
//	char symb = ' ';
//	int num = 0;
//
//	do {
//		symb = view.lecturerTaskMenu();
//		switch (symb) {
//		case 49: {
//			test.setTaskID(test.fReadCount(path) + 1);
//			test.inputConsolTask();
//			system("cls");
//			test.showConsolTask();
//			test.fSaveTask(path);
//			//cout << "\n\n";
//			//task.fReadAll(path);
//			//cout << "\n\n";
//			break;
//		}
//		case 50: {
//			system("cls");
//			test.fReadShowTasks(path);
//			Sleep(2000);
//			break;
//		}
//		case 51: {
//			system("cls");
//
//			for (;;) {
//				cout << "\n����i�� ����� ��������, ��� �����i��� ������� �� �����: ";
//				cin >> num;
//				if (num > test.fReadCount(path)) {
//					cout << "\n�������, �i���i��� ������� ������ " << num;
//				}
//				else break;
//			}
//			test.fReadTask(path, num);
//			test.showConsolTask();
//			Sleep(2000);
//			break;
//		}
//		default: {}
//		}
//
//	} while (symb != '0');
//}

//����� ��� ������ ������������� � ������. ��������� ������ �� ������ view,
//��� ��������� � ������� main
void Lecturer::lecturerTest(View& view) {
	//Test test;
	char symb = ' ';
	do {
		symb = view.lecturerTestMenu();
		switch (symb) {
		case 49: { //�������
			//cout << "\n�������� �����";
			//Sleep(1000);
            this->test.inputConsolTest(this->login);
            this->test.fSaveTest();
			this->test.lecturerTestTask(this->test.getTestID() + ".txt", view);
			break;
		}
		case 50: { //�������������
            system("cls");
            this->cursorPosition(0, 1);
            cout << "����������� ����I�";
            this->cursorPosition(0, 3);
            cout << "�����i�� ���� ��� �����������";
            this->test.clearsTestList();
            this->test.fReadTestListSelectively(LECTURER_ID, this->getLogin());
            int size = this->test.showConsolTestListForLecturer(7, this->getSurname() + " " + this->getName() + " " + this->getPatronymic());
            this->cursorPosition(0, 5);
            int num = 0;
            for (;;) {
                cin >> num;
                if (num > 0 && num <= size) {
                    break;
                }
                this->stringCls(0, 5, 5);
                cout << "������� �������� �� ������� � ������� ����i���!!!";
                Sleep(2000);
                this->stringCls(0, 5, 167);
            }
            string tempTestID = this->test.editTest(num - 1);
            this->test.lecturerTestTask(tempTestID + ".txt", view);
            //if (_getch()) break;
            //cout << "\n�������������� �����";
			//Sleep(1000);
			break;
		}
		case 51: { //�������
            this->test.clearsTestList();
            this->test.fReadTestListSelectively(LECTURER_ID, this->getLogin());
            int size = this->test.showConsolTestListForLecturer(7, this->getSurname() + " " + this->getName() + " " + this->getPatronymic());

			//cout << "\n�������� �����";
			//Sleep(1000);
			break;
		}
		default: {}
		}

	} while (symb != '0');

}