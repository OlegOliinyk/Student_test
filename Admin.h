#pragma once
#include "UserConsolFile.h"
//#include <map>
//#include <string>
//
//
//using namespace std;

class Admin :
    public UserConsolFile {
private:
    void inputUserData();
public:
    Admin() :UserConsolFile("UspaAd.usp") { /*this->fReadListUsers();*/ }
    ~Admin(){}

    bool searchListUsers();
    void consolUserRegistration();
    void consolShowListUsers();
};

