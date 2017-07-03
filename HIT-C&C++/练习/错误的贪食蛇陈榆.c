#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define H 8
#define L 16
char GameMap[H][L];//��Ϸ��ͼ
int key;//��������
int sum = 1, over = 0;//�ߵĳ��ȣ���Ϸ����
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct Snake
{
	int x, y;//���λ��
	int now;//���浱ǰ���ķ���0��1��2��3�ֱ������������
};
struct Snake Snake[H*L];
const char Shead = '@';//��ͷ
const char Sbody = '#';//����
const char Sfood = '*';//ʳ��
const char Snode = '.';//�������ڵ�ͼ����ʾΪ��
void Initial();//��ͼ�ĳ�ʼ��
void Create_Food();//�ڵ�ͼ���������ʳ��
void Show();//ˢ����ʾ��ͼ
void Button();//ȡ�����������жϷ���
void Move();//�ߵ��ƶ�
void Check_Border();//�����ͷ�Ƿ�Խ��
void Check_Head(int x, int y);//�����ͷ�ƶ���λ�õ����

int main()
{
	Initial();
	Show();
	return 0;
}

void Initial()//��ͼ�ĳ�ʼ��
{
	int i, j;
	int hx, hy;
	system("title ̰����");//����̨�ı���
	memset(GameMap, '.', sizeof(GameMap));//��ʼ����ͼȫ��Ϊ��
	system("cls");
	srand(time(0));//�������
	hx = rand() % H;
	hy = rand() % L;
	GameMap[hx][hy] = Shead;
	Snake[0].x = hx;
	Snake[0].y = hy;
	Snake[0].now = -1;
	Create_Food();//�������ʳ��
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < L; j++)
		{
			printf("%c", GameMap[i][j]);
		}
		printf("\n");
	}
	printf("�����ⷽ�����ʼ��Ϸ");
	getch();
	Button();
}

void Create_Food()//�ڵ�ͼ���������ʳ��
{
	int fx, fy;
	while (1)
	{
		fx = rand() % H;
		fy = rand() % L;
		if (GameMap[fx][fy] == '.')//���ܳ�������ͷ��λ��
		{
			GameMap[fx][fy] = Sfood;
			break;
		}
	}
}

void Show()//ˢ����ʾ��ͼ
{
	int i, j;
	while (1)
	{
		Sleep(500);//�ӳٰ��룬ÿ����ˢ��һ�ε�ͼ
		Button();//�жϰ���
		Move();//��ʼ����
		if (over)
		{
			printf("\n**��Ϸ����**\n");
			getchar();
			break;
		}
		system("cls");//��յ�ͼ����ʾˢ�º�ĵ�ͼ
		for (i = 0; i < H; i++)
		{
			for (j = 0; j < L; j++)
			{

				printf("%c", GameMap[i][j]);
			}
			printf("\n");
		}
		printf("�����ⷽ�����ʼ��Ϸ");
	}
}

void Button()
{
	if (kbhit() != 0)//��鵱ǰ�Ƿ��м������룬�����򷵻�һ������ֵ
	{
		while (kbhit() != 0)
			key = getch();//�������ӿ���̨��ȡ�������浽kry��
		switch (key)
		{
		case 97:
		case 65:
			Snake[0].now = 0;
			break;
		case 100:
		case 68:
			Snake[0].now = 1;
			break;
		case 119:
		case 87:
			Snake[0].now = 2;
			break;
		case 115:
		case 83:
			Snake[0].now = 3;
			break;
		}
	}
}

void Move()
{
	int i, x, y;
	int t = sum;//�����ߵĳ���
				//��¼��ǰ��ͷ��λ�ã�������Ϊ�գ���ͷ���ƶ�
	x = Snake[0].x;
	y = Snake[0].y;
	GameMap[x][y] = '.';
	Snake[0].x = Snake[0].x + dx[Snake[0].now];
	Snake[0].y = Snake[0].y + dy[Snake[0].now];
	Check_Border();
	Check_Head(x, y);
	if (sum == t)
	{
		for (i = 0; i < sum; i++)
		{
			if (i == 1)
				GameMap[Snake[i].x][Snake[i].y] = '.';
			if (i == sum - 1)
			{
				Snake[i].x = x;
				Snake[i].y = y;
				Snake[i].now = Snake[0].now;
			}
			else
			{
				Snake[i].x = Snake[i + 1].x;
				Snake[i].y = Snake[i + 1].y;
				Snake[i].now = Snake[i + 1].now;
			}
			GameMap[Snake[i].x][Snake[i].y] = '#';//�ƶ���Ҫ��Ϊ��#��������
		}
	}

}

void Check_Border()
{
	if (Snake[0].x < 0 || Snake[0].x >= H || Snake[0].y < 0 || Snake[0].y >= L)
		over = 1;
}

void Check_Head(int x, int y)
{
	if (GameMap[Snake[0].x][Snake[0].y] == '.')
	{
		GameMap[Snake[0].x][Snake[0].y] = '@';
	}
	else if (GameMap[Snake[0].x][Snake[0].y] == '*')
	{
		GameMap[Snake[0].x][Snake[0].y] = '@';
		Snake[sum].x = x;
		Snake[sum].y = y;
		Snake[sum].now = Snake[0].now;
		GameMap[Snake[sum].x][Snake[sum].y] = '#';
		sum++;
		Create_Food();
	}
	else
		over = 1;
}
