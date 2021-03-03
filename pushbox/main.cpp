
using namespace std;

#include <iostream>

#include <windows.h>
#include <string.h>
#include <conio.h>
#include "pushbox.h"

#define N 15
#define M 15



int main()
{
    int map[N][M] =
    {
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   1,   2,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   1,   0,   3,   3,   1,   0,   1,   1,   1,   0,   0,   0,
        0,   0,   0,   1,   0,   3,   0,   1,   0,   1,   4,   1,   0,   0,   0,
        0,   0,   0,   1,   1,   1,   0,   1,   1,   1,   4,   1,   0,   0,   0,
        0,   0,   0,   0,   1,   1,   0,   0,   0,   0,   4,   1,   0,   0,   0,
        0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,
        0,   0,   0,   0,   1,   0,   0,   0,   1,   1,   1,   1,   0,   0,   0,
        0,   0,   0,   0,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0
    };

    PushBox box;

    int select = 1;
    int step = 0;
    while (1)
    {
        cout << "你选择的关卡是：" << select << endl;
        cout << "你走了：" << step << "步";
        box.Drop(map);
        cout << "W-----向上           S------向下" << endl;
        cout << "A-----向左           S------向右" << endl;
        char ch;
        ch = _getch();
        step = box.move(map, ch);
        system("cls");
        if (box.juide(map))break;
    }
    std::cout << "你赢了!";
    std::cout << "共走：" << step << "步";
    getchar();
    getchar();
}
