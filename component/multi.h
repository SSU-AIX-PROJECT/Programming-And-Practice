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

#define GROUND_POS_P1 300
#define GROUND_POS_P2 900
#define END_X 1500

void printDescMulti() {
    printf("\n   키보드 입력 테스트를 진행해주세요");
    changeCmdColor(LIGHT_BLUE);
    printf("\n   -> S와 J를 한번씩 눌러주세요");
    changeCmdColor(WHITE);
}

int multiGame(void) {
    system("mode con:cols=120 lines=100");

    int scoreP1 = 0;
    int scoreP2 = 0;

    int x = 100;
    int y_P1 = GROUND_POS_P1;
    int y_P2 = GROUND_POS_P2;


    int state_jump_P1 = 0;
    int state_jump_P2 = 0;

    int jump_pos_P1 = 0;
    int jump_pos_P2 = 0;

    int state_run_P1 = 0;
    int state_run_P2 = 0;
    struct CACTUS cactus = {CACTUS_RIGHT, END_X / 10};
    HDC hdc = GetWindowDC(GetForegroundWindow());

    printDescMulti();
    int joinP1 = 0;
    int joinP2 = 0;

    int END_P1 = 0;
    int END_P2 = 0;

    do {
        if (joinP1) changeCmdColor(BLUE);
        printf("\n\n   S키 - PLAYER 1");
        changeCmdColor(WHITE);
        if (joinP2) changeCmdColor(BLUE);
        printf("\n   J키 - PLAYER 2");
        changeCmdColor(WHITE);

        if (joinP1 && joinP2) break;

        int press = _getch();
        if (press == 115) joinP1 = 1; // S키 눌른 경우 P1 연동 완료
        if (press == 106) joinP2 = 1; // J키 눌른 경우 P2 연동 완료

        system("cls");
        printDescMulti();

    } while (1);
    Sleep(2500);


    while (1) {

        state_run_P1 = 1 - state_run_P1;
        state_run_P2 = 1 - state_run_P2;

        int pressedKey = getKey();
        // P1 데이터 수정
        if (pressedKey == 115 && state_jump_P1 == 0 && END_P1 == 0) {
            state_jump_P1 = 1;
            jump_pos_P1 = 0;
        }
        // P2 데이터 수정
        if (pressedKey == 106 && state_jump_P2 == 0 && END_P2 == 0) {
            state_jump_P2 = 1;
            jump_pos_P2 = 0;
        }

        // P1 점프 상태 관리
        if (state_jump_P1 != 0) {
            y_P1 = GROUND_POS_P1 - 50 * jump_pos_P1;
            jump_pos_P1 += state_jump_P1;
            if (jump_pos_P1 == 4 && state_jump_P1 == 1) {
                state_jump_P1 = -1;
                jump_pos_P1 = 4;
            } else if (jump_pos_P1 == 0 && state_jump_P1 == -1) {
                state_jump_P1 = 0;
            }
        } else {
            y_P1 = GROUND_POS_P1;
        }
        // P2 점프 상태 관리
        if (state_jump_P2 != 0) {
            y_P2 = GROUND_POS_P2 - 50 * jump_pos_P2;
            jump_pos_P2 += state_jump_P2;
            if (jump_pos_P2 == 4 && state_jump_P2 == 1) {
                state_jump_P2 = -1;
                jump_pos_P2 = 4;
            } else if (jump_pos_P2 == 0 && state_jump_P2 == -1) {
                state_jump_P2 = 0;
            }
        } else {
            y_P2 = GROUND_POS_P2;
        }

        // 선인장 제어
        if (END_P1 == 0) draw_cactus(&hdc, &cactus, 0);;
        if (END_P2 == 0) draw_cactus(&hdc, &cactus, GROUND_POS_P2 - GROUND_POS_P1);;


        if (cactus.loc < 0) {
            cactus.loc = END_X / 10;
            cactus.shape = rand()%3;
        }
        cactus.loc = cactus.loc - 5;

        if (5 <= cactus.loc && cactus.loc <= 25) {
            if (state_jump_P1 == 0) END_P1 = 1;
        }
        if (5 <= cactus.loc && cactus.loc <= 25) {
            if (state_jump_P2 == 0) END_P2 = 1;
        }
        if (END_P1 && END_P2) break;

        draw_character(&hdc, state_run_P1, x, y_P1);
        draw_character(&hdc, state_run_P2, x, y_P2);

        Sleep(10);
        system("cls");
        printf("PLAYER 1 점수 : %10d", scoreP1);
        for (int i = 0; i < 30; i++) printf("\n");
        printf("PLAYER 2 점수 : %10d", scoreP2);

        if (END_P1 == 0) scoreP1 += 1;
        if (END_P2 == 0) scoreP2 += 1;
    }
    system("color 07");

    return scoreP1 >= scoreP2 ? scoreP1 : scoreP2;
}

#endif //PROGRAMINGSOURCE_MULTI_H
