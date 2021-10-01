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
	//Экран авторизации
	void screenAuthorization(string role);
	void screenRegistration(string role);
	void screenDelete(string role);
	//Экран изменения логина и пароля
	void screenChangeAuthorization();
	char adminMainMenu();
	char workWithUsersMenu(string user);
	char lecturerMainMenu(string lecturer);
	//Меню для работы с тестом преподавателя
	char lecturerTestMenu();
	//Меню для работы с тестовым заданием преподавателя
	char lecturerTaskMenu(string testName);
	char studentMainMenu(string student);
	char studentTestMenu();
	char groupMainMenu();
	char subjectMainMenu();
};

