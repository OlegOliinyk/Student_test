#pragma once
#include "Task.h"
#include "View.h"
#include "ViewRecordList.h"
#include "ConsolCommands.h"
#include "RecordList.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TEST_FIELDS { TEST_ID = 0, LECTURER_ID, TEST_SUBJECT, TEST_FOR_GROUP, TEST_NAME };

class Test :
    public ConsolCommands
    /*public Task*/ {
protected:
    //testID будет добавляться к названию файла для тестовых заданий по даному тесту
    string path{ "TestList.txt" };
    //string testID{ "" }; 
    //string lecturerID{ "" };
    //string testSubject{ "" };
    //string testForGroup{ "" };
    //string testName{ "" };
    vector<string> test_fields;
    vector<vector<string>> test_list;
    int count{ 0 };
    Task task;

public:
    Test() { 
        test_fields.reserve(5);
        for (int i = 0; i < 5; i++) test_fields.push_back("");
    }
    ~Test(){}

    string getTestID();

    void inputConsolTest(string lecturerID);
    void showConsolTest();
    int showConsolTestListForLecturer(int posY, string lecturer);
    void showConsolTestListForStudent(int posY);
    void showConsolTestList(int posY);
    bool fSaveTest();
    bool fSaveTestList();
    bool fReadTestListSelectively(TEST_FIELDS select, string id);
    bool fReadShowTests(string path);

    void clearsTestList();

    string editTest(int num);

    //string testIdFromTestList(int num);

    void lecturerTestTask(string path, View& view);

};

