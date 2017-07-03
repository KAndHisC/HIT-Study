#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LEN 15 //�ַ�����󳤶�
#define STU_NUM 50 //����ѧ������
#define COURSE_NUM 8 //���Ŀ��Կ�Ŀ��

typedef struct student
{
	char num[MAX_LEN]; //ÿ��ѧ����ѧ��
	char name[MAX_LEN]; //ÿ��ѧ��������
	float score[COURSE_NUM]; //ÿ��ѧ��COURSE_LEN�Ź��εĳɼ�
	float sum; //ÿ��ѧ�����ܳɼ�
	float aver; //ÿ��ѧ����ƽ���ɼ�
	float point; //ÿ��ѧ����ƽ��ѧ�ּ�
}STU;

int Menu(void);
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float *x, float *y);
void SwapLong(long *x, long *y);
void SwapChar(char x[], char y[]);
void AsSortbyNum(STU stu[], int n, int m);
void GradePoint(STU stu[], int n, int m);
void ReadScore(STU stu[], int n, int m);
void AverSumofEveryStudent(STU stu[], int n, int m);
void AverSumofEveryCourse(STU stu[], int n, int m);
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b));
void PrintScore(STU stu[], int n, int m);
void WritetoFile(STU record[], int n, int m);
void ReadfromFile(STU record[], int *n, int *m);
void SortbyName(STU stu[], int n, int m);
void SearchbyNum(STU stu[], int n, int m);
void SearchbyName(STU stu[], int n, int m);
void StatisticAnalysis(STU stu[], int n, int m);


/*  �������ܣ�����������ʾ�û�����������ݲ���������ø����
������ڲ�������
��������ֵ������������������0
*/
int main()
{
	system("color 80");
	char input;
	int n = 0, m = 0; //ѧ������Ϊn,�γ���m

	STU stu[STU_NUM];

	printf("\n*\t*\t*\t*\t��ӭ����ѧ���ɼ�����ϵͳ\t*\t*\t*\t*\n\n");
	printf("������ѧ��������50��֮�ڣ�\n>>>: ");

	while (scanf("%d", &n) != 1 || n > 50 || n <= 0)
	{
		while (getchar() != '\n');
		printf("����������ѧ��������50��֮�ڣ�\n>>>: ");

	}
	printf("������γ���Ŀ��8��֮�ڣ�\n>>>: ");

	while (scanf("%d", &m) != 1 || m > 8 || m <= 0)
	{
		while (getchar() != '\n');
		printf("����������γ���Ŀ��8��֮�ڣ�\n>>>:��");

	}
	printf("\n");

	while (1)
	{
		input = Menu();    //��ʾ�˵�������ȡ�û�����
		switch (input)
		{
		case 0:  printf("\n                                                ��ӭ���´�ʹ�ã�                                           \n");
			exit(1);
		case 1: ReadScore(stu, n, m);
			break;
		case 2: AverSumofEveryCourse(stu, n, m);
			break;
		case 3: AverSumofEveryStudent(stu, n, m);
			break;
		case 4: SortbyScore(stu, n, m, Descending);
			printf("\n���ִܷӸߵ�������\n");
			PrintScore(stu, n, m);
			break;
		case 5: SortbyScore(stu, n, m, Ascending);
			printf("\n���ִܷӵ͵�������\n");
			PrintScore(stu, n, m);
			break;
		case 6: AsSortbyNum(stu, n, m);
			printf("\n��ѧ�Ŵ�С��������\n");
			PrintScore(stu, n, m);
			break;
		case 7: SortbyName(stu, n, m);
			printf("\n���������ֵ�˳������\n");
			PrintScore(stu, n, m);
			break;
		case 8: SearchbyNum(stu, n, m);
			break;
		case 9: SearchbyName(stu, n, m);
			break;
		case 10: StatisticAnalysis(stu, n, m);
			break;
		case 11: PrintScore(stu, n, m);
			break;
		case 12: GradePoint(stu, n, m);
			break;
		case 13: WritetoFile(stu, n, m);
			break;
		case 14: ReadfromFile(stu, &n, &m);
			break;

		default: printf("�������");
		}
	}
	return 0;
}



