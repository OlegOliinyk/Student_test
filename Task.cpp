#include "Task.h"
//using namespace std;

Task::Task(int taskID, int numberPoints, string task, pair<string, bool>* answers) {
	this->setTaskID(taskID);
	this->setNumberPoints(numberPoints);
	this->setTask(task);
	this->setAnswers(answers);
}

void Task::taskCls() {
	this->setNumberPoints(0);
	this->setTask("");
	pair<string, bool> answers[quantityAnswers]{ {"", 0}, {"", 0}, {"", 0}, {"",0} };
	this->setAnswers(answers);
}

void Task::setTaskID(int taskID) {
	this->taskID = taskID;
}

void Task::setNumberPoints(int numberPoints) {
	this->numberPoints = numberPoints;
}

void Task::setTask(string task) {
	this->task = task;
	//strcpy_s(this->task.c_str(), strlen(task.c_str()), task.c_str());
}

void Task::setAnswers(pair<string, bool>* answers) {
	for (int i = 0; i < quantityAnswers; i++) {
		this->answers[i].first = answers[i].first;
		//strcpy_s(this->answers[i].first, strlen(answers[i].first), answers[i].first);
		this->answers[i].second = answers[i].second;
	}
}

int Task::getTaskID() {
	return this->taskID;
}

int Task::getNumberPoints() {
	return this->numberPoints;
}

string Task::getTask() {
	return this->task;
}

pair<string, bool>* Task::getAnswers() {
	return this->answers;
}

void Task::inputConsolTask() {
	setlocale(LC_ALL, "Ukr");
	system("cls");
	this->taskCls();
	std::cout << "\nЗавдання №" << this->taskID;
	std::cout << "\nВведiть текст завдання\n";
	getline(cin, this->task);
	if (this->task.empty()) getline(cin, this->task);
	char correctID = ' ';
	for (int i = 0; i < quantityAnswers; i++) {
		std::cout << "\n\nВведiть " << i + 1 << " варiант вiдповiдi: ";
		getline(cin, this->answers[i].first);
		std::cout << "Вiдповiдь вiрна - '1', не вiрна - '0'";
		do {
			correctID = _getch();
		} while (correctID < 48 && correctID > 57);
		if (correctID == 48)
			this->answers[i].second = false;
		else
			this->answers[i].second = true;
	}
	std::cout << "\n\nВведiть кiлькiсть балiв за дане завдання: ";
	std::cin >> this->numberPoints;
	std::cout << "\n";
}

void Task::showConsolTask() {
	std::cout << "\nЗавдання № " << this->taskID << "\nКiлькiсть балiв за завдання " << this->numberPoints
		<< "\nТекст завдання:\n" << this->task;
	for (int i = 0; i < quantityAnswers; i++) {
		std::cout << "\nВiдповiдь " << i + 1 << " - " << this->answers[i].first << "   " << this->answers[i].second;
	}
}


bool Task::fSaveTask(string path) {//Сохранение счётчика нужно выделить в отдельный метод
	fstream fSave;
	string pathC = path;
	string str{ "" };
	int pos = pathC.find('.');
	if (pos != -1)
		pathC.erase(pos, 4);
	pathC += "Count";
	pathC += ".txt";
	fSave.open(pathC, ios::out);
	if (fSave.is_open()) {
		fSave.write((char*)&this->taskID, sizeof(int));
		fSave.close();
	}
	else {
		cout << "\n\nПомилка вiдкриття файлу " << pathC;
	}/////////////////////////////////////////////////////////////////////////////////////

	fSave.open(path, ios::out | ios::binary | ios::app);
	if (fSave.is_open()) {
		//fSave.write((char*)this->taskID, sizeof(this->taskID));
		//fSave.seekp(0, ios::beg);
		//fSave.write((char*) &this->taskID, sizeof(int));
		//if (this->taskID == 1) {
		//	fSave.seekp(1, ios::beg);
		//}
		//else {
		//	fSave.seekp(0, ios::end);
		//}

		str = this->task;
		replace(str.begin(), str.end(), ' ', '_');

		fSave << this->taskID << " " << this->numberPoints << " " << str;
		for (int i = 0; i < quantityAnswers; i++) {
			str = this->answers[i].first;
			replace(str.begin(), str.end(), ' ', '_');
			fSave << " " << str << " " << this->answers[i].second;
		}
		fSave << "\n";

		//fSave.write((char*)this, sizeof(Task));
		fSave.close();
		return true;
	}
	else {
		cout << "\n\nПомилка вiдкриття файлу " << path;
		return false;
	}
}


