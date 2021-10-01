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
	this->count = task.fReadCount(this->path) + 1;//Получаем количество записей в файле со списком тестов
	this->stringCls(0, 1, 167);
	cout << "Створення тесту №" << this->count;
	this->stringCls(0, 3, 167);
	cout << "Назва предмету для якого створюється тест (виберiть iз списку): ";
	ViewRecordList recordListSub("sub.txt");
	this->test_fields[TEST_SUBJECT] = recordListSub.consolShowListRecord(4);
	//cin.ignore(1, '/n');
	//getline(cin, this->test_fields[TEST_SUBJECT], '\n');//Нужно добавить метод для выбора предметов из списка предметов в файле
	this->stringCls(0, 3, 167);
	cout << "Для якої групи (виберiть iз списку)?: ";
	ViewRecordList recordListGp("gp.txt");
	this->test_fields[TEST_FOR_GROUP] = recordListGp.consolShowListRecord(4);
	//cin >> this->test_fields[TEST_FOR_GROUP]; //Нужно доработать метод в представлении для выбора группы из имеющегося списка в файле групп
	//getline(cin, this->testForGroup);
	this->stringCls(0, 3, 167);
	cout << "Тема тесту?: ";
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
	cout << "\n\nТест ID" << this->test_fields[TEST_ID];
	cout << "\nЗ предмету " << this->test_fields[TEST_SUBJECT] << " для студентiв " << this->test_fields[TEST_FOR_GROUP] << " групи" << "\nТема тесту " << this->test_fields[TEST_NAME];
}

//Выводит список тестов на экран для указанного преподавателя
int Test::showConsolTestListForLecturer(int posY, string lecturer) {
	cursorPosition(0, posY);
	cout << "Список тестiв викладача " << lecturer << endl;
	cout << "\n№   Предмет   Для Групи   Тема тесту\n\n";
	int size = this->test_list.size();
	for (int n = 0; n < size; n++) {
		cout << n + 1 << "   " << this->test_list[n][TEST_SUBJECT] 	<< "   " 
			<< this->test_list[n][TEST_FOR_GROUP] << "   " << this->test_list[n][TEST_NAME] << endl;
	}
	return size;
}

//Выводит список тестов на экран для студентов
void Test::showConsolTestListForStudent(int posY) {
	cursorPosition(0, posY);
	cout << "Список тестiв для групи " << this->test_list[0][TEST_FOR_GROUP];
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

bool Test::fSaveTest() {//Сохранение счётчика нужно выделить в отдельный метод
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
		cout << "\n\nПомилка вiдкриття файлу " << pathC;
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
		cout << "\n\nПомилка вiдкриття файлу " << this->path;
		return false;
	}
}

//Метод перезаписывает в файл список тестов. Используется при удалении теста
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
		cout << "\n\nПомилка вiдкриття файлу " << this->path;
		return false;
	}
	return false;
}

//Метод выполняет чтение из файла и формирует список тестов (в vector test_list) для указанной группы (TEST_FOR_GROUP, здающей эти тесты)
//либо для указанного id преподавателя (LECTURER_ID, который создавал эти тесты) 
//либо переписывает весь список из файла в vector test_list
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
		cout << "\n\nПомилка вiдкриття файлу " << this->path;
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
	cout << "РЕДАГУВАННЯ ТЕСТУ";
	this->cursorPosition(0, 3);
	cout << "Для змiни даних тесту необхiдно ввести (вибрати) новi значення по кожный позицiї або '0' - без змін";
	this->cursorPosition(0, 5);
	cout << "Предмет тесту " << this->test_fields[TEST_SUBJECT];
	//cin >> temp;
	bool tempBool = false;
	ViewRecordList recordListSub("sub.txt");
	string tempTestSubject = recordListSub.consolShowListRecord(7);
	if (tempTestSubject != "0") {
		tempBool = true;
	}
	this->stringCls(0, 5, 167);
	cout << "Тест для групи: " << this->test_fields[TEST_FOR_GROUP];
	ViewRecordList recordListGp("gp.txt");
	string tempTestForGroup = recordListGp.consolShowListRecord(7);
	if (tempTestForGroup != "0") {
		tempBool = true;
	}
	this->stringCls(0, 5, 167);
	cout << "Тема тесту: " << this->test_fields[TEST_NAME] << "\n";
	cin.ignore(1, '/n');
	string tempTestName = "";
	getline(cin, tempTestName, '\n');
	if (tempTestName != "0") {
		tempBool = true;
	}
	if (tempBool == true) { //Если были изменения
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

//Функция для работы с заданиями создаваемого теста. Принимает ссылку на объект view,
//уже созданный в функции main, и ссылку на объект test созданный в функции lecturerTest
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
				cout << "\nВведiть номер завдання, яке необхiдно вивести на екран: ";
				cin >> num;
				if (num > this->task.fReadCount(path)) {
					cout << "\nПомилка, кiлькiсть завдань меньше " << num;
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
