//#include <windows.h>
//#include <conio.h>
//#include <cstdio>
//
//// Char Pos Set
//int x = 100, y = 100;
//void draw_character(HDC *hdc, int state);
//
//int main(void) {
//    int state_run;
//    HDC hdc = GetWindowDC(GetForegroundWindow());
//    y = 100;
//    while ( 1 ) {
//        state_run = 1 - state_run;
//        if (_kbhit) {
//            // is jump?
////            printf("!");
////            y = 30;
//        }
//        draw_character(&hdc, state_run);
//    }
//    return 0;
//}
//
//void draw_character(HDC *hdc, int state) {
//    // 꼬리 part
//    Rectangle(*hdc, x + 10, y + 105, x + 40, y + 115);
//    Rectangle(*hdc, x + 20, y + 115, x + 60, y + 145);
//    Rectangle(*hdc, x + 40, y + 145, x + 60, y + 165);
//    Rectangle(*hdc, x + 50, y + 165, x + 60, y + 175);
//    Rectangle(*hdc, x + 30, y + 145, x + 40, y + 155);
//    Rectangle(*hdc, x + 10, y + 135, x + 20, y + 70);
//    // 몸통 part
//    Rectangle(*hdc, x + 60, y + 105, x + 70, y + 175);
//    Rectangle(*hdc, x + 70, y + 95, x + 120, y + 175);
//    Rectangle(*hdc, x + 120, y + 95, x + 150, y + 145);
//    Rectangle(*hdc, x + 120, y + 145, x + 140, y + 155);
//    Rectangle(*hdc, x + 120, y + 155, x + 130, y + 165);
//    Rectangle(*hdc, x + 150, y + 95, x + 170, y + 105);
//    Rectangle(*hdc, x + 160, y + 105, x + 170, y + 115);
//    // 머리 part
//    Rectangle(*hdc, x + 110, y + 25, x + 150, y + 95);
//    Rectangle(*hdc, x + 85, y + 85, x + 110, y + 95);
//    Rectangle(*hdc, x + 100, y + 75, x + 110, y + 85);
//    Rectangle(*hdc, x + 150, y + 65, x + 190, y + 75);
//    Rectangle(*hdc, x + 150, y + 55, x + 160, y + 65);
//    Rectangle(*hdc, x + 150, y, x + 200, y + 55);
//    Rectangle(*hdc, x + 120, y, x + 150, y + 15);
//    Rectangle(*hdc, x + 200, y + 10, x + 210, y + 55);
//    Rectangle(*hdc, x + 110, y + 10, x + 130, y + 25);
//    Rectangle(*hdc, x + 140, y + 15, x + 150, y + 25);
//    // 다리 part
//    Rectangle(*hdc, x + 70, y + 175, x + 90, y + 195);
//    Rectangle(*hdc, x + 70, y + 195, x + 80, y + 215);
//    Rectangle(*hdc, x + 80, y + 205, x + 90, y + 215);
//    Rectangle(*hdc, x + 110, y + 175, x + 120, y + 215);
//    Rectangle(*hdc, x + 120, y + 205, x + 130, y + 215);
//}