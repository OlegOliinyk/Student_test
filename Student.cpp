#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

void Student::inputUserData() {
    cout << "\n������: ";
    cin >> this->user[PASSWORD];
    cout << "\n����i�� ���i�i�: ";
    cin >> this->user[SURNAME];
    cout << "\n���: ";
    cin >> this->user[NAME];
    cout << "\n�� �������i: ";
    cin >> this->user[PATRONYMIC];
    cout << "\n����: ";
    cin >> this->user[COURSE];
    cout << "\n���������: ";
    cin.ignore(1, '\n');
    getline(cin, user[FACULTY], '\n');
    cout << "\n�����: ";
    getline(cin, user[GROUP], '\n');

}

void Student::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "����������� ������������";
    for (;;) {
        cout << "\n\n����i�� ���i� ������ �����������: ";
        cin >> this->login;
        if (this->listUsers.size() == 0 || this->listUsers.count(this->login) == 0) {
            this->inputUserData();
            //cout << "������: ";
            //cin >> this->password;
            //cout << "\n������� �������: ";
            //cin >> this->user.surname;
            //cout << "���: ";
            //cin >> this->user.name;
            //cout << "��������: ";
            //cin >> this->user.patronymic;
            this->listUsers.emplace(this->login, this->user);

            break;
        }
        else {
            cout << "\n����� ���� ��� ����!!!";
        }
    }
    this->fWriteListUsers();
}

void Student::consolShowListUsers() {

}
