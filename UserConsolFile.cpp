#include "UserConsolFile.h"

bool UserConsolFile::fReadAll() {
    fstream fRead;
    char symb = ' ';
    string path{ "Uspa.usp" };
    fRead.open(path, ios::in | ios::binary);
    if (fRead.is_open()) {
        cout << "\n";
        while (!fRead.eof()) {
            fRead >> symb;
            cout << symb;
        }
        fRead.close();
        return true;
    }
    else return false;
}

bool UserConsolFile::fReadListUsers() {
    fstream fListUsers(this->path, ios::in | ios::binary);
    if (fListUsers.is_open()) {
        auto it = listUsers.begin();
        while (!fListUsers.eof()) {

            fListUsers >> this->login; /*>> this->user[PASSWORD] >> this->user[SURNAME] >> this->user[NAME] >> this->user[PATRONYMIC];*/
            for (int i = 0; i < userFields; i++) {
                fListUsers >> this->user[i];
                replace(this->user[i].begin(), this->user[i].end(), '_', ' ');

            }
            it = listUsers.find(this->login);
            if (it == listUsers.end()) {
                this->listUsers.emplace(this->login, this->user);

                //cout << "\n";
                //cout << this->login;
                //for (int i = 0; i < userFields; i++) {
                //    cout << "   " << this->user[i];
                //}
            }
        }
        fListUsers.close();
        cout << "\n";
        return true;
    }
    return false;
}

bool UserConsolFile::fWriteListUsers() {
    fstream fListUsers(this->path, ios::out | ios::binary);
    if (fListUsers.is_open()) {
        string tempStr{ "" };
        for (auto it = this->listUsers.begin(); it != this->listUsers.end(); ++it) {
            fListUsers << it->first; /*<< " " << it->second[PASSWORD] << " " << it->second[SURNAME] << " "
                << it->second[NAME] << " " << it->second[PATRONYMIC] << "\n";*/
            for (int i = 0; i < this->userFields; i++) {
                tempStr = it->second[i];
                replace(tempStr.begin(), tempStr.end(), ' ', '_');

                fListUsers << " " << tempStr;
            }
            fListUsers << "\n";
            //cout << it->first;
            //for (int i = 0; i < this->userFields; i++) {
            //    cout << " " << it->second[i];
            //}
            cout << "\n";
        };
        fListUsers.close();
        return true;
    }
    return false;
}

//void Users::inputUserData() {
//    cout << "\n������: ";
//    cin >> this->password;
//    cout << "\n����i�� ���i�i�: ";
//    cin >> this->user.surname;
//    cout << "\n���: ";
//    cin >> this->user.name;
//    cout << "\n�� �������i: ";
//    cin >> this->user.patronymic;
//}

void UserConsolFile::consolUserRegistration() {
    //system("cls");
    this->fReadListUsers();
    //cout << "����������� ������������";
    for (;;) {
        cout << "\n\n����i�� ���i� ������ �����������: ";
        cin >> this->login;
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

bool UserConsolFile::consolUserAuthorization() {
        string login, password;
        //system("cls");
        //string path{ "" };
        //switch (role) {
        //case ADMIN: { path = "UspaAd.usp"; break; }
        //case LECTURER: { path = "UspaLc.usp"; break; }
        //case STUDENT: { path = "UspaSt.usp"; break; }
        //}
        //if (this->listUsers.size() != 0) this->clearListUsers();

        this->fReadListUsers();
        auto it = this->listUsers.begin();
        for (int i = 0; i < 5; i++) {
            cout << "\n\n����i�� ���i� ��� ���������i�: ";
            cin >> login;
            if (login == "0") return false;
            it = this->listUsers.find(login);
            if (it != this->listUsers.end()) {
                for (int i = 0; i < 5; i++) {
                    cout << "\n����i�� ������: ";
                    cin >> password;
                    if (it->second[PASSWORD] == password) {
                        this->login = it->first;
                        this->user = it->second;
                        return true;
                    }
                    else {
                        cout << "\n������ �� �i����!!!";
                    }
                }
            }
            else {
                cout << "\n������ ����������� ���� � ������!!!";
            }
        }
        return false;
}

void UserConsolFile::consolShowListUsers() {
    //system("cls");
    cout << "\n";
    for (auto it = this->listUsers.begin(); it != this->listUsers.end(); ++it) {
        cout << it->first << " " << it->second[PASSWORD] << " " << it->second[SURNAME] << " "
            << it->second[NAME] << " " << it->second[PATRONYMIC] << "\n";
    };
    cout << "\n";
}

bool UserConsolFile::consolUserDelete() {
    this->fReadListUsers();
    string login, password;
    //system("cls");
    //cout << "\n��������� �����������";
    auto it = this->listUsers.begin();
    for (int i = 0; i < 5; i++) {
        cout << "\n\n����i�� ���i� ��� ��������� �����������: ";
        cin >> login;
        if (login == "0") return false;
        it = this->listUsers.find(login);
        if (it != this->listUsers.end()) {
            this->listUsers.erase(it);
            //for (int i = 0; i < 5; i++) {
            //    cout << "\n������� ������: ";
            //    cin >> password;
            //    if (it->second == password) {
            //        return true;
            //    }
            //    else {
            //        cout << "\n������ �� ������!!!";
            //    }
            //}
            this->fWriteListUsers();
            return true;
        }
        else {
            cout << "\n������ ����������� ���� � ������!!!";
        }
    }
    return false;
}
