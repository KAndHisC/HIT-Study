#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#define MAXXY 15 //���̴�С
int p[MAXXY][MAXXY] = {0};//�Ծ���Ϣ
short Cx, Cy, cx, cy;//��ǰ���λ�ú���һ�ι��λ��
int now = 1,count = 0;//�ڷ����֣�ͳ�ƻغ���
int victor;//��¼ʤ����Ϣ
HANDLE hOut;
COORD pos;

void print(void) {//��ӡ����
	int i;
	printf("��������������������������������������������������������������\n"); 
	printf("�������ө��ө��ө��ө��ө��ө��ө��ө��ө��ө��ө��ө��ө�����\n");
	for (i = 3; i < 30; i++) 
	{
		if ((i % 2) == 1 && i != 31)
			printf("��������������������������������������������������������������\n");
		else printf("���ġ��ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�ࡪ�̡�\n");
	}
	printf("�������۩��۩��۩��۩��۩��۩��۩��۩��۩��۩��۩��۩��۩�����\n");
	printf("��������������������������������������������������������������\n");
}

void sign(void){//��ʾ���ͼ��
	 pos = { 4 * (cx - 1),2 * (cy-1 ) }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * cx ,2 * (cy - 1) }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * (cx - 1),2 * cy }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * cx ,2 * cy  }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 if (Cx<1)Cx = MAXXY;//������λ��Խ�����ƶ����Բ�
	 if (Cy<1)Cy = MAXXY;
	 if (Cx>MAXXY)Cx = 1;
	 if (Cy>MAXXY)Cy = 1;
	 pos = { 4 * (Cx - 1),2 * (Cy - 1) }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * Cx ,2 * (Cy - 1) }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * (Cx - 1),2 * Cy }; SetConsoleCursorPosition(hOut, pos); printf("��");
	 pos = { 4 * Cx ,2 * Cy }; SetConsoleCursorPosition(hOut, pos); printf("��");
}

int put(void) {//�ڵ�ǰ���λ�����ӣ�����ǿգ��򷵻�0��ʾʧ��
		if (p[Cx-1][Cy-1] == 0)
		{
			p[Cx-1][Cy-1] = now;//�ı��λ������
			pos = { (4 * Cx)-2,2 * Cy-1 };
			SetConsoleCursorPosition(hOut, pos);
			if(now==1)printf("��");else printf("��"); 
			count++;
			return 1;//����1��ʾ�ɹ�
		}
		else return 0;		
	}

int Check(void)//ʤ����飬���жϵ�ǰ����λ����û���������������
{
	int w = 1, x = 1, y = 1, z = 1, i;//�ۼƺ�����б��б�ĸ������������ͬ������Ŀ
	for (i = 1; i<5; i++)if (Cy + i<MAXXY&&p[Cx-1][Cy-1 + i] == now)w++; else break;//���¼��
	for (i = 1; i<5; i++)if (Cy - i>0 && p[Cx-1][Cy-1 - i] == now)w++; else break;//���ϼ��
	if (w >= 5)return now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
	for (i = 1; i<5; i++)if (Cx + i<MAXXY&&p[Cx-1 + i][Cy-1] == now)x++; else break;//���Ҽ��
	for (i = 1; i<5; i++)if (Cx - i>0 && p[Cx-1 - i][Cy] == now)x++; else break;//������
	if (x >= 5)return now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
	for (i = 1; i<5; i++)if (Cx + i<MAXXY&&Cy + i<MAXXY&&p[Cx -1+ i][Cy-1 + i] == now)y++; else break;//�����¼��
	for (i = 1; i<5; i++)if (Cx - i>0 && Cy - i>0 && p[Cx-1 - i][Cy-1 - i] == now)y++; else break;//�����ϼ��
	if (y >= 5)return now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
	for (i = 1; i<5; i++)if (Cx + i<MAXXY&&Cy - i>0 && p[Cx-1 + i][Cy -1- i] == now)z++; else break;//�����ϼ��
	for (i = 1; i<5; i++)if (Cx - i>0 && Cy + i<MAXXY&&p[Cx-1 - i][Cy-1 + i] == now)z++; else break;//�����¼��
	if (z >= 5)return now;//�����ﵽ5�����жϵ�ǰ�������ΪӮ��
	return 0;//��û�м�鵽�����飬�򷵻�0��ʾ��û����Ҵ��ʤ��
}

void begin(void) {
	int i, j;
	for(i=0;i<MAXXY;i++)for(j=0;j<MAXXY;j++)p[i][j] =  0 ;
	Cx = Cy = cx = cy = 8;
	victor = 0; count = 0; now = 1;
	print();
	sign();
}

void RunGame(void) { //��Ϸ��ʼ
	begin();
	int input;
	while((input=getch())!= 27)
	{
		if (input == 0x20)//����ǿո���ʼ����
		{
			if (put()) { victor = Check(); now = 3 - now; if (victor!=0)break; }
		}
		else if (input == 0xE0)//������µ��Ƿ������������������룬��һ��Ϊ0xE0��ʾ���µ��ǿ��Ƽ�
		{
			input = getch();//��õڶ���������Ϣ
			cx = Cx; cy = Cy;
			switch (input)//�жϷ���������ƶ����λ��
			{
			case 0x4B:
				Cx--;
				break;
			case 0x48:
				Cy--;
				break;
			case 0x4D:
				Cx++;
				break;
			case 0x50:
				Cy++;
				break;
			}
			sign();
		}		
	}
	if (input == 27)exit(0);
	pos = { 30,16 };
	if (victor == 1)printf("�ڷ�ʤ���������������");
	else if (victor == 2)printf("�׷�ʤ���������������");
	else if (count == 15 * 15)printf("ƽ�֣������������");
	getch();
}

int main(void)//������
{
	system("title �ڴ���������");//���ñ���,�Ա�SetConsoleTitle("�ڴ���������");
	system("mode con cols=63 lines=33");//���ô��ڴ�С
	system("color 80");//������ɫ
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	while(1)RunGame();//ѭ��ִ����Ϸ
}