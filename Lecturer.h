#pragma once
#include "UserConsolFile.h"
#include "Test.h"
#include "View.h"
#include "Test.h"
#include "ConsolCommands.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>



//struct LecturerData {
//    string surname{ "" };
//    string name{ "" };
//    string patronymic{ "" };
//    //string role{ "" };
//    string faculty{ "" };
//    string subject{ "" };
//};


class Lecturer :
    public ConsolCommands,
    public UserConsolFile {
protected:
    enum USER_FIELDS { PASSWORD, SURNAME, NAME, PATRONYMIC, FACULTY, SUBJECT };
    Test test;
    void inputUserData();
public:
    Lecturer() : UserConsolFile("UspaLc.usp", 6) { this->setUserFields(6)/*, this->fReadListUsers()*/; }
    ~Lecturer() {}

    void consolUserRegistration();
    void consolShowListUsers();
    //void lecturerTestTask(Test& test, View& view);
    void lecturerTest(View& view);
};