/*  �������ܣ�����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void AverSumofEveryStudent(STU students[], int n, int m)
{
	int i, j;

	for (i = 0; i<n; i++)
	{
		students[i].sum = 0;
		for (j = 0; j<m; j++)
		{
			students[i].sum = students[i].sum + students[i].score[j];
		}
		students[i].aver = m>0 ? students[i].sum / m : -1;
		printf("ѧ�� %d: �ܳɼ� �� %.0f, ƽ���� �� %.0f\n", i + 1, students[i].sum, students[i].aver);
	}
}

/*  �������ܣ���ʾ�˵�������û����������ѡ��
������ڲ�����
��������ֵ�������û����������ѡ��itemSelected
*/
int Menu(void)
{
	int itemSelected;
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("* 1.¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�\t\t\t\t*\n");
	printf("* 2.����ÿ�ſγ̵��ֺܷ�ƽ����\t\t\t\t\t\t*\n");
	printf("* 3.����ÿ��ѧ�����ֺܷ�ƽ����\t\t\t\t\t\t*\n");
	printf("* 4.��ÿ��ѧ�����ִܷӸߵ����ų��ɼ���\t\t\t\t\t*\n");
	printf("* 5.��ÿ��ѧ�����ִܷӵ͵����ų��ɼ���\t\t\t\t\t*\n");
	printf("* 6.��ѧ����С�����ų��ɼ���\t\t\t\t\t\t*\n");
	printf("* 7.���������ֵ�˳���ų��ɼ���\t\t\t\t\t\t*\n");
	printf("* 8.��ѧ�Ų�ѯѧ���������俼�Գɼ�\t\t\t\t\t*\n");
	printf("* 9.��������ѯѧ��ѧ�ż��俼�Գɼ�\t\t\t\t\t*\n");
	printf("* 10.�ɼ����ݷ���\t\t\t\t\t\t\t*\n");
	printf("* 11.���ÿ��ѧ����ѧ�š����������ƿ��Գɼ��Լ�ÿ�ſγ̵��ֺܷ�ƽ����\t*\n");
	printf("* 12.����ÿλѧ����ƽ��ѧ�ּ�\t\t\t\t\t\t*\n");
	printf("* 13.��ÿ��ѧ���ļ�¼��Ϣд���ļ�\t\t\t\t\t*\n");
	printf("* 14.���ļ���ȡÿ��ѧ���ļ�¼��Ϣ\t\t\t\t\t*\n");
	printf("* 0. �˳�ϵͳ\t\t\t\t\t\t\t\t*\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n����������ѡ��:\n>>>: ");
	scanf("%d", &itemSelected);    //�����û�����
	return itemSelected;
}






/*  �������ܣ�����ѡ�񷨽�����sum��Ԫ��ֵ����
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����,ָ��Ascending��Descending�ĺ���ָ��*compare
��������ֵ����
*/
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b))
{
	int i, j, k, t;

	for (i = 0; i<n - 1; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
		{
			if ((*compare)(stu[j].sum, stu[k].sum))
				k = j;
		}
		if (k != i)
		{
			for (t = 0; t<m; t++)    //����m�ſγ̵ĳɼ�
			{
				SwapFloat(&stu[k].score[t], &stu[i].score[t]);
			}
			SwapFloat(&stu[k].sum, &stu[i].sum);    //�����ܷ�
			SwapFloat(&stu[k].aver, &stu[i].aver);    //����ƽ����
			SwapChar(stu[k].num, stu[i].num);    //����ѧ��
			SwapChar(stu[k].name, stu[i].name);    //��������
		}
	}
}

