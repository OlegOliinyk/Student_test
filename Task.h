#pragma once
#include <fstream>
#include <iostream>
#include <clocale>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

constexpr auto quantityAnswers = 4; //Количество ответов
//constexpr auto taskSize = 501; //Количество символов в задании
//constexpr auto pathSize = 51; //Количество символов в имени файла

class Task {
protected:
	int taskID{ 0 }; //Номер задания
	int numberPoints{ 0 }; //Количество балов за вопрос
	string task{ "" }; //Задание (вопрос)
	pair<string, bool> answers[quantityAnswers]{ {"", 0}, {"", 0}, {"", 0}, {"", 0} }; //Массив вариантов ответа
	void taskCls();

public:
	Task() {}
	Task(int taskID, int numberPoints, string task, pair<string, bool>* answers);
	~Task() {}
	void setTaskID(int taskID);
	void setNumberPoints(int numberPoints);
	void setTask(string task);
	void setAnswers(pair<string, bool>* answers);
	int getTaskID();
	int getNumberPoints();
	string getTask();
	pair<string, bool>* getAnswers();
	void inputConsolTask();
	void showConsolTask();
	bool fSaveTask(string path);
	int fReadCount(string path);
	//int fReadNTask(string path);

	//bool fReadAll(string path);
	bool fReadTask(string path, int num);
	bool fReadShowTasks(string path);
};


//#pragma once
//#include <fstream>
//constexpr auto answerSize = 51; //Размер ответа
//constexpr auto quantityAnswers = 4; //Количество ответов
//constexpr auto taskSize = 501; //Количество символов в задании
//constexpr auto pathSize = 51; //Количество символов в имени файла
//
//struct Answer {
//	char answer[answerSize]{ "T" }; //Текст варианта ответа
//	bool correctID{ false }; //Верный, неверный
//};
//
//class Task {
//protected:
//	int taskID{ 0 }; //Номер задания
//	int numberPoints{ 0 }; //Количество балов за вопрос
//	char task[taskSize]{ "TASK" }; //Задание (вопрос)
//	Answer answers[quantityAnswers]; //Массив вариантов ответа
//
//public:
//	Task() {}
//	Task(int taskID, int numberPoints, char* task, Answer* answers);
//	~Task() {}
//	void setTaskID(int taskID);
//	void setNumberPoints(int numberPoints);
//	void setTask(char* task);
//	void setAnswers(Answer* answers);
//	int getTaskID();
//	int getNumberPoints();
//	char* getTask();
//	Answer* getAnswers();
//	void inputConsolTask();
//	void showConsolTask();
//	bool fSaveTask(char* path);
//	int fReadNTask(char* path);
//	bool fReadAll(char* path);
//	bool fReadTask(char* path, int num);
//	bool fReadShowTasks(char* path);
//};
