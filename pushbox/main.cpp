
using namespace std;

#include <iostream>

#include <windows.h>
#include <string.h>
#include <conio.h>

#include "pushbox.h"
/*
int map[N][M] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },//0->?հ?
    { 0, 0, 0, 0, 1, 0, 2, 1, 1, 1, 0, 0, 0, 0, 0 },//1->ǽ
    { 0, 0, 0, 0, 1, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0 },//2->??
    { 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0 },//3->????
    { 0, 0, 0, 1, 4, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0 },//4->λ??
    { 0, 0, 0, 1, 4, 3, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 4, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
*/

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
        cout << "??ѡ???Ĺؿ??ǣ?" << select << endl;
        cout << "?????ˣ?" << step << "??";
        box.Drop(map);
        cout << "W-----????           S------????" << endl;
        cout << "A-----????           S------????" << endl;
        char ch;
        ch = _getch();
        step = box.move(map, ch);
        system("cls");
        if (box.juide(map))break;
    }
    std::cout << "??Ӯ??!";
    std::cout << "???ߣ?" << step << "??";
    getchar();
    getchar();
}