/*  �������ܣ�����n��ѧ����m�ſγ̳ɼ�
������ڲ������ṹ������stu[]�����α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void ReadScore(STU students[], int n, int m)
{
	int i, j;

	printf("������ѧ����ѧ�š������ͳɼ�\n");
	for (i = 0; i<n; i++)
	{
		scanf("%s%s", students[i].num, students[i].name);
		for (j = 0; j<m; j++)
		{
			scanf("%f", &students[i].score[j]);
		}
	}
	printf("\n");
}



/*  �������ܣ����������������ڴ�λ��
������ڲ�������Ҫ����������������
��������ֵ����
*/
void SwapFloat(float *x, float *y)
{
	float tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

/*  �������ܣ������������������ڴ�λ��
������ڲ�������Ҫ������������������
��������ֵ����
*/
void SwapLong(long *x, long *y)
{
	long tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}


/*  �������ܣ�����ÿ�ſγ̵��ֺܷ�ƽ����
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void AverSumofEveryCourse(STU stu[], int n, int m)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];

	for (j = 0; j<m; j++)
	{
		sum[j] = 0;
		for (i = 0; i<n; i++)
		{
			sum[j] = sum[j] + stu[i].score[j];
		}
		aver[j] = n>0 ? sum[j] / n : -1;
		printf("�γ� %d: �ܷ� �� %.0f, ƽ���� �� %.0f\n", j + 1, sum[j], aver[j]);
	}
}

/*  �������ܣ�ʹ������������
������ڲ�������Ҫ�Ƚϵ�����������
��������ֵ�����رȽϽ���Ĳ���ֵ
*/
int Ascending(float a, float b)
{
	return a < b;    //�����ȽϾ����˰������������a<b���򽻻�
}

/*  �������ܣ�ʹ���ݽ�������
������ڲ�������Ҫ�Ƚϵ�����������
��������ֵ�����رȽϽ���Ĳ���ֵ
*/
int Descending(float a, float b)
{
	return a > b;    //�����ȽϾ����˰������������a>b���򽻻�
}




/*  �������ܣ���ѧ�Ų���ѧ���ɼ�����ʾ���ҽ��
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void SearchbyNum(STU stu[], int n, int m)
{
	char numbers[MAX_LEN];
	int i, j;

	printf("��������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", numbers);    //������Ҫ���ҵ�ѧ��
	for (i = 0; i<n; i++)
	{
		if (strcmp(stu[i].num, numbers) == 0)    //�鵽
		{
			printf("%s\t%s\t", stu[i].num, stu[i].name);    //�����ѧ���Լ���Ӧ����
			for (j = 0; j<m; j++)
			{
				printf("%.0f\t", stu[i].score[j]);    //�����ѧ�Ŷ�Ӧ��m�ſγ̵ĳɼ�
			}
			printf("%.0f\t%.0f\n", stu[i].sum, stu[i].aver);    //�����ѧ�Ŷ�Ӧ���ֺܷ�ƽ����
			return;
		}
	}
	printf("û�з��ָ�ѧ����\n");
}


/*  �������ܣ���ѡ�񷨽��ַ�����num��Ԫ�ذ�˳������
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void AsSortbyNum(STU stu[], int n, int m)
{
	int i, j, k;

	for (i = 0; i<n - 1; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (strcmp(stu[j].num, stu[i].num) < 0)
			{
				for (k = 0; k<m; k++)    //����m�ſγ̵ĳɼ�
				{
					SwapFloat(&stu[i].score[k], &stu[j].score[k]);
				}
				SwapFloat(&stu[i].sum, &stu[j].sum);    //�����ܷ�
				SwapFloat(&stu[i].aver, &stu[j].aver);    //����ƽ����
				SwapChar(stu[i].num, stu[j].num);    //����ѧ��
				SwapChar(stu[i].name, stu[j].name);    //��������
			}
		}
	}
}

/*  �������ܣ�������ʵ���ַ������ֵ�˳������
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void SortbyName(STU stu[], int n, int m)
{
	int i, j, k;

	for (i = 0; i<n - 1; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (strcmp(stu[j].name, stu[i].name) < 0)
			{
				for (k = 0; k<m; k++)    //����m�ſγ̵ĳɼ�
				{
					SwapFloat(&stu[i].score[k], &stu[j].score[k]);
				}
				SwapFloat(&stu[i].sum, &stu[j].sum);    //�����ܷ�
				SwapFloat(&stu[i].aver, &stu[j].aver);    //����ƽ����
				SwapChar(stu[i].num, stu[j].num);    //����ѧ��
				SwapChar(stu[i].name, stu[j].name);    //��������
			}
		}
	}
}

/*  �������ܣ�����������ѧ���ɼ�����ʾ���ҽ��
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void SearchbyName(STU stu[], int n, int m)
{
	char x[MAX_LEN];
	int i, j;

	printf("��������Ҫ���ҵ�������");
	scanf("%s", x);    //������Ҫ���ҵ�����
	for (i = 0; i<n; i++)
	{
		if (strcmp(stu[i].name, x) == 0)    //�鵽
		{
			printf("%s\t%s\t", stu[i].num, stu[i].name);    //����������Լ���Ӧѧ��
			for (j = 0; j<m; j++)
			{
				printf("%.0f\t", stu[i].score[j]);    //�����������Ӧ��m�ſγ̵ĳɼ�
			}
			printf("%.0f\t%.0f\n", stu[i].sum, stu[i].aver);    //�����������Ӧ���ֺܷ�ƽ����
			return;
		}
	}
	printf("û�з��ָ�ѧ����\n");
}


/*  �������ܣ����ļ��ж�ȡѧ����ѧ�š��������ɼ�����Ϣд�뵽�ṹ������stu��
������ڲ�����ѧ����������stu[]��ѧ������n���γ���m
��������ֵ����
*/
void ReadfromFile(STU stu[], int *n, int *m)
{
	FILE *fp;
	int i, j;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	fscanf(fp, "%d\t%d", n, m);  //���ļ��ж���ѧ�������Ϳγ�����
	for (i = 0; i<*n; i++)  //ѧ������������nָ��Ĵ洢��Ԫ
	{
		fscanf(fp, "%10s", stu[i].num);
		fscanf(fp, "%10s", stu[i].name);
		for (j = 0; j<*m; j++)  //�γ�����������nָ��Ĵ洢��Ԫ
		{
			fscanf(fp, "%10f", &stu[i].score[j]);
		}
		fscanf(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
	}
	fclose(fp);
}


/*  �������ܣ����������ַ������ڴ�λ��
������ڲ�������Ҫ�����������ַ���
��������ֵ����
*/
void SwapChar(char x[], char y[])
{
	char tmp[MAX_LEN];
	strcpy(tmp, x);
	strcpy(x, y);
	strcpy(y, tmp);
}



/*  �������ܣ���ӡѧ���ɼ�
������ڲ�����ѧ����������stu[]��ѧ������n���γ���m
��������ֵ����
*/
void PrintScore(STU stu[], int n, int m)
{
	int i, j;

	for (i = 0; i<n; i++)
	{
		printf("%s\t%s\t", stu[i].num, stu[i].name);    //��ӡѧ�ź�����
		for (j = 0; j<m; j++)
		{
			printf("%.0f\t", stu[i].score[j]);    //��ӡm�ſγ̵ĳɼ�
		}
		printf("%.0f\t%.0f\n", stu[i].sum, stu[i].aver);    //��ӡ�ֺܷ�ƽ����
	}
}




/*  �������ܣ����n��ѧ����ѧ�š�������m�ſγ̵ĳɼ����ļ�student.txt��
������ڲ�����ѧ����������stu[]��ѧ������n���γ���m
��������ֵ����
*/
void WritetoFile(STU stu[], int n, int m)
{
	FILE *fp;
	int i, j;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	fprintf(fp, "%d\t%d\n", n, m);  //��ѧ�������Ϳγ�����д���ļ�
	for (i = 0; i<n; i++)
	{
		fprintf(fp, "%10s%10s", stu[i].num, stu[i].name);
		for (j = 0; j<m; j++)
		{
			fprintf(fp, "%10.0f", stu[i].score[j]);
		}
		fprintf(fp, "%10.0f%10.0f\n", stu[i].sum, stu[i].aver);
	}
	fclose(fp);
}


/*  �������ܣ�����ƽ��ѧ�ּ�
������ڲ�����ѧ����������stu[]��ѧ������n���γ���m
��������ֵ����
*/
void GradePoint(STU stu[], int n, int m)
{
	float grade[COURSE_NUM];
	int i, j, sum = 0;

	printf("������ÿ�ſγ̵�ѧ�֣�");
	for (i = 0; i<m; i++)
	{
		scanf("%f", &grade[i]);
		sum += grade[i];
	}
	for (i = 0; i<n; i++)
	{
		stu[i].point = 0;
		for (j = 0; j<m; j++)
		{
			stu[i].point += (stu[i].score[j])*grade[j];
		}
		printf("ѧ�� %d: ƽ��ѧ�ּ�: %.0f\n", i + 1, (stu[i].point) / sum);
	}
}



/*  �������ܣ�ͳ�Ƹ������ε�ѧ����������ռ�İٷֱ�
������ڲ������ṹ������stu[],���α���n��ʾѧ�����������α���m��ʾ�γ�����
��������ֵ����
*/
void StatisticAnalysis(STU stu[], int n, int m)
{
	int i, j, t[6];

	for (j = 0; j<m; j++)
	{
		printf("���ڿγ�%d:\n", j + 1);
		memset(t, 0, sizeof(t));    //������t��ȫ��Ԫ�س�ʼ��Ϊ��
		for (i = 0; i<n; i++)
		{
			if (stu[i].score[j] >= 0 && stu[i].score[j]<60) t[0]++;
			else if (stu[i].score[j]<70)   t[1]++;
			else if (stu[i].score[j]<80)   t[2]++;
			else if (stu[i].score[j]<90)   t[3]++;
			else if (stu[i].score[j]<100)  t[4]++;
			else if (stu[i].score[j] == 100) t[5]++;
		}
		for (i = 0; i <= 5; i++)
		{
			if (i == 0)
				printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);    //�������������ٷֱ�
			else if (i == 5)
				printf("%d\t%d\t%.2f%%\n", (i + 5) * 10, t[i], (float)t[i] / n * 100);    //�����������ٷֱ�
			else printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100); //�����������������ٷֱ�
		}
	}
}



