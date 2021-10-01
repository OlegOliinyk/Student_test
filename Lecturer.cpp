#include "Lecturer.h"

void Lecturer::inputUserData() {
    cout << "\nПароль: ";
    cin >> this->user[PASSWORD];
    //getline (cin, this->user[PASSWORD]);
    cout << "\nВведiть Фамiлiю: ";
    cin >> this->user[SURNAME];
    //getline(cin, this->user[SURNAME]);
    cout << "\nИмя: ";
    cin >> this->user[NAME];
    //getline(cin, this->user[NAME]);
    cout << "\nПо батьковi: ";
    cin >> this->user[PATRONYMIC];
    //getline(cin, this->user[PATRONYMIC]);
    cout << "\nФакультет: ";
    cin.ignore(1, '\n');
    getline(cin, user[FACULTY], '\n');
    cout << "\nПредмет: ";
    getline(cin, user[SUBJECT], '\n');
}

void Lecturer::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "Регистрация пользователя";
    for (;;) {
        cout << "\n\nВведiть логiн нового користувача: ";
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
            cout << "\nДаний логін вже існує!!!";
        }
    }
    this->fWriteListUsers();
}

void Lecturer::consolShowListUsers() {

}

////Функция для работы с заданиями создаваемого теста. Принимает ссылку на объект view,
////уже созданный в функции main, и ссылку на объект test созданный в функции lecturerTest
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
//				cout << "\nВведiть номер завдання, яке необхiдно вивести на екран: ";
//				cin >> num;
//				if (num > test.fReadCount(path)) {
//					cout << "\nПомилка, кiлькiсть завдань меньше " << num;
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

//Метод для работы Преподавателя с Тестом. Принимает ссылку на объект view,
//уже созданный в функции main
void Lecturer::lecturerTest(View& view) {
	//Test test;
	char symb = ' ';
	do {
		symb = view.lecturerTestMenu();
		switch (symb) {
		case 49: { //Создать
			//cout << "\nСоздание теста";
			//Sleep(1000);
            this->test.inputConsolTest(this->login);
            this->test.fSaveTest();
			this->test.lecturerTestTask(this->test.getTestID() + ".txt", view);
			break;
		}
		case 50: { //Редактировать
            system("cls");
            this->cursorPosition(0, 1);
            cout << "РЕДАГУВАННЯ ТЕСТIВ";
            this->cursorPosition(0, 3);
            cout << "Виберiть тест для редагування";
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
                cout << "Введене значення не входить в заданий промiжок!!!";
                Sleep(2000);
                this->stringCls(0, 5, 167);
            }
            string tempTestID = this->test.editTest(num - 1);
            this->test.lecturerTestTask(tempTestID + ".txt", view);
            //if (_getch()) break;
            //cout << "\nРедактирование теста";
			//Sleep(1000);
			break;
		}
		case 51: { //Удалить
            this->test.clearsTestList();
            this->test.fReadTestListSelectively(LECTURER_ID, this->getLogin());
            int size = this->test.showConsolTestListForLecturer(7, this->getSurname() + " " + this->getName() + " " + this->getPatronymic());

			//cout << "\nУдаление теста";
			//Sleep(1000);
			break;
		}
		default: {}
		}

	} while (symb != '0');

}