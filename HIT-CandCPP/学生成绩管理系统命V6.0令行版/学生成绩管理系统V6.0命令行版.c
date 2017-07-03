#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define STUDENTS 30	//ѧ������
#define COURSE 6	//�γ�������
#define NAME 15		//������������
#define MAXLEN 7	//�������������

typedef struct MyStruct
{
	long number;		//ѧ��
	int totalscore;		//�ܷ�
	double averscore;	//ƽ����
	int score[COURSE];	//���Ƴɼ�
	char name[NAME];	//����
}STU;   //���ڴ洢ѧ����Ϣ�Ľṹ��

typedef struct MyStruct2
{
	int courseN;			//�γ���
	int Iniflag;			//��ʼ��״̬
	int Successfulnumber;	//�ѵǼ�����
	int sortflag;			//��ǰ����״̬	
}FLAG;	//���ڴ洢��������״̬�Ľṹ��

int Initialization(FLAG *flag);

int AnalyzeOrder(char ml[], int x);
/*����:�����û����������
����:�洢�û���������������,�Լ���������
����ֵ:��Ӧ��������ּǺ�
*/
int SearchStudent(FLAG*flag, STU student[], int x);
/*����:��������ѯѧ����Ϣ
����:flag�Ǳ��������״̬�ļ���,student[]������ѧ����Ϣ,xΪ��ѯ������
����ֵ:��Ӧѧ��������ѧ����Ϣ�����е��±�
*/
void NewStudent(FLAG *flag, STU student[]);
/*����:�����½�ѧ����Ϣ
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void ModifyStudent(FLAG *flag, STU student[]);
/*����:�޸�ָ��ѧ����Ϣ
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void ReadStudent(FLAG *flag, STU stu[]);
/*����:��ȡ�ļ��е�ѧ����Ϣ
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void ListStudent(FLAG*flag, STU student[]);
/*����:��Ҫ������û�������ָ��,�����հ�Ҫ���ӡѧ���ɼ���
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void DeleteStudent(FLAG *flag, STU student[]);
/*����:�����û�ɾ��ָ��ѧ����Ϣ
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void WriteStudent(FLAG *flag, STU student[],int x);
/*����:��ѧ����Ϣ�������Ӧ�ļ���
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void SortName(FLAG *flag, STU student[], int mode);
/*����:��ѧ����Ϣ����������������
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void SortScore(FLAG *flag, STU student[], int mode);
/*����:��ѧ����Ϣ�����ֽܷ�������
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void SortNumber(FLAG *flag, STU student[], int mode);
/*����:��ѧ����Ϣ����ѧ�Ž�������
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ
����ֵ:��
*/
void PrintStudent(FLAG*flag, STU student[], int x);
/*����:���ѧ���ĳɼ���
����:flag�Ǳ��������״̬�ļ���,student[]���ڴ洢����ѧ����Ϣ,x��ָ�������ѧ���±�
����ֵ:��
*/
void Swap(STU *x,STU *y);
/*����:����ѧ����Ϣ�洢��λ��
����:��Ҫ����λ�õ�����ѧ����Ϣ
����ֵ:��
*/
void ViewHelp(void);
/*����:���������Ϣ����
����:��
����ֵ:��
*/
void PutMenu(void);
/*����:��ӡ���ܲ˵�
����:��
����ֵ:��
*/

int main(int argc, char* arvg[])
{	
	STU student[STUDENTS];		//��������ѧ����Ϣ������
	FLAG Flag = { -1,1,0 ,0 };	//�������ڴ洢�����������״̬�Ľṹ��
	int  i;
	char ml[MAXLEN] = { 0 };

	//��ӭ����
	puts("��ӭʹ��ѧ���ɼ������ն�! --����HIT1163710227�ڴ�");
	PutMenu();
	ReadStudent(&Flag, student);

	//��ʼ����
	while (Initialization(&Flag)) {
		printf("\n������������в���:>>> ");
		while (!scanf("%4s", ml))//������
		{
			puts("��Ч�������������\n");
			while (getchar() != '\n');
		}
		switch (AnalyzeOrder(ml, 1))//����ָ��������������ܺ���
		{
		case 0:
			NewStudent(&Flag, student); break;
		case 1:
			DeleteStudent(&Flag, student);   break;
		case 2:
			ModifyStudent(&Flag, student);  break;
		case 3:
			i = -1;
			i = SearchStudent(&Flag, student, -1);
			if (i > -1)PrintStudent(&Flag, student, i); break;
		case 4:
			ListStudent(&Flag, student);  break;
		case 5:
			ReadStudent(&Flag, student);  break;
		case 6:
			WriteStudent(&Flag, student,0);  break;
		case 7:
			ViewHelp(); break;
		case 8:
			PutMenu(); break;
		case 9:
			WriteStudent(&Flag, student,1); exit(1); break;
		default:
			printf("'%s'������Ч����,����������:", ml); break;
		}
	}

	//����ԭ���˳�
	puts("�쳣�˳�!!!");
	return 0;
}

void PutMenu(void) {

	system("cls");//����

	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\
\t\t* ����������:								*\n\
\t\t* new n(n<=30) �½�ѧ����Ϣ						*\n\
\t\t* del name/number ������/ѧ�Ų��Ҳ�ɾ��ѧ����Ϣ				*\n\
\t\t* re  name/number ������/ѧ�Ų��Ҳ��޸�ѧ����Ϣ				*\n\
\t\t* sch name/number ������/ѧ�Ų���ѧ����Ϣ				*\n\
\t\t* ls  score/name/number asc/desc ������/ѧ��/���� ����/���� ��ӡ�ɼ���	*\n\
\t\t* rd  xxx ��ȡ�ļ�xxx							*\n\
\t\t* wr  xxx �����ļ���xxx							*\n\
\t\t* help xx �鿴xx�������ϸ������Ϣ					*\n\
\t\t* menu �鿴���˵�							*\n\
\t\t* exit �Զ��������ݲ��˳�����						*\n\
\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
}

int Initialization(FLAG *flag) {
	if (flag->Iniflag) {//�Զ�����ʧ��,Ҫ���û��ֶ�����������
		printf("\n�����뱾�ο�����Ч��Ŀ��n,(n<=6):\n");
		while (!scanf("%2d", &flag->courseN) ||flag->courseN >6 || flag->courseN<0)
		{
			puts("��������,����������\n");
			while (getchar() != '\n');
		}
		flag->Iniflag = 0;
	}

	while(getchar() != '\n');//��ջ�����
	return 1;
}

void NewStudent(FLAG *flag,STU student[]) {
	int n = flag->courseN,m=flag->Successfulnumber;
	int i=0, j=0, number = 0;

	//���뼰������
	if (!scanf("%2d", &number)||number<1||number+m >STUDENTS) {
		puts("�����ѧ��������Ч��Խ��,�½�ѧ����Ϣʧ��!");
	}else {//��������,��ȡѧ����Ϣ,�������ܷ�ƽ����
		printf("�밴���¸�ʽ����%d��ѧ������Ϣ:\n",number);
		printf("����\tѧ��");
		for (i = 0; i < n; i++)printf("\t��Ŀ%d", i + 1);
		printf("\n");
		for (i = 0; i < number; i++) {
			scanf("%14s%ld",student[m+i].name,&student[m+i].number);
			student[i].totalscore = 0;
			for (j = 0; j < n; j++) { 
				scanf("%3d", &student[m + i].score[j]);
				student[i].totalscore += student[i].score[j];
			}
			student[i].averscore = student[i].totalscore / flag->courseN;
			flag->Successfulnumber++;//ÿ��ȡһ��ѧ����Ϣ,�ɹ���ȡ��Ϣ������һ
		}
	}
	flag->sortflag = -1;//������Ϣд��,��Ҫ��������
}

void ModifyStudent(FLAG *flag, STU student[]) {
	char ml[7] = { 0 };
	int n = -1, x = -1, i =0;

	if (!scanf("%6s", ml))//��ȡ������
	{
		puts("��Ч����,����������\n");
		return;
	}

	//�����������ѧ����Ϣ
	n = AnalyzeOrder(ml, 2);
	if (n == 1 || n == 2)x = SearchStudent(flag, student, n);
	else printf("'re %s'������Чָ��,����������", ml);

	if (x != -1) {//�����û��޸�ѧ����Ϣ
		printf("�밴���¸�ʽ������ȷ��ѧ����Ϣ:\n");
		printf("����\tѧ��");
		for (i = 0; i < n; i++)printf("\t��Ŀ%d", i + 1);
		printf("\n");
		scanf("%14s%ld", student[x].name, &student[x].number);
		student[x].totalscore = 0;
		for (i = 0; i < flag->courseN; i++) {
				scanf("%3d", &student[x].score[i]);
				student[x].totalscore += student[x].score[i];
			}
		student[x].averscore = student[x].totalscore / flag->courseN;
		flag->sortflag = -1;//����Ϣ�Ķ�,��Ҫ��������
	}
}

void ReadStudent(FLAG *flag,STU student[]) {
	FILE *fp;
	char filename[20] = {0};
	char *file = "student.txt";
	int i, j;
	
	//���ļ�
	if (flag->Iniflag ) {
		fp = fopen(file, "r");
	}else {
		while (!scanf("%19s", filename)) {
			puts("��������ȷ�ļ���ַ���ļ���");
			while (getchar() != '\n');
		}
		fp = fopen(filename, "r");
	}

	if (fp != NULL) {//�򿪳ɹ����ȡ�ļ�
		fscanf(fp,"%1d%2d",&flag->courseN,&flag->Successfulnumber);
		for (i = 0; i < flag->Successfulnumber; i++) {
			student[i].totalscore = 0;
			fscanf(fp, "%14s%ld", &student[i].name, &student[i].number);
			for (j = 0; j < flag->courseN; j++){
				fscanf(fp,"%3d",&student[i].score[j]);
				student[i].totalscore += student[i].score[j];
			}
			fscanf(fp, "%*d%*lf");
			student[i].averscore = student[i].totalscore / flag->courseN;
		}
		fclose(fp);
		flag->sortflag = -1;
		flag->Iniflag = 0;
		puts("��ȡ�浵�ɹ�,���س�������") ;
	}else if (flag->Iniflag)puts("�Զ�����ʧ��!");
	else puts("��ȡʧ��!!!");//��ʧ�������ԭ�򱨳�����
}

void WriteStudent(FLAG *flag, STU student[],int x) {
	FILE *fp;
	char filename[20] = { 0 };
	char *file = "student.txt";
	int i=0, j=0;

	//���ļ�
	if (x) {
		fp = fopen(file, "w");
	}else {
		while (!scanf("%19s", filename)) {
			puts("��������ȷ�ļ���ַ���ļ���");
			while (getchar() != '\n');
		}
		fp = fopen(filename, "w");
	}

	if (fp != NULL) {//�򿪳ɹ������ѧ����Ϣ
		fprintf(fp,"%d\t%d",flag->courseN,flag->Successfulnumber);
		for (i = 0; i < flag->Successfulnumber; i++) {
			fprintf(fp, "\n%s\t%ld", student[i].name,student[i].number);
			for (j = 0; j < flag->courseN; j++) {
				fprintf(fp, "\t%d", student[i].score[j]);
			}
			fprintf(fp, "\t%d\t%.1f",student[i].totalscore,student[i].averscore);
		}
		fclose(fp);
	}else puts("����ʧ��!");//��ʧ���򱨴�
}

void Swap(STU *x, STU *y) {//��������ѧ����Ϣ
	STU temp=*x;
	*x = *y;
	*y = temp;
}