int Task::fReadCount(string path) {
	fstream fRead;
	int num = 0;
	int pos = path.find('.');
	if (pos != -1)
		path.erase(pos, 4);
	path += "Count";
	path += ".txt";

	fRead.open(path, ios::in);
	if (!fRead.is_open()) {
		return 0;
	}
	else {
		fRead.read((char*)&num, sizeof(int));
		fRead.close();
		return num;
	}
}

//bool Task::fReadAll(string path) {
//	fstream fRead;
//	char symb = ' ';
//	fRead.open(path, ios::in | ios::binary);
//	if (fRead.is_open()) {
//		cout << "\n";
//		while (!fRead.eof()) {
//			fRead >> symb;
//			cout << symb;
//		}
//		fRead.close();
//		return true;
//	}
//	else return false;
//}

//Метод вывода на экран задачи с указаным номером
bool Task::fReadTask(string path, int num) {
	fstream fRead(path, ios::in | ios::binary);
	int numb = 0;
	if (fRead.is_open()) {
		string str{ "" };
		for (int i = 0; i < num; i++) {
			fRead >> this->taskID >> this->numberPoints >> this->task;
			replace(this->task.begin(), this->task.end(), '_', ' ');
			for (int i = 0; i < quantityAnswers; i++) {
				fRead >> this->answers[i].first >> this->answers[i].second;
				replace(this->answers[i].first.begin(), this->answers[i].first.end(), '_', ' ');
			}

		}
		str = "";

		//fRead.seekg((num - 1) * sizeof(Task));
		//fRead.read((char*)this, sizeof(Task));
		fRead.close();
		return true;
	}
	else {
		cout << "\n\nПомилка вiдкриття файлу " << path;
		return false;
	}
	return false;
}

bool Task::fReadShowTasks(string path) {
	fstream fRead(path, ios::in | ios::binary);
	//int num = 0;
	if (fRead.is_open()) {
		while (!fRead.eof()) {
			fRead >> this->taskID >> this->numberPoints >> this->task;
			replace(this->task.begin(), this->task.end(), '_', ' ');
			for (int i = 0; i < quantityAnswers; i++) {
				fRead >> this->answers[i].first >> this->answers[i].second;
				replace(this->answers[i].first.begin(), this->answers[i].first.end(), '_', ' ');
			}
			//if (fRead.peek() == '\n')
			//	fRead.seekg(1, ios::cur);
			if (!fRead.eof())
				this->showConsolTask();

			//fRead.read((char*)this, sizeof(Task));
			//if (!fRead.eof())
			//	this->showConsolTask();
			//cout << "\n";
		}
		fRead.close();
		return true;
	}
	else {
		cout << "\n\nПомилка вiдкриття файлу " << path;
		return false;
	}
}



