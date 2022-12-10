#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#include "pose.h"
#include "background.h"
#include "get.cpp"

#include "enum.h"

#define GROUND_POS 300
#define END_X 1500

int getKey();


int main(void) {
    int x = 100, y = GROUND_POS;
    int state_jump;
    int jump_pos;
    int state_run = 0;
    struct CACTUS cactus[3] = {
            {CACTUS_LEFT, END_X / 10},
            {CACTUS_RIGHT, END_X / 10},
            {CACTUS_ALL, END_X / 10}
    };
    HDC hdc = GetWindowDC(GetForegroundWindow());

    while (1) {
        state_run = 1 - state_run;


        if (getKey() && state_jump == 0) {
            state_jump = 1;
            jump_pos = 0;
        }

        Rectangle(hdc, 400 + 40, 510 - 50, 430 + 30, 420 - 10);
        Rectangle(hdc, 400 + 30, 510 - 50, 430 + 10, 420 + 30);
        Rectangle(hdc, 400, 510, 430, 420);

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



        for (int i = 0; i < 3; i++) {
            draw_cactus(&hdc, &cactus[i]);
            if (cactus[i].loc < 0) cactus[i].loc = END_X / 10;
            cactus[i].loc = cactus[i].loc - 5;
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