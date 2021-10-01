#include "View.h"
#include "RecordList.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <clocale>
#include <string>
#include <set>

using namespace std;

char View::mainMenu() {
	system("cls");
	char symbol{ ' ' };
	cout << "\nТЕСТУВАННЯ СТУДЕНТIВ" << "\nВиберiть тип користувача";
	cout << "\n\nВихiд - 0       Адмiн - 1       Викладач - 2       Студент - 3\n";
	symbol = _getch();
	switch (symbol) {
	case 49: return 'A';
	case 50: return 'L';
	case 51: return 'S';
	default: return '0';
	}
}

void View::screenAuthorization(string role) {
	system("cls");
	cout << "\nАвторизацiя користувача " << role;
}

void View::screenRegistration(string role) {
	system("cls");
	cout << "\nРеєстрацiя користувача " << role;
}

void View::screenDelete(string role) {
	system("cls");
	cout << "\nВидалення користувача " << role;
}

void View::screenChangeAuthorization() {

}

char View::adminMainMenu() {
	system("cls");
	char symbol{ ' ' };
	cout << "\nВнесення (змiна) даних: ";
	cout << "\n\nПовернутися - 0     Адмiн - 1     Викладач - 2     Студент - 3     Список груп - 4     Список предметiв - 5\n";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 'A';
	case 50: return 'L';
	case 51: return 'S';
	case 52: return 'G';
	case 53: return 'P';
	default: return '0';
	}
}

char View::workWithUsersMenu(string user) {
	system("cls");
	char symbol{ ' ' };
	cout << "\nВнесення (змiна) даних користувачiв " << user;
	cout << "\n\nПовернутися - 0       Створити - 1       Редагувати - 2       Видалити - 3\n";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 'C';
	case 50: return 'E';
	case 51: return 'D';
	default: return '0';
	}
}

char View::lecturerMainMenu(string lecturer) {
	system("cls");
	char symbol{ ' ' };
	cout << "\nВИКЛАДАЧ " << lecturer;
	cout << "\n\nПовернутися - 0     Змiна логiну та паролю - 1     Робота з тестом - 2     Результати тестування - 3";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}

char View::lecturerTestMenu() {
	system("cls");
	char symbol{ ' ' };
	cout << "\nРОБОТА З ТЕСТОМ (ВИКЛАДАЧ)";
	cout << "\n\nПовернутися - 0     Створити - 1     Редагувати  - 2     Видалити - 3";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}

char View::lecturerTaskMenu(string testName) {
	system("cls");
	char symbol{ ' ' };
	cout << "\nРОБОТА З ТЕСТОВИМИ ЗАВДАННЯМИ ТЕСТУ '" << testName << "' (ВИКЛАДАЧ)";
	cout << "\n\nПовернутися - 0   Додати завдання - 1   Вивести всi завдання - 2   Вивести одне завдання - 3";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}

char View::studentMainMenu(string student) {
	system("cls");
	char symbol{ ' ' };
	cout << "\nСТУДЕНТ " << student;
	cout << "\n\nПовернутися - 0     Змiна логiну та паролю - 1     Тестування - 2";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	default: return '0';
	}
}

char View::studentTestMenu() {
	system("cls");
	char symbol{ ' ' };
	cout << "\nРОБОТА З ТЕСТОМ (СТУДЕНТ)";
	cout << "\n\nПовернутися - 0       Пройти - 1       Переглянути Результати - 2";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	default: return '0';
	}
}

char View::groupMainMenu() {
	//system("cls");
	char symbol{ ' ' };
	this->stringCls(0, 1, 167);
	cout << "РОБОТА IЗ СПИСКОМ ГРУП";
	this->stringCls(0, 3, 167);
	cout << "Повернутися - 0   Додати групу до списку - 1   Видалити групу iз списку - 2   Вивести список груп - 3\n";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}

char View::subjectMainMenu() {
	//system("cls");
	char symbol{ ' ' };
	this->stringCls(0, 1, 167);
	cout << "РОБОТА IЗ СПИСКОМ ПРЕДМЕТIВ";
	this->stringCls(0, 3, 167);
	cout << "Повернутися - 0   Додати предмет до списку - 1   Видалити предмет iз списку - 2   Вивести список предметiв - 3\n";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}
