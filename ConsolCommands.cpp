#include "ConsolCommands.h"

//Функция устанавливает курсор в указанную позицию по полученным координатам x и y.
void ConsolCommands::cursorPosition(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsolCommands::stringCls(int x, int y, int n) {
	this->cursorPosition(x, y);
	for (int i = 0; i < n; i++)
		cout << " ";
	this->cursorPosition(x, y);
}

