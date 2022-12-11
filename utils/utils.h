#ifndef PROGRAMINGSOURCE_UTILS_H
#define PROGRAMINGSOURCE_UTILS_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>

#include "enum.h"

int getKey() {
    if (_kbhit() != 0) return _getch();
    return 0;
}

void changeCmdColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }

#endif //PROGRAMINGSOURCE_UTILS_H
