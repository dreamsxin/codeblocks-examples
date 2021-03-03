using namespace std;

#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <fstream>

#define N 15
#define M 15

//建立一个推箱子相关操作的类
/*--------------------------PushBox类编写--------------------------------------*/
/****************************************************************************/
class PushBox
{
public:
    int move(int map[N][M], char ch);//移动箱子
    void Drop(int map[N][M]);//箱子界面编写
    int  juide(int map[N][M]);//判断是否全部移入位置，成功返回1，失败返回0
private:
    int push(int map[N][M],int x1,int x2,int y1,int y2);
    void Color(int m);
    void Postion(int map[N][M], int *i, int *j);
};

int PushBox::move(int map[N][M], char ch)
{

    static int step = 0;
    int x1, x2, y1, y2;
    switch (ch)
    {
    case 's':
    case 'S':
        x1 = 1;
        x2 = 2;
        y1 = 0;
        y2 = 0;
        if (push(map, x1, x2, y1, y2)) step++;
        return step;

    case 'w':
    case 'W':
        x1 = -1;
        x2 = -2;
        y1 = 0;
        y2 = 0;
        if (push(map,x1,x2,y1,y2)) step++;
        return step;

    case 'A':
    case 'a':
        x1 = 0;
        x2 = 0;
        y1 = -1;
        y2 = -2;
        if (push(map,x1,x2,y1,y2)) step++;
        return step;
    case 'D':
    case 'd':
        x1 = 0;
        x2 = 0;
        y1 = 1;
        y2 = 2;
        if (push(map,x1,x2,y1,y2)) step++;
        return step;
    }
    return 0;
}

void PushBox::Drop(int map[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            switch (map[i][j])
            {
            case 0:
                Color(7);
                std::cout << "  ";
                break;
            case 1:
                Color(4);
                std::cout << "■";
                break;
            case 2:
                Color(10);
                std::cout << "△";
                break;
            case 3:
                Color(5);
                std::cout << "□";
                break;
            case 4:
                Color(1);
                std::cout << "☆";
                break;
            case 5:
                Color(7);
                std::cout << "◆";
                break;
            case 6:
                Color(10);
                std::cout << "△";
                break;

            }
        std::cout << "\n";
    }
}

int PushBox::juide(int map[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (map[i][j] == 6)return 0;
            if (map[i][j] == 4)return 0;
        }

        if (i == N - 1 && j == M - 1)return 1;
    }
    return 0;
}

int PushBox::push(int map[N][M],int x1,int x2,int y1,int y2)
{
    int i, j;
    Postion(map, &i, &j);
    /*******************人在空格处*/
    if (map[i][j] == 2)
    {
        //人前是箱子,箱子在空格处
        if (map[i + x1][j + y1] == 3)
        {
            //箱子前面为空格S
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //箱子前面为位置
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }
        //人前为箱子，箱子在位置上
        if (map[i + x1][j + y1] == 5)
        {
            //箱子前面为空
            if (map[i + x2][j + y2] == 0)
            {
                map[i + x2][j + y2] = 3;
                map[i + x1][j + y1] = 6;
                map[i][j] = 0;
                return 1;

            }
            //箱子前面为位置
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 5;
                return 1;
            }

        }
        /*--------------------*/
        //人前为空格
        if (map[i + x1][j + y1] == 0)
        {
            map[i + x1][j + y1] = 2;
            map[i][j] = 0;
            return 1;
        }
        //人前为位置
        if (map[i + x1][j + y1] == 4)
        {
            map[i + x1][j + y1] = 6;
            map[i][j] = 0;
            return 1;
        }
        return 0;
    }
    /*******************人在位置上*/
    if (map[i][j] == 6)
    {
        //位置前面是箱子,箱子在空格
        if (map[i + x1][j + y1] == 3)
        {
            //箱子前面为空格
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //箱子前面为位置
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }
        //位置前面是箱子,箱子在位置
        if (map[i + x1][j + y1] == 5)
        {
            //箱子前面是空格
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //箱子前面是位置
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }

        /*-----------------*/
        //人前为位置
        if (map[i + x1][j + y1] == 4)
        {
            map[i + x1][j + y1] = 6;
            map[i][j] = 4;
            return 1;
        }
        //人前为空格
        if (map[i + x1][j + y1] == 0)
        {
            map[i + x1][j + y1] = 2;
            map[i][j] = 4;
            return 1;
        }
        return 0;
    }
    return 0;
}

void PushBox::Postion(int map[N][M], int *cl, int *cow)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (map[i][j] == 2 || map[i][j] == 6)goto ML;
        }
    }
ML:
    *cl = i;
    *cow = j;
    ;
}

void PushBox::Color(int m)
{
    HANDLE consolehwnd;//创建句柄，详细句柄知识，请百度一下或查MSDN
    consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);//实例化句柄
    SetConsoleTextAttribute(consolehwnd, m);
}
