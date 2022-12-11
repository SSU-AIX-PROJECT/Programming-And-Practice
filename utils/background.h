//
// Created by dlalsdn on 2022-12-07.
//

#ifndef PROGRAMINGSOURCE_BACKGROUND_H
#define PROGRAMINGSOURCE_BACKGROUND_H

#include <windows.h>
#include "enum.h"

struct CACTUS {
    int shape;
    int loc;
};

void draw_cactus(HDC *hdc, struct CACTUS *cactus) {
    int X_LOC = cactus->loc * 10;
    // 뿌리
    Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
    if (cactus->shape == CACTUS_LEFT || cactus->shape == CACTUS_ALL) {
        Rectangle(*hdc, X_LOC - 30, 460 + 25, X_LOC - 10, 410 + 25);
        Rectangle(*hdc, X_LOC - 10, 460 + 25, X_LOC , 450 + 25);
    }
    if (cactus->shape == CACTUS_RIGHT || cactus->shape == CACTUS_ALL) {
        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
    }
}

#endif //PROGRAMINGSOURCE_BACKGROUND_H