void SortName(FLAG *flag,STU student[],int mode) {
	int i = 0, j = 0, k = 0;
	int temp;

	//����������������ظ�����
	if (flag->sortflag == 10+mode)return;
	for (i = 0; i < flag->Successfulnumber - 1; i++) {
		k = i;
		for (j = i + 1; j < flag->Successfulnumber; j++){
			temp = strcmp(student[j].name, student[k].name);
			if (mode == 4)temp = -temp;
			if ( temp< 0)k = j;
		}
		if (k != i)Swap(&student[k],&student[i]);
	}
	flag->sortflag = 10+mode;//������ɺ��ǵ�ǰ����״̬
}

void SortScore(FLAG *flag, STU student[], int mode) {
	int i = 0, j = 0, k = 0;
	int temp;

	//����������򲻱��ظ�����
	if (flag->sortflag == mode)return;
	for (i = 0; i < flag->Successfulnumber - 1; i++) {
		k = i;
		for (j = i + 1; j < flag->Successfulnumber; j++) {
			temp = (student[j].totalscore<student[k].totalscore);
			if (mode == 4)temp = !temp;
			if (temp)k = j;
		}
		if (k != i)Swap(&student[k], &student[i]);
	}
	flag->sortflag = mode;//����������ǵ�ǰ����״̬
}

void SortNumber(FLAG *flag, STU student[], int mode) {
	int i = 0, j = 0, k = 0;
	int temp;

	//����������������ظ�����
	if (flag->sortflag == 20+mode)return;
	for (i = 0; i < flag->Successfulnumber - 1; i++) {
		k = i;
		for (j = i + 1; j < flag->Successfulnumber; j++) {
			temp = (student[j].number<student[k].number);
			if (mode == 4)temp = !temp;
			if (temp)k = j;
		}
		if (k != i)Swap(&student[k], &student[i]);
	}
	flag->sortflag = 20+mode;//������ɺ�������״̬
}

int AnalyzeOrder(char ml[], int x) {
	const char ML1[10][5] = { "new","del","re","sch","ls","rd","wr","help","menu","exit" };
	const char ML2[5][7] = { "score","name","number","asc","desc" };
	int i;//�������ڴ洢��Ч���������

	if (x == 1) {
		for (i = 0; i < 10;i++)if (strcmp(ml, ML1[i]) == 0)return i;	
	}
	else if (x == 2) {
		for (i = 0; i < 5;i++)if (strcmp(ml, ML2[i]) == 0)return i;
	}
	return -1;//ƥ�䲻�ɹ��򷵻�-1
}

void ListStudent(FLAG*flag, STU student[]) {
	char ml1[7] = { 0 }, ml2[5] = { 0 };
	int n = -1, m = -1;

	//��ȡ������
	if (scanf("%s %s", ml1, ml2) != 2) {
		printf("'ls %s %s'�����������������Ч����!\n", ml1, ml2);
		return;
	}

	n = AnalyzeOrder(ml1, 2);
	m = AnalyzeOrder(ml2, 2);
	if ( m == 3 || m == 4)
	{//������������,���������������Ϣ
		switch (n)
		{
		case 0:SortScore(flag, student, m); break;
		case 1:SortName(flag, student, m); break;
		case 2:SortNumber(flag, student, m); break;
		default:printf("'%s %s'������Ч���������!\n", ml1, ml2);
			break;
		}
		PrintStudent(flag, student,-1);
	}
	else { //���������������Ϣ
		printf("'%s %s'������Ч���������!\n",ml1,ml2);
		return;
	}
}

