//
// Created by dlalsdn on 2022-12-03.
//

#ifndef PROGRAMINGSOURCE_ENUM_H
#define PROGRAMINGSOURCE_ENUM_H

// 현재 페이지
enum SCENE {
    MENU,
    GAME,
};
// 플레이 방식
enum PLAY_MODE {
    SINGLE_GAME,
    MULTI_GAME
};
// 공룡 상태
enum BEHAVE_STATE {
    RUN01,
    RUN02,
    IDLE,
};
// 선인장 모양
enum CACTUS_STATE {
    CACTUS_LEFT,
    CACTUS_RIGHT,
    CACTUS_ALL,
};

// 콘솔 색상
enum CMD_COLOR {
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLR,
    LIGHT_YELLOW,
    LIGHT_WHITE,
};
#endif //PROGRAMINGSOURCE_ENUM_H
