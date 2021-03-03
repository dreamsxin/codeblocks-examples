#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define  high 25   //������
#define width 60   //������
#define  border -1    //�߽�
#define   blank  0    //�հ�
#define   plane  1    //�ɻ�
#define  bullet  2    //�ӵ�
#define   enemy  3    //�л�
#define destroy  4    //�ݻٱ��

int canvas[high + 2][width + 2];  //��Ϸ�����ĸߺͿ�
int pos_h, pos_w;   //�ɻ�λ��
int enemynum;    //�л�����
int interval; //ͬ���ƴ���ģ��ʱ����
int itv_move; //�л��ƶ���ʱ����
int itv_new; //�л�ˢ�µ�ʱ����
int score;  //����
int IsOver;  //�ж���Ϸ�Ƿ����

void Startup();   //��Ϸ��ֵ��ʼ��
void Show();    //��Ϸ�������
void UpdateInput();     //�����뵼�µ���Ϸ״̬����
void UpdateNormal();    //�������޹ص���Ϸ״̬����
void HideCursor();		//���ع��
void gotoxy(int x, int y);		//�ص����

int main()
{
    Startup();  //��ʼ��
    while (IsOver)     //��Ϸѭ��
    {
        UpdateInput();
        UpdateNormal();
        Show();
    }
    printf("\t\tgame over!\n");
    Sleep(2500);    //��ͣ��Ϸ�������棨���룩
    system("pause");
    return 0;
}
void Startup()    //��Ϸ��ֵ��ʼ��
{
    IsOver = 1;
    score = 0;  //��ʼ������
    for (int i = 0; i < high + 2; i++)        //��ʼ������
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == high + 1 ||
                    j == 0 || j == width + 1)
            {
                canvas[i][j] = border;
            }
            else canvas[i][j] = blank;
        }
    }
    pos_h = high / 2;    //��ʼ���ɻ���ֱ����
    pos_w = width / 2;     //��ʼ���ɻ�ˮƽ����
    canvas[pos_h][pos_w] = plane;  //��ʼ���ɻ�λ��
    enemynum = 3;       //�л�����
    srand(time(NULL));
    interval = 4;      //��ʼ��ʱ��������
    itv_move = 5;      //��ʼ���л��ƶ�ʱ����
    itv_new = 40;     //��ʼ���л�ˢ��ʱ����
}
void Show()    //��Ϸ�������
{
    HideCursor();   //���ع��
    gotoxy(1, 1);    //�ص���ꡢˢ�»���
    for (int i = 0; i < high + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (canvas[i][j] == plane)   //��ǰλ��Ϊ�ɻ�λ��
            {
                printf("*");
            }
            else if (canvas[i][j] == bullet)    //��ǰλ��Ϊ�ӵ�λ��
            {
                printf("|");
            }
            else if (canvas[i][j] == enemy)    //��ǰλ��Ϊ�л�λ��
            {
                printf("@");
            }
            else if (canvas[i][j] == border)    //��ǰλ��Ϊ�߽�
            {
                printf("#");
            }
            else if (canvas[i][j] == blank)    //��ǰλ��������ڱ߽���
            {
                printf(" ");
            }
            else if (canvas[i][j] == destroy)    //��ǰλ��������ڱ߽���
            {
                printf("x");
            }
        }
        printf("\n");
    }
    printf("\n�÷֣�%d", score);
}
void UpdateInput()    //�����뵼�µ���Ϸ״̬����
{
    char key_W = GetKeyState('W'),  //��� W ���Ƿ���
         key_S = GetKeyState('S'),  //��� S ���Ƿ���
         key_A = GetKeyState('A'),  //��� A ���Ƿ���
         key_D = GetKeyState('D'),  //��� D ���Ƿ���
         key_attack = GetKeyState(' ');  //��� �ո� ���Ƿ���
    if (kbhit())   //���м�����ʱ  //vc++6.0���ϰ汾Ϊ _kbhit()
    {
        if (key_W < 0)    //������ W ��������
        {
            if (pos_h > 1)
            {
                canvas[pos_h][pos_w] = blank;
                if (canvas[pos_h - 1][pos_w] == enemy)    //�¸�λ���ǵл���ײ��
                {
                    canvas[pos_h - 1][pos_w] = destroy;
                    IsOver = 0;
                }
                else canvas[--pos_h][pos_w] = plane;
            }
        }
        if (key_S < 0)    //������ S ��������
        {
            if (pos_h < high)
            {
                canvas[pos_h][pos_w] = blank;
                if (canvas[pos_h + 1][pos_w] == enemy)    //�¸�λ���ǵл���ײ��
                {
                    canvas[pos_h + 1][pos_w] = destroy;
                    IsOver = 0;
                }
                else canvas[++pos_h][pos_w] = plane;
            }
        }
        if (key_A < 0)    //������ A ��������
        {
            if (pos_w > 1)
            {
                canvas[pos_h][pos_w] = blank;
                if (canvas[pos_h][pos_w - 1] == enemy)    //�¸�λ���ǵл���ײ��
                {
                    canvas[pos_h][pos_w - 1] = destroy;
                    IsOver = 0;
                }
                else canvas[pos_h][--pos_w] = plane;
            }
        }
        if (key_D < 0)    //������ D ��������
        {
            if (pos_w < width)
            {
                canvas[pos_h][pos_w] = blank;
                if (canvas[pos_h][pos_w + 1] == enemy)    //�¸�λ���ǵл���ײ��
                {
                    canvas[pos_h][pos_w + 1] = destroy;
                    IsOver = 0;
                }
                else canvas[pos_h][++pos_w] = plane;
            }
        }
        if (key_attack < 0)     //�����¿ո���������ӵ�
        {
            if (pos_h != 1)canvas[pos_h - 1][pos_w] = bullet;
        }
    }
}
void UpdateNormal()    //�������޹ص���Ϸ״̬����
{
    int temp[high + 2][width + 2];  //�����ж�ԭλ�õ���ʱ����
    for (int i = 1; i <= high; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            temp[i][j] = canvas[i][j];
        }
    }
    for (int i = 1; i <= high; i++)    //������ʱ���飬�޸Ļ���
    {
        for (int j = 1; j <= width; j++)
        {
            if (temp[i][j] == enemy && interval % itv_move == 0)   //��ǰλ��Ϊ�л�
            {
                canvas[i][j] = blank;
                if (temp[i + 1][j] == bullet)    //����Ϊ�ӵ����л�������
                {
                    canvas[i + 1][j] = blank;
                    score++;
                    printf("\a");  //������Ч
                }
                else if (i < high)
                {
                    canvas[i + 1][j] = enemy;
                }
                if (i + 1 == pos_h && j == pos_w)    //����Ϊ�ɻ�����ҷɻ���ײ��
                {
                    canvas[i + 1][j] = destroy;
                    IsOver = 0;
                }
            }
            if (temp[i][j] == bullet)   //��ǰλ��Ϊ�ӵ�
            {
                canvas[i][j] = blank;
                if (temp[i - 1][j] == enemy)    //�¸�λ���ǵл����л�������
                {
                    canvas[i - 1][j] = blank;
                    score++;
                    printf("\a");
                }
                else if (i > 1)
                {
                    canvas[i - 1][j] = bullet;
                }
            }
        }
    }
    if (interval % itv_new == 0)  //�պõ�ʱ����
        for (int i = 0; i < enemynum; i++)     //�����л�Ⱥ
        {
            canvas[rand() % 2 + 1][rand() % width + 1] = enemy;
        }
    if (interval <= 100)    //ʱ�����ƴ�
    {
        interval++;
    }
    else      //ʱ�����ƴ�����
    {
        interval = 0;
    }
}
void gotoxy(int x, int y)   //�ص����
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void HideCursor()   //���ع�꺯��
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
