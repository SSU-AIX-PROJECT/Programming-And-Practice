#ifndef PROGRAMINGSOURCE_MENU_H
#define PROGRAMINGSOURCE_MENU_H

#include "../utils/utils.h"

#define SIZE_OF_MENU 3

char menuSelect[SIZE_OF_MENU][20] = {"SINGLE GAME [ 1P ]", "MULTI GAME  [ 2P ]", "    QUIT GAME"};

void printMenu(const int *currentMenu);

int menuComponent() {
    int pressKey, currentMenu = 0;
    printMenu(&currentMenu);

    while (1) {
        pressKey = getKey();
        if (pressKey == 0) continue;
        if (pressKey == 72) { // 위 화살표 누를 시
            if (currentMenu-- < 1) currentMenu++;
        } else if (pressKey == 80) { // 아래 화살표 누를 시
            if (currentMenu++ > 1) currentMenu--;
        } else if (pressKey == 13) { // 엔터 누를 시
            printf("EXECUTE MENU : %d\n", currentMenu);
            break;
        }
        printMenu(&currentMenu);
    }
    return currentMenu;
}

void printMenu(const int *currentMenu) {
    system("cls");
    for (int i = 0; i < 15; i++) printf("\n");
    for (int i = 0; i < 3; i++) {
        changeCmdColor(WHITE);
        if (*currentMenu == i) changeCmdColor(LIGHT_BLUE);
        printf("                                                  %s \n\n", menuSelect[i]);
    }
    changeCmdColor(WHITE);
}


#endif //PROGRAMINGSOURCE_MENU_H
