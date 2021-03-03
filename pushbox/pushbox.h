using namespace std;

#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <fstream>

#define N 15
#define M 15

//����һ����������ز�������
/*--------------------------PushBox���д--------------------------------------*/
/****************************************************************************/
class PushBox
{
public:
    int move(int map[N][M], char ch);//�ƶ�����
    void Drop(int map[N][M]);//���ӽ����д
    int  juide(int map[N][M]);//�ж��Ƿ�ȫ������λ�ã��ɹ�����1��ʧ�ܷ���0
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
                std::cout << "��";
                break;
            case 2:
                Color(10);
                std::cout << "��";
                break;
            case 3:
                Color(5);
                std::cout << "��";
                break;
            case 4:
                Color(1);
                std::cout << "��";
                break;
            case 5:
                Color(7);
                std::cout << "��";
                break;
            case 6:
                Color(10);
                std::cout << "��";
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
    /*******************���ڿո�*/
    if (map[i][j] == 2)
    {
        //��ǰ������,�����ڿո�
        if (map[i + x1][j + y1] == 3)
        {
            //����ǰ��Ϊ�ո�S
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //����ǰ��Ϊλ��
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }
        //��ǰΪ���ӣ�������λ����
        if (map[i + x1][j + y1] == 5)
        {
            //����ǰ��Ϊ��
            if (map[i + x2][j + y2] == 0)
            {
                map[i + x2][j + y2] = 3;
                map[i + x1][j + y1] = 6;
                map[i][j] = 0;
                return 1;

            }
            //����ǰ��Ϊλ��
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 0;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 5;
                return 1;
            }

        }
        /*--------------------*/
        //��ǰΪ�ո�
        if (map[i + x1][j + y1] == 0)
        {
            map[i + x1][j + y1] = 2;
            map[i][j] = 0;
            return 1;
        }
        //��ǰΪλ��
        if (map[i + x1][j + y1] == 4)
        {
            map[i + x1][j + y1] = 6;
            map[i][j] = 0;
            return 1;
        }
        return 0;
    }
    /*******************����λ����*/
    if (map[i][j] == 6)
    {
        //λ��ǰ��������,�����ڿո�
        if (map[i + x1][j + y1] == 3)
        {
            //����ǰ��Ϊ�ո�
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //����ǰ��Ϊλ��
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 2;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }
        //λ��ǰ��������,������λ��
        if (map[i + x1][j + y1] == 5)
        {
            //����ǰ���ǿո�
            if (map[i + x2][j + y2] == 0)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 3;
                return 1;
            }
            //����ǰ����λ��
            if (map[i + x2][j + y2] == 4)
            {
                map[i][j] = 4;
                map[i + x1][j + y1] = 6;
                map[i + x2][j + y2] = 5;
                return 1;
            }
        }

        /*-----------------*/
        //��ǰΪλ��
        if (map[i + x1][j + y1] == 4)
        {
            map[i + x1][j + y1] = 6;
            map[i][j] = 4;
            return 1;
        }
        //��ǰΪ�ո�
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
    HANDLE consolehwnd;//�����������ϸ���֪ʶ����ٶ�һ�»��MSDN
    consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);//ʵ�������
    SetConsoleTextAttribute(consolehwnd, m);
}
