#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

void Admin::inputUserData() {
    cout << "\nПароль: ";
    cin >> this->user[PASSWORD];
    cout << "\nВведiть Фамiлiю: ";
    cin >> this->user[SURNAME];
    cout << "\nИмя: ";
    cin >> this->user[NAME];
    cout << "\nПо батьковi: ";
    cin >> this->user[PATRONYMIC];
}

bool Admin::searchListUsers() {

    return false;
}

void Admin::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "Регистрация пользователя";
    for (;;) {
        cout << "\n\nВведiть логiн нового користувача: ";
        cin >> this->login;
        if (this->login == "0") break;
        if (this->listUsers.size() == 0 || this->listUsers.count(this->login) == 0) {
            this->inputUserData();
            this->listUsers.emplace(this->login, this->user);
            break;
        }
        else {
            cout << "\nДаний логін вже існує!!!";
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
