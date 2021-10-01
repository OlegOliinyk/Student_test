#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

void Admin::inputUserData() {
    cout << "\n������: ";
    cin >> this->user[PASSWORD];
    cout << "\n����i�� ���i�i�: ";
    cin >> this->user[SURNAME];
    cout << "\n���: ";
    cin >> this->user[NAME];
    cout << "\n�� �������i: ";
    cin >> this->user[PATRONYMIC];
}

bool Admin::searchListUsers() {

    return false;
}

void Admin::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "����������� ������������";
    for (;;) {
        cout << "\n\n����i�� ���i� ������ �����������: ";
        cin >> this->login;
        if (this->login == "0") break;
        if (this->listUsers.size() == 0 || this->listUsers.count(this->login) == 0) {
            this->inputUserData();
            this->listUsers.emplace(this->login, this->user);
            break;
        }
        else {
            cout << "\n����� ���� ��� ����!!!";
        }
    }
    this->fWriteListUsers();
}

void Admin::consolShowListUsers() {
    //system("cls");
    cout << "\n";
    for (auto it = this->listUsers.begin(); it != this->listUsers.end(); ++it) {
        cout << it->first << " " << it->second[PASSWORD] << " " << it->second[SURNAME] << " "
            << it->second[NAME] << " " << it->second[PATRONYMIC] << "\n";
    };
    cout << "\n";
}
