#include<stdio.h>
#include<math.h>
int count = 0;//������Ч�����ж�������ʱ��ifʹ�ô����ɷ���
int Isprime(int n) {//�ж�����
	int i;
	for (i = 3; i <= sqrt(n); i++)
	{ count++; if (!(n%i))return 0; }
	return 1;
}
void counter(int m, int mode) {//�����㷨
	int i,flag=0;
	if (!((m / 2) % 2))flag=1;//�ж϶��ֵ��Ƿ������������ǣ��Ӽ�1ʹ֮Ϊ����
	if (mode == 1)
	{for (i = m / 2+flag; i < m; i+=2)if (Isprime(i)&&Isprime(m - i))printf("(%d,%d)", i, m - i);}
	else {for (i = m / 2-flag; i>0 ; i-=2)if (Isprime(i)&&Isprime(m - i))printf("(%d,%d)", i, m - i);}
	printf("\nif��ʹ�ô���:%d\n", count);
}
int main() {//��������
	int numble = 1,mode=-1;
	char c=0;
	 do{
		numble = 1, mode = -1; count = 0; c = 0;
		while (numble % 2)
		{
			printf("������һ��ż��:"); scanf("%d", &numble);
		}
		while (mode != 1 && mode != 0)
		{
			printf("����1���ϼ���,����0���¼���:"); scanf("%d", &mode);
		}
		counter(numble, mode);
		printf("�����������,��ESC�˳�\n");
	 } while ( getch()!= 27);
	return 0;
}