#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#include "pose.h"
#define GROUND_POS 300

int getKey();

int main(void) {
    int x = 100, y = GROUND_POS;
    int state_jump;
    int jump_pos;
    int state_run = 0;
    HDC hdc = GetWindowDC(GetForegroundWindow());

    while (1) {
        state_run = 1 - state_run;


        if (getKey() && state_jump == 0) {
            state_jump = 1;
            jump_pos = 0;
        }
//        else if (y < GROUND_POS) {
//            y += 25;
//        }
        if (state_jump != 0) {
            y = GROUND_POS - 50 * jump_pos;
            jump_pos += state_jump;
            if (jump_pos == 4 && state_jump == 1) {
                state_jump = -1;
                jump_pos = 4;
            } else if (jump_pos == 0 && state_jump == -1) {
                state_jump = 0;
            }
        } else {
            y = GROUND_POS;
        }

        draw_character(&hdc, state_run, x, y);
        Sleep(10);
        system("cls");
    }
}

int getKey() {
    if (_kbhit() != 0) return _getch();
    return 0;
}