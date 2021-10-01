#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

void Student::inputUserData() {
    cout << "\nПароль: ";
    cin >> this->user[PASSWORD];
    cout << "\nВведiть Фамiлiю: ";
    cin >> this->user[SURNAME];
    cout << "\nИмя: ";
    cin >> this->user[NAME];
    cout << "\nПо батьковi: ";
    cin >> this->user[PATRONYMIC];
    cout << "\nКурс: ";
    cin >> this->user[COURSE];
    cout << "\nФакультет: ";
    cin.ignore(1, '\n');
    getline(cin, user[FACULTY], '\n');
    cout << "\nГрупу: ";
    getline(cin, user[GROUP], '\n');

}

void Student::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "Регистрация пользователя";
    for (;;) {
        cout << "\n\nВведiть логiн нового користувача: ";
        cin >> this->login;
        if (this->listUsers.size() == 0 || this->listUsers.count(this->login) == 0) {
            this->inputUserData();
            //cout << "пароль: ";
            //cin >> this->password;
            //cout << "\nВведите Фамилию: ";
            //cin >> this->user.surname;
            //cout << "Имя: ";
            //cin >> this->user.name;
            //cout << "Отчество: ";
            //cin >> this->user.patronymic;
            this->listUsers.emplace(this->login, this->user);

            break;
        }
        else {
            cout << "\nДаний логін вже існує!!!";
        }
    }
    this->fWriteListUsers();
}

void Student::consolShowListUsers() {

}
