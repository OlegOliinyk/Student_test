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
	cout << "\n���������� �������I�" << "\n�����i�� ��� �����������";
	cout << "\n\n���i� - 0       ���i� - 1       �������� - 2       ������� - 3\n";
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
	cout << "\n���������i� ����������� " << role;
}

void View::screenRegistration(string role) {
	system("cls");
	cout << "\n�������i� ����������� " << role;
}

void View::screenDelete(string role) {
	system("cls");
	cout << "\n��������� ����������� " << role;
}

void View::screenChangeAuthorization() {

}

char View::adminMainMenu() {
	system("cls");
	char symbol{ ' ' };
	cout << "\n�������� (��i��) �����: ";
	cout << "\n\n����������� - 0     ���i� - 1     �������� - 2     ������� - 3     ������ ���� - 4     ������ �������i� - 5\n";
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
	cout << "\n�������� (��i��) ����� ����������i� " << user;
	cout << "\n\n����������� - 0       �������� - 1       ���������� - 2       �������� - 3\n";
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
	cout << "\n�������� " << lecturer;
	cout << "\n\n����������� - 0     ��i�� ���i�� �� ������ - 1     ������ � ������ - 2     ���������� ���������� - 3";
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
	cout << "\n������ � ������ (��������)";
	cout << "\n\n����������� - 0     �������� - 1     ����������  - 2     �������� - 3";
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
	cout << "\n������ � ��������� ���������� ����� '" << testName << "' (��������)";
	cout << "\n\n����������� - 0   ������ �������� - 1   ������� ��i �������� - 2   ������� ���� �������� - 3";
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
	cout << "\n������� " << student;
	cout << "\n\n����������� - 0     ��i�� ���i�� �� ������ - 1     ���������� - 2";
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
	cout << "\n������ � ������ (�������)";
	cout << "\n\n����������� - 0       ������ - 1       ����������� ���������� - 2";
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
	cout << "������ I� ������� ����";
	this->stringCls(0, 3, 167);
	cout << "����������� - 0   ������ ����� �� ������ - 1   �������� ����� i� ������ - 2   ������� ������ ���� - 3\n";
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
	cout << "������ I� ������� �������I�";
	this->stringCls(0, 3, 167);
	cout << "����������� - 0   ������ ������� �� ������ - 1   �������� ������� i� ������ - 2   ������� ������ �������i� - 3\n";
	symbol = _getch();
	switch (symbol) {
	case 27: return 27;
	case 49: return 49;
	case 50: return 50;
	case 51: return 51;
	default: return '0';
	}
}
