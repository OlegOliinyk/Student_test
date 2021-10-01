
#pragma once
#include <map>
#include <string>
#include <vector>

using namespace std;

class User {
protected:
	unsigned short userFields{ 4 };
	enum USER_FIELDS { PASSWORD, SURNAME, NAME, PATRONYMIC };

	string path{ "Uspa.usp" };
	string login{ "" };
	vector<string> user/*{ "","","","" }*/;
	map<string, vector<string>> listUsers;
public:
	User() { for (int i = 0; i < userFields; i++) this->user.push_back(""); }
	User(unsigned short userFields) { for (int i = 0; i < userFields; i++) this->user.push_back(""); }
	User(string path) : User() {
		this->setPath(path);
	}
	User(string path, unsigned short userFields): User(userFields) {
		this->setPath(path);
	}
	~User() {}

	void setUserFields(unsigned short userFielgs);
	void setPath(string &path);
	void setLogin(string &login);
	void setPassword(string &password);
	void setSurname(string& surname);
	void setName(string& name);
	void setPatronymic(string& patronymic);
	//bool setListUsers();
	string getPath();
	string getLogin();
	string getPassword();
	string getSurname();
	string getName();
	string getPatronymic();
	//bool searchListUsers();
	bool clearListUsers();

};

