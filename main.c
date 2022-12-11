#include <windows.h>
#include <stdio.h>

#include "utils/utils.h"
#include "utils/enum.h"
#include "component/menu.h"
#include "component/single.h"
#include "component/multi.h"



int getKey();

void changeCmdColor(int color);

//void printMenu(const int *currentMenu);

int main() {
    int record;
    int selectedMenu = 0;
    // 한글 깨짐 방지
    system("chcp 65001 && cls");

    while (1) {
        // 메인 메뉴 선택창
        selectedMenu = menuComponent();

        system("cls");
        switch (selectedMenu) {
            case 0:
                record = singleGame();
                break;

            case 1:
                record = multiGame();
                break;

            case 2:
                return EXIT_SUCCESS;
        }

        system("cls");
        printf("\n\n\n\n\n                                                  최종 점수\n\n");
        printf("                                             %15d \n\n\n\n\n", record);
        printf(" 메뉴로 돌아가려면 아무키나 누르세요");
        _getch();
    }
}