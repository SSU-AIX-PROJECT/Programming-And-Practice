#ifndef PROGRAMINGSOURCE_POSE_H
#define PROGRAMINGSOURCE_POSE_H

#include "windows.h"

#define ROWS 23
#define LEG_ROWS 5

int POSE_SET[ROWS][4] = {
        // 꼬리 part
        {10,  105, 40,  115},
        {20,  115, 60,  145},
        {40,  145, 60,  165},
        {50,  165, 60,  175},
        {30,  145, 40,  155},
        {10,  135, 20,  70},
        // 몸통 part
        {60,  105, 70,  175},
        {70,  95,  120, 175},
        {120, 95,  150, 145},
        {120, 145, 140, 155},
        {120, 155, 130, 165},
        {150, 95,  170, 105},
        {160, 105, 170, 115},
        // 머리 part
        {110, 25,  150, 95},
        {85,  85,  110, 95},
        {100, 75,  110, 85},
        {150, 65,  190, 75},
        {150, 55,  160, 65},
        {150, 0,   200, 55},
        {120, 0,   150, 15},
        {200, 10,  210, 55},
        {110, 10,  130, 25},
        {140, 15,  150, 25},
};
int LEG_POSE_SET[4][LEG_ROWS][4] = {
        { // RUN01
                {70, 175, 80, 195},
                {80, 185, 90, 195},
                {100, 175, 110, 185},
                {110, 175, 120, 215},
                {120, 205, 130, 215},
        },
        { // RUN02
                {70, 175, 90, 195},
                {70, 195, 80, 215},
                {80,  205, 90,  215},
                {110, 175, 120, 200},
                {120, 190, 130, 200},
        },
        { // IDLE
                {70, 175, 90, 195},
                {70, 195, 80, 215},
                {80,  205, 90,  215},
                {110, 175, 120, 215},
                {120, 205, 130, 215},
        }
};

void draw_character(HDC *hdc, int state, int x, int y) {
    for (int i = 0; i < ROWS; i++) {
        Rectangle(*hdc, x + POSE_SET[i][0], y + POSE_SET[i][1], x + POSE_SET[i][2], y + POSE_SET[i][3]);
    }
    for (int i = 0; i < LEG_ROWS; i++) {
        Rectangle(*hdc, x + LEG_POSE_SET[state][i][0], y + LEG_POSE_SET[state][i][1], x + LEG_POSE_SET[state][i][2],
                  y + LEG_POSE_SET[state][i][3]);
    }
}

#endif //PROGRAMINGSOURCE_POSE_H
