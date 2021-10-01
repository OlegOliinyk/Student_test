// Oliinyk_Test_Student_Exam.cpp : 

#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Admin.h"
#include "Lecturer.h"
#include "Student.h"
#include "View.h"
#include "Test.h"
#include "ViewRecordList.h"


using namespace std;

//void lecturerTestTask(Test &test, View &view);
//void lecturerTest(View &view);

int main() {
	setlocale(LC_ALL, "Rus");
	
	//COORD coord;
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);

	View view;
	char idMenu{ ' ' };
	for (;;) {
		idMenu = view.mainMenu();
		switch (idMenu) {
		case 'A': {
			Admin userA;
			view.screenAuthorization("ADMIN");
			if (!userA.consolUserAuthorization()) {
				break;
			}
			do {
				idMenu = view.adminMainMenu();
				switch (idMenu) {
				case 'A': {
					do {
						//Admin userA;
						idMenu = view.workWithUsersMenu("ADMIN");
						switch (idMenu) {
						case 'C': {
							view.screenRegistration("ADMIN");
							userA.consolUserRegistration();

							//cout << "\nСоздание пользователя ADMIN";
							//Sleep(1000);
							break;
						}
						case 'E': {
							cout << "\nРедактирование пользователя ADMIN";
							Sleep(1000);
							break;
						}
						case 'D': {
							view.screenDelete("ADMIN");
							if (!userA.consolUserDelete()) {
								cout << "\nНе вдале видалення користувача ADMIN!!!";
							}
							//cout << "\nУдаление пользователя ADMIN";
							//Sleep(1000);
							break;
						}
						default: {}
						}
					} while (idMenu != '0' && idMenu != 27);
					if (idMenu != 27) idMenu = ' ';
					//cout << "\nРабота с группой Admins";
					//Sleep(1000);
					break;
				}
				case 'L': {
					do {
						Lecturer userL;
						idMenu = view.workWithUsersMenu("LECTURER");
						switch (idMenu) {
						case 'C': {
							view.screenRegistration("LECTURER");
							userL.consolUserRegistration();
							//cout << "\nСоздание пользователя LECTURER";
							//Sleep(1000);
							break;
						}
						case 'E': {
							cout << "\nРедактирование пользователя LECTURER";
							Sleep(1000);
							break;
						}
						case 'D': {
							view.screenDelete("LECTURER");
							if (!userL.consolUserDelete()) {
								cout << "\nНе вдале видалення користувача LECTURER!!!";
							}
							//cout << "\nУдаление пользователя LECTURER";
							//Sleep(1000);
							break;
						}
						default: {}
						}
					} while (idMenu != '0' && idMenu != 27);
					if (idMenu != 27) idMenu = ' ';
					//cout << "\nРабота с группой Lecturers";
					//Sleep(1000);
					break;
				}
				case 'S': {
					do {
						Student userS;
						idMenu = view.workWithUsersMenu("STUDENT");
						switch (idMenu) {
						case 'C': {
							view.screenRegistration("STUDENT");
							userS.consolUserRegistration();

							//cout << "\nСоздание пользователя STUDENT";
							//Sleep(1000);
							break;
						}
						case 'E': {
							cout << "\nРедактирование пользователя STUDENT";
							Sleep(1000);
							break;
						}
						case 'D': {
							view.screenDelete("STUDENT");
							if (!userS.consolUserDelete()) {
								cout << "\nНе вдале видалення користувача STUDENT!!!";
							}
							//cout << "\nУдаление пользователя STUDENT";
							//Sleep(1000);
							break;
						}
						default: {}
						}
					} while (idMenu != '0' && idMenu != 27);
					if (idMenu != 27) idMenu = ' ';
					//cout << "\nРабота с группой Students";
					//Sleep(1000);
					break;
				}
				case 'G': {
					ViewRecordList group("gp.txt");
					system("cls");
					//idMenu = view.groupMainMenu();
					do {
						//ViewRecordList group("gp.txt");
						idMenu = view.groupMainMenu();
						switch (idMenu) {
						case 49: {
							group.consolInputRecord('G');
							break;
						}
						case 50: {
							group.consolDelRecord('G');
							break;
						}
						case 51: {
							group.consolShowListRecord('G');
							break;
						}
						default: {}
						}
					} while (idMenu != '0' && idMenu != 27);
					if (idMenu != 27) idMenu = ' ';
					break;
				}
				case 'P': {
					ViewRecordList subject("sub.txt");
					system("cls");
					//idMenu = view.subjectMainMenu();
					do {
						//ViewRecordList subject("sub.txt");
						idMenu = view.subjectMainMenu();
						switch (idMenu) {
						case 49: {
							subject.consolInputRecord('P');
							break;
						}
						case 50: {
							subject.consolDelRecord('P');
							break;
						}
						case 51: {
							subject.consolShowListRecord('P');
							break;
						}
						default: {}
						}
					} while (idMenu != '0' && idMenu != 27);
					if (idMenu != 27) idMenu = ' ';
					break;
				}
				default: {}
				}
			} while (idMenu != '0' && idMenu != 27);
			if (idMenu != 27) idMenu = ' ';
			//cout << "\nAdmin";
			//Sleep(1000);
			break;
		}
		case 'L': {
			Lecturer userL;
			view.screenAuthorization("LECTURER");
			if (!userL.consolUserAuthorization()) {
				break;
			}
			do {
				idMenu = view.lecturerMainMenu(userL.getSurname() + " " + userL.getName() + " " + userL.getPatronymic());
				switch (idMenu) {
				case 49: { //Смена логина и пароля
					cout << "\nСмена логина и пароля";
					Sleep(1000);
					break;
				}
				case 50: { //Работа с тестом
					userL.lecturerTest(view);
					break;
				}
				case 51: { //Результаты тестирования
					cout << "\nРезультаты тестирования";
					Sleep(1000);
					break;
				}
				default: {}
				}
			} while (idMenu != '0' && idMenu != 27);
			if (idMenu != 27) idMenu = ' ';
			//cout << "\nLecturer";
			//Sleep(1000);
			break;
		}
		case 'S': {
			Student userS;
			view.screenAuthorization("STUDENTS");
			if (!userS.consolUserAuthorization()) {
				break;
			}
			do {
				idMenu = view.studentMainMenu(userS.getSurname() + " " + userS.getName() + " " + userS.getPatronymic());
				switch (idMenu) {
				case 49: { //Смена логина и пароля
					cout << "\nСмена логина и пароля";
					Sleep(1000);
					break;
				}
				case 50: { //Тестирование
					cout << "\nТестирование студента";
					Sleep(1000);
					break;
				}
				default: {}
				}
			} while (idMenu != '0' && idMenu != 27);
			if (idMenu != 27) idMenu = ' ';

			//cout << "\nStudent";
			//Sleep(1000);
			break;
		}
		default: return 0;
		}
	}

	//Admins user;
	//int N = 1;
	//while (N != 0) {
	//	//system("cls");
	//	cout << "\n( 0 - выход, 1 - регистрация, 2 - авторизация, удаление пользователя - 3 ): ";
	//	cin >> N;
	//	switch (N) {
	//	case 1: {
	//		user.consolLecturerRegistration();
	//		break;
	//	}
	//	case 2: {
	//		user.consolUserAuthorization();
	//		break;
	//	}
	//	case 3: {
	//		user.deleteUser();
	//		break;
	//	}
	//	}

		//if (N == 1){
		//user.consolUserRegistration();
		//}
	//if (user.fReadListUser()) {
	//	cout << "\nOk";
	//}
	//else{
	//	cout << "\nОшибка чтения файла";
	//}
	//user.consolShowListUser();
}


////Функция для работы с заданиями создаваемого теста. Принимает ссылку на объект view,
////уже созданный в функции main, и ссылку на объект test созданный в функции lecturerTest
//void lecturerTestTask(Test &test, View &view) {
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
//
////Функция работы Преподавателя с Тестом. Принимает ссылку на объект view,
////уже созданный в функции main
//void lecturerTest(View &view) {
//	Test test;
//	char symb = ' ';
//	do {
//		symb = view.lecturerTestMenu();
//		switch (symb) {
//		case 49: { //Создать
//			cout << "\nСоздание теста";
//			Sleep(1000);
//			lecturerTestTask(test, view);
//			break;
//		}
//		case 50: { //Редактировать
//			cout << "\nРедактирование теста";
//			Sleep(1000);
//			break;
//		}
//		case 51: { //Удалить
//			cout << "\nУдаление теста";
//			Sleep(1000);
//			break;
//		}
//		default: {}
//		}
//
//	} while (symb != '0');
//
//}