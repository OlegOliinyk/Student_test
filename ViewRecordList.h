#pragma once
#include "RecordList.h"
#include "ConsolCommands.h"

class ViewRecordList :
    public RecordList, public ConsolCommands {

public:
    ViewRecordList(string path): RecordList(path) {}
    ~ViewRecordList(){}

    void consolInputRecord(char id);
    void consolDelRecord(char id);
    void consolShowListRecord(char id);

    string consolShowListRecord(int pos);


};

