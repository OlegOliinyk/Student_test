#pragma once
#include <fstream>
#include <iostream>
#include <clocale>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

constexpr auto quantityAnswers = 4; //���������� �������
//constexpr auto taskSize = 501; //���������� �������� � �������
//constexpr auto pathSize = 51; //���������� �������� � ����� �����

class Task {
protected:
	int taskID{ 0 }; //����� �������
	int numberPoints{ 0 }; //���������� ����� �� ������
	string task{ "" }; //������� (������)
	pair<string, bool> answers[quantityAnswers]{ {"", 0}, {"", 0}, {"", 0}, {"", 0} }; //������ ��������� ������
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
//constexpr auto answerSize = 51; //������ ������
//constexpr auto quantityAnswers = 4; //���������� �������
//constexpr auto taskSize = 501; //���������� �������� � �������
//constexpr auto pathSize = 51; //���������� �������� � ����� �����
//
//struct Answer {
//	char answer[answerSize]{ "T" }; //����� �������� ������
//	bool correctID{ false }; //������, ��������
//};
//
//class Task {
//protected:
//	int taskID{ 0 }; //����� �������
//	int numberPoints{ 0 }; //���������� ����� �� ������
//	char task[taskSize]{ "TASK" }; //������� (������)
//	Answer answers[quantityAnswers]; //������ ��������� ������
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
