#include <windows.h>
#include <stdio.h>

#include "utils/utils.h"
#include "component/menu.h"
#include "component/single.h"
#include "component/multi.h"

int main() {
    system("mode con:cols=120 lines=30"); // 창 크기 초기화
    int record, selectedMenu = 0;
    system("chcp 65001 && cls"); // 한글 깨짐 방지
    while (1) {
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