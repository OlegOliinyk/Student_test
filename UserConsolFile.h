#pragma once
#include "User.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>


//����� UserConsolFile ��������� ������ User, � ������� ����������� ������ ���������� � ������ ������ � ����,
//� �����, ������ ������ �� �������.
class UserConsolFile :
    public User {
protected:
	bool fReadAll();
	bool fReadListUsers();
	bool fWriteListUsers();
	virtual void inputUserData() = 0;
public:
    UserConsolFile(): User(){}
	UserConsolFile(unsigned short userFields) : User(userFields) {}
	UserConsolFile(string path) : User(path) {} 
	UserConsolFile(string path, unsigned short userFields) : User(path, userFields) {}

	virtual void consolUserRegistration() = 0;
	bool consolUserAuthorization();
	virtual void consolShowListUsers() = 0;
	bool consolUserDelete();
};