//#include "Task.h"
//#include <iostream>
//#include <fstream>
//#include <clocale>
//#include <conio.h>
//#include <stdlib.h>
//
//using namespace std;
//
//Task::Task(int taskID, int numberPoints, char* task, Answer* answers) {
//	this->setTaskID(taskID);
//	this->setNumberPoints(numberPoints);
//	this->setTask(task);
//	this->setAnswers(answers);
//}
//
//void Task::setTaskID(int taskID) {
//	this->taskID = taskID;
//}
//
//void Task::setNumberPoints(int numberPoints) {
//	this->numberPoints = numberPoints;
//}
//
//void Task::setTask(char* task) {
//	strcpy_s(this->task, strlen(task), task);
//}
//
//void Task::setAnswers(Answer* answers) {
//	for (int i = 0; i < quantityAnswers; i++) {
//		strcpy_s(this->answers[i].answer, strlen(answers[i].answer), answers[i].answer);
//		this->answers[i].correctID = answers[i].correctID;
//	}
//}
//
//int Task::getTaskID() {
//	return this->taskID;
//}
//
//int Task::getNumberPoints() {
//	return this->numberPoints;
//}
//
//char* Task::getTask() {
//	return this->task;
//}
//
//Answer* Task::getAnswers() {
//	return this->answers;
//}
//
//void Task::inputConsolTask() {
//	system("cls");
//	std::cout << "\nЗавдання №" << this->taskID;
//	std::cout << "\nВведiть текст завдання\n";
//	std::cin.getline(this->task, taskSize);
//	char correctID = ' ';
//	for (int i = 0; i < quantityAnswers; i++) {
//		std::cout << "\n\nВведiть " << i + 1 << " варiант вiдповiдi: ";
//		std::cin.getline(this->answers[i].answer, answerSize);
//		std::cout << "Вiдповiдь вiрна - '1', не вiрна - '0'";
//		do {
//			correctID = _getch();
//		} while (correctID < 48 && correctID > 57);
//		if (correctID == 48)
//			this->answers[i].correctID = false;
//		else
//			this->answers[i].correctID = true;
//	}
//	std::cout << "\n\nВведiть кiлькiсть балiв за дане завдання: ";
//	std::cin >> this->numberPoints;
//	std::cout << "\n";
//}
//
//void Task::showConsolTask() {
//	std::cout << "\nЗавдання № " << this->taskID << "\nКiлькiсть балiв за завдання " << this->numberPoints
//		<< "\nТекст завдання:\n" << this->task;
//	for (int i = 0; i < quantityAnswers; i++) {
//		std::cout << "\nВiдповiдь " << i + 1 << " - " << this->answers[i].answer << "   " << this->answers[i].correctID;
//	}
//}
//
//
//bool Task::fSaveTask(char* path) {
//	fstream fSave;
//	char pathC[pathSize + 5]{ "" };
//	//if (strchr(path, '.')) {
//	strncat_s(pathC, path, strlen(path) - 4);
//	//}
//	//else {
//	//	strncat_s(pathC, path, strlen(path));
//	//}
//	strncat_s(pathC, "Count", 5);
//	strncat_s(pathC, ".txt", 4);
//
//	fSave.open(pathC, ios::out);
//	if (fSave.is_open()) {
//		fSave.write((char*)&this->taskID, sizeof(int));
//		fSave.close();
//	}
//	else {
//		cout << "\n\nПомилка вiдкриття файлу TaskCount.txt";
//	}
//	fSave.open(path, ios::out | ios::binary | ios::app);
//	if (fSave.is_open()) {
//		//fSave.write((char*)this->taskID, sizeof(this->taskID));
//		//fSave.seekp(0, ios::beg);
//		//fSave.write((char*) &this->taskID, sizeof(int));
//		//if (this->taskID == 1) {
//		//	fSave.seekp(1, ios::beg);
//		//}
//		//else {
//		//	fSave.seekp(0, ios::end);
//		//}
//
//		//fSave.write((char*) &this->taskID, sizeof(int));
//
//		//fSave((char*)sizeof(Task), sizeof(int));
//		fSave.write((char*)this, sizeof(Task));
//		fSave.close();
//		return true;
//	}
//	else {
//		cout << "\n\nПомилка вiдкриття файлу " << path;
//		return false;
//	}
//}
//
//
//int Task::fReadNTask(char* path) {
//	fstream fRead;
//	int num = 0;
//
//	char pathC[pathSize + 5]{ "" };
//	//if (strchr(path, '.')) {
//	strncat_s(pathC, path, strlen(path) - 4);
//	//}
//	//else {
//	//	strncat_s(pathC, path, strlen(path));
//	//}
//	strncat_s(pathC, "Count", 5);
//	strncat_s(pathC, ".txt", 4);
//
//	fRead.open(pathC, ios::in);
//	if (!fRead.is_open()) {
//		return 0;
//	}
//	else {
//		fRead.read((char*)&num, sizeof(int));
//		fRead.close();
//		return num;
//	}
//}
//
//bool Task::fReadAll(char* path) {
//	fstream fRead;
//	char symb = ' ';
//	fRead.open(path, ios::in | ios::binary);
//	if (fRead.is_open()) {
//		cout << "\n";
//		while (!fRead.eof()) {
//			fRead >> symb;
//			cout << symb;
//		}
//		fRead.close();
//		return true;
//	}
//	else return false;
//}
//
//bool Task::fReadTask(char* path, int num) {
//	fstream fRead(path, ios::in | ios::binary);
//	int numb = 0;
//	if (fRead.is_open()) {
//		fRead.seekg((num - 1) * sizeof(Task));
//		fRead.read((char*)this, sizeof(Task));
//		fRead.close();
//		return true;
//	}
//	else {
//		cout << "\n\nПомилка вiдкриття файлу " << path;
//		return false;
//	}
//	return false;
//}
//
//bool Task::fReadShowTasks(char* path) {
//	fstream fRead(path, ios::in | ios::binary);
//	int num = 0;
//	if (fRead.is_open()) {
//		while (!fRead.eof()) {
//			fRead.read((char*)this, sizeof(Task));
//			if (!fRead.eof())
//				this->showConsolTask();
//			cout << "\n";
//		}
//		fRead.close();
//		return true;
//	}
//	else {
//		cout << "\n\nПомилка вiдкриття файлу " << path;
//		return false;
//	}
//}
