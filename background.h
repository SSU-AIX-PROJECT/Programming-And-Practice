//
// Created by dlalsdn on 2022-12-07.
//

#ifndef PROGRAMINGSOURCE_BACKGROUND_H
#define PROGRAMINGSOURCE_BACKGROUND_H

#include "enum.h"

struct CACTUS {
    int shape;
    int loc;
};


void draw_cactus(HDC *hdc, struct CACTUS *cactus) {
    int X_LOC = cactus->loc * 10;
    if (cactus->shape == CACTUS_LEFT) {
        // 불휘 깊은 선인장
        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
    } else if (cactus->shape == CACTUS_RIGHT) {
        // 불휘 깊은 선인장
        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
    } else if (cactus->shape == CACTUS_ALL) {
        // 불휘 깊은 선인장
        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
    }
}
//void draw_cactus(HDC *hdc, int state, int loc) {
//    int X_LOC = loc * 10;
//    if (state == CACTUS_LEFT) {
//        // 불휘 깊은 선인장
//        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
//        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
//        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
//    } else if (state == CACTUS_RIGHT) {
//        // 불휘 깊은 선인장
//        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
//        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
//        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
//    } else if (state == CACTUS_ALL) {
//        // 불휘 깊은 선인장
//        Rectangle(*hdc, X_LOC, 510, X_LOC + 30, 420);
//        Rectangle(*hdc, X_LOC + 40, 460, X_LOC + 60, 410);
//        Rectangle(*hdc, X_LOC + 30, 460, X_LOC + 40, 450);
//    }
//}



#endif //PROGRAMINGSOURCE_BACKGROUND_H
