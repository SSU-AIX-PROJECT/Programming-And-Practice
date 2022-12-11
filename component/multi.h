//
// Created by dlalsdn on 2022-12-11.
//

#ifndef PROGRAMINGSOURCE_MULTI_H
#define PROGRAMINGSOURCE_MULTI_H

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

int multiGame(void) {
    int score = 0;
    int x = 100, y = GROUND_POS;
    int state_jump = 0;
    int jump_pos = 0;
    int state_run = 0;
    struct CACTUS cactus = {CACTUS_RIGHT, END_X / 10};


    printf("\n 게임을 시작하기전에 확인해주세요");
    printf("\n 1. 콘솔창을 아래 밑줄이 보일 때까지 내려주세요");
    printf("\n 2. 키보드 입력 테스트를 진행해주세요");

    // 115 s 106 j
    int joinP1 = 0;
    int joinP2 = 0;

    while (1) {

        int press = getKey();
        if (press == 115) joinP1 = 1; // S키 눌른 경우 P1 연동 완료
        if (press == 106) joinP2 = 1; // J키 눌른 경우 P2 연동 완료


    }
    return -1;

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
        draw_cactus(&hdc, &cactus);
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

#endif //PROGRAMINGSOURCE_MULTI_H
