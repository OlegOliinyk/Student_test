#pragma once
#include "UserConsolFile.h"

//struct StudentData {
//    string surname{ "" };
//    string name{ "" };
//    string patronymic{ "" };
//    //string role{ "" };
//    string course{ "" };
//    string faculty{ "" };
//    string group{ "" };
//};


class Student :
    public UserConsolFile {
protected:
    enum USER_FIELDS { PASSWORD, SURNAME, NAME, PATRONYMIC, COURSE, FACULTY, GROUP };
    void inputUserData();
public:
    Student() :UserConsolFile("UspaSt.usp", 7) { this->setUserFields(7)/*, this->fReadListUsers()*/; }
    ~Student() {}

    void consolUserRegistration();
    void consolShowListUsers();
};