int SearchStudent(FLAG*flag, STU student[], int x) {
	char ml[7] = { 0 }, name[NAME] = {0};
	long number = 0;
	int i=0, n = flag->Successfulnumber;

	//δ֪�����������ȶ�ȡ���������������
	if (x == -1) {
		scanf("%6s", ml);
		x = AnalyzeOrder(ml, 2);
	}
	if (x == -1) printf("'sch %s'������Ч������,����������!\n", ml);

	if (x == 1) { //���������������±�
		printf("������ָ��ѧ��������:");
		scanf("%14s", name);
		for (i = 0; i < n; i++) {
			if (strcmp(name, student[i].name) == 0)
				return i;
		}
	}else if (x == 2) { //����ѧ�Ų������±�
		printf("������ָ��ѧ����ѧ��:");
		scanf("%ld", &number);
		for (i = 0; i <n; i++) {
			if (number == student[i].number)
				return i;
		}
	}

	puts("δ��������ѧ����Ϣ!");
	return -1;//δ����������-1
}

void DeleteStudent(FLAG *flag, STU student[]) {
	char ml[7] = { 0 };
	int n=-1,x=-1,i=flag->Successfulnumber-1;

	//�ӻ�������ȡָ������򱨴�
	if (!scanf("%6s", ml))
	{
		puts("��Ч����,����������\n");
		return;
	}

	n = AnalyzeOrder(ml, 2);
	if(n==1||n==2)x = SearchStudent(flag,student,n);
	else printf("'del %s'������Чָ��,����������",ml);

	if (x != -1) {//������ѧ����Ϣ�������һ����Ϣ���Ǹ���Ϣ
		if (x != i) { 
			student[x] = student[i];
			flag->sortflag = -1;//��Ϣ�䶯��Ҫ��������
		}
		flag->Successfulnumber--;//�ѵǼ�������һ
	}
}

void ViewHelp(void) {
	char ml2[5];

	scanf("%4s",ml2);
	switch (AnalyzeOrder(ml2,1))//����ָ��ֱ������Ӧ��ϸ����
	{
	case 0:puts("new n���������½�n(<30��)��ѧ����Ϣ,�����ָ��������½�ѧ����Ϣ"); break;
	case 1:puts("del name/numble�������ڰ�����/ѧ������ѧ����Ϣ��ɾ��"); break;
	case 2:puts("re name/numble�������ڰ�����/ѧ�ż���ѧ����Ϣ���޸�"); break;
	case 3:puts("sch name/numble�������ڰ�����/ѧ�ż���ѧ����Ϣ"); break;
	case 4:puts("ls name/numble/score asc/desc���������������,\n��ʾ��������/ѧ��/�ֽܷ�����/����������ӡ�ɼ���"); break;
	case 5:puts("rd xxx���ڶ�ȡ�ɼ��浵,xxxΪ�ļ���ַ���ļ���"); break;
	case 6:puts("wr xxx���ڵ����ɼ��浵�ļ�,xxxΪ�ļ���ַ���ļ���"); break;
	case 7:puts("help xx�������ڲ鿴xx�������ϸʹ�ð���"); break;
	case 8:puts("menu �������ڲ鿴����˵�"); break;
	case 9:puts("exit �������ڱ��沢�˳�����,Ĭ�ϱ�����ڳ���ͬĿ¼��student.txt�ļ���"); break;
	default:
		printf("' %s'������Ч�����������ȷ����",ml2);
		break;
	}
}

void PrintStudent(FLAG *flag, STU student[],int x) {
	int i = 0,j=0;

	//��ӡ��ͷ
	printf("\n����\tѧ��");
	for (i = 0; i < flag->courseN; i++)printf("\t��Ŀ%d", i + 1);
	printf("\t�ܷ�\tƽ����");

	if (x != -1) {//���ָ��ѧ����Ϣ
		printf("\n%s\t%ld", student[x].name, student[x].number);
		for (i = 0; i <flag->courseN; i++)
			printf("\t%d", student[x].score[i]);
		printf("\t%d\t%.1f",student[x].totalscore,student[x].averscore);
	}
	else for (i = 0; i < flag->Successfulnumber; i++) {
		//���ȫ�� ѧ����Ϣ
		printf("\n%s\t%ld", student[i].name, student[i].number);
		for (j = 0; j < flag->courseN; j++)
			printf("\t%d", student[i].score[j]);
		printf("\t%d\t%.1f", student[i].totalscore, student[i].averscore);
	}
}