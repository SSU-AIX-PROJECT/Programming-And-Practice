#ifndef PROGRAMINGSOURCE_SINGLE_H
#define PROGRAMINGSOURCE_SINGLE_H

#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#include "../utils/pose.h"
#include "../utils/utils.h"
#include "../utils/background.h"
#include "../utils/enum.h"

#define GROUND_POS 300
#define END_X 1500

int singleGame(void) {
    system("mode con:cols=120 lines=30");

    int score = 0;
    int x = 100, y = GROUND_POS;
    int state_jump = 0;
    int jump_pos = 0;
    int state_run = 0;
    struct CACTUS cactus = {CACTUS_RIGHT, END_X / 10};

    HDC hdc = GetWindowDC(GetForegroundWindow());

    while (1) {
        state_run = 1 - state_run;

        if (getKey() && state_jump == 0) {
            state_jump = 1;
            jump_pos = 0;
        }


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

        // 선인장 제어
        draw_cactus(&hdc, &cactus, 0);
        if (cactus.loc < 0) {
            cactus.loc = END_X / 10;
            cactus.shape = rand()%3;
        }
        cactus.loc = cactus.loc - 5;

        if (5 <= cactus.loc && cactus.loc <= 25) {
            if (state_jump == 0) break;
        }


        draw_character(&hdc, state_run, x, y);
        Sleep(10);
        system("cls");
        printf("내 점수 : %10d", score);
        score += 1;
    }
    return score;
}

#endif //PROGRAMINGSOURCE_SINGLE_H
