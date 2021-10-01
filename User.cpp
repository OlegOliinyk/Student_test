#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

//using namespace std;

void User::setUserFields(unsigned short userFielgs) {
    this->userFields = userFielgs;
}

void User::setPath(string &path) {
    this->path = path;
}

void User::setLogin(string& login) {
    this->login = login;
}

void User::setPassword(string& password) {
    this->user[PASSWORD] = password;
}

void User::setSurname(string& surname) {
    this->user[SURNAME] = surname;
}

void User::setName(string& name) {
    this->user[NAME] = name;
}

void User::setPatronymic(string& patronymic) {
    this->user[PATRONYMIC] = patronymic;
}

string User::getPath() {
    return this->path;
}

string User::getLogin() {
    return this->login;
}

string User::getPassword() {
    return this->user[PASSWORD];
}

string User::getSurname() {
    return this->user[SURNAME];
}

string User::getName() {
    return this->user[NAME];
}

string User::getPatronymic() {
    return this->user[PATRONYMIC];
}

bool User::clearListUsers() {
    this->listUsers.clear();
    return false;
}

