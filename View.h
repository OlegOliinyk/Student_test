#pragma once
//#include "ViewRecordList.h"
#include "ConsolCommands.h"
#include <string>

using namespace std;

class View : 
	public ConsolCommands {
protected:
	//void cursorPosition(int x, int y);
	//void stringCls(int x, int y, int n);
public:
	char mainMenu();
	//����� �����������
	void screenAuthorization(string role);
	void screenRegistration(string role);
	void screenDelete(string role);
	//����� ��������� ������ � ������
	void screenChangeAuthorization();
	char adminMainMenu();
	char workWithUsersMenu(string user);
	char lecturerMainMenu(string lecturer);
	//���� ��� ������ � ������ �������������
	char lecturerTestMenu();
	//���� ��� ������ � �������� �������� �������������
	char lecturerTaskMenu(string testName);
	char studentMainMenu(string student);
	char studentTestMenu();
	char groupMainMenu();
	char subjectMainMenu();
};

