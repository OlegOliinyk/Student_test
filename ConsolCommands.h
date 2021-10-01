#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class ConsolCommands {
protected:
	void cursorPosition(int x, int y);
	void stringCls(int x, int y, int n);
};

