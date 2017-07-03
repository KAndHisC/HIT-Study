#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define COURSE_NUM 6
#define STU_NUM 30
#define MAX_LEN 10
typedef struct student
{
    long num;
    char name[MAX_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
    struct student * next;
}STU;
int Login(void);
int Menu(void);
STU * ReadScore(STU *head,int n,int m,char coursename[][MAX_LEN],int maxscore[]);
STU * AverSumofEveryStudent(STU *head,int n,int m);
void AverSumofEveryCourse(STU *head,int n,int m,char coursename[][MAX_LEN]);
STU * SortbyScore(STU *head,int n,int m,int (*compare)(float a,float b));
int Ascending(float a,float b);
int Descending(float a,float b);
void SwapFloat(float *x,float *y);
void SwapLong(long *x,long *y);
void SwapChar(char x[],char y[]);
STU * AsSortbyNum(STU *head,int n,int m);
STU * SortbyName(STU *head,int n,int m);
void SearchbyNum(STU *head,int n,int m,char coursename[][MAX_LEN]);
void SearchbyName(STU *head,int n,int m,char coursename[][MAX_LEN]);
void StatisticAnalysis(STU *head,int n,int m,char coursename[][MAX_LEN],int max[]);
void PrintScore(STU *head,int n,int m,char coursename[][MAX_LEN]);
void AverSumofEveryStudent2(STU *head,int n,int m);/*ר��дһ���������ڼ���ƽ��ֵ���ܷ�ֻ�ǲ�����Ļ���*/
void WritetoFile(STU *head,int n,int m,char coursename[][MAX_LEN],int max[]);
STU * ReadfromFlie(int *n,int *m,char coursename[][MAX_LEN],int max[]);
int DeleteMemory(STU *head);
STU *AppendEmptyNode(STU *head,int n,int m);
STU *DeleteNode(STU *head,int *n);
STU *Adddata(STU *head,int m,char coursename[][MAX_LEN],int *n);

int main()
{
    int i,n,m,t,l,item,iscls,maxscore[COURSE_NUM];
    int canlogin,logintimes;
    STU * head  = NULL;
    char coursename[COURSE_NUM][MAX_LEN];
    for(logintimes = 0;logintimes < 3;logintimes++)
    {
        canlogin = Login();
        if(canlogin == 1)
        {
            printf("Logining Please wait!\n");
            for(i = 0;i < 1e9;i++);//ͨ������û�����ݵ�ѭ������ʱ��ģ����صĹ���
            printf("Welcome to our program!\n");
            for(i = 0;i < 1e9;i++);//�����������
            do
            {
                fflush(stdin);
                printf("Input student number(n <= %d):",STU_NUM);
                t = scanf("%d",&n);
                printf("Input course number(m <= %d)\n",COURSE_NUM);
                l = scanf("%d",&m);
            }while(n <= 0 || m <= 0 || n > STU_NUM || m > COURSE_NUM || t != 1 || l != 1);/*����ѧ��������n�Լ���Ŀ������m���Ҷ���������ݼӼ��Լ��*/
            while(1)
            {
                item = Menu();
                switch(item)
                {
                case 1:
                    head = ReadScore(head,n,m,coursename,maxscore);
                    break;
                case 2:
                    AverSumofEveryCourse(head,n,m,coursename);
                    break;
                case 3:
                    head = AverSumofEveryStudent(head,n,m);
                    break;
                case 4:
                    SortbyScore(head,n,m,Descending);//��Descending�����ĵ�ַ��������ָ��
                    printf("\nSort in descending order by score:\n");
                    PrintScore(head,n,m,coursename);
                    break;
                case 5:
                    SortbyScore(head,n,m,Ascending);//��Aescending�����ĵ�ַ��������ָ��
                    printf("\nSort in ascending order by score:\n");
                    PrintScore(head,n,m,coursename);
                    break;
                case 6:
                    AsSortbyNum(head,n,m);
                    printf("\nSort in ascending order by number:\n");
                    PrintScore(head,n,m,coursename);
                    break;
                case 7:
                    head = SortbyName(head,n,m);
                    printf("\nSort in dictionary number by name:\n");
                    PrintScore(head,n,m,coursename);
                    break;
                case 8:
                    SearchbyNum(head,n,m,coursename);
                    break;
                case 9:
                    SearchbyName(head,n,m,coursename);
                    break;
                case 10:
                    StatisticAnalysis(head,n,m,coursename,maxscore);
                    break;
                case 11:
                    PrintScore(head,n,m,coursename);
                    break;
                case 12:
                    WritetoFile(head,n,m,coursename,maxscore);
                    break;
                case 13:
                    head = ReadfromFlie(&n,&m,coursename,maxscore);
                    PrintScore(head,n,m,coursename);
                    break;
                case 14:
                    head = DeleteNode(head,&n);
                    break;
                case 15:
                    head = Adddata(head,m,coursename,&n);
                    break;
                case 0:
                    printf("Exiting Please wait!\n");
                    for(i = 0;i < 1e9;i++);//��ʱѭ��ģ���˳��Ĺ���
                    printf("End of program!Look forward to seeing you again!\n");
                    i = DeleteMemory(head);
                    if(i == 1)
                        printf("Memory has been deleted!\n");
                    exit(0);
                default:
                    printf("Input arrow!\n");
                }
            }
            printf("\nInput 1 if you want to clear screen!\n");
            scanf("%d",&iscls);//���ڱ����û��Ļش�
            if(iscls == 1)
            {
            system("cls"); //���ú���������ʹ��Ļ��
            }
        }
        else if(logintimes < 2)
        {
            printf("Wrong name!Please try again!\n");
        }
    }
    printf("Wrong!You have tried three times!Program closed!\n");
    return 0;
}

/*�����ӿڣ���
  �������ܣ�ģ���û���½
  ��������ֵ����½�ɹ�Ϊ1����Ϊ0*/
int Login(void)
{
    char name[7][MAX_LEN] = {"����","����","��ͥ��","������","����Ԫ","����Ⱥ","������"};
    char name2[MAX_LEN];
    int i;
    printf("Name:");
    gets(name2);
    for(i = 0;i <7;i++)
    {
        if(strcmp(name2,name[i]) == 0)
            return 1;
    }
    return 0;
}

/*�����ӿڣ���
  �������ܣ���ʾ�˵����û�ѡ����Ӧ�Ĺ��ܲ����ڵ�һ������ʱ����ѡ��1
  ��������ֵ�������û�ѡ��Ĵ��Ÿ�������*/
int Menu(void)
{
    int itemSelected,k;
    static int i = 1;
    printf("\nManagement for students' score V6.0\n");
    printf("1.Input record.\n");
    printf("2.Calculate total and average score of every course.\n");
    printf("3.Calculate total and average score of every student.\n");
    printf("4.Sort in descending order by score.\n");
    printf("5.Sort in ascending order by score.\n");
    printf("6.Sort in ascending order by number.\n");
    printf("7.Sort in dictionary order by name.\n");
    printf("8.Search by number.\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis.\n");
    printf("11.List record.\n");
    printf("12.Write to a file.\n");
    printf("13.Read from a file.\n");
    printf("14.Delete data\n");
    printf("15.Add data\n");
    printf("0.Exit!\n");
    if(i == 1)
    {
        do
        {
            fflush(stdin);
            printf("Please input 1 or 13 since this is your first choice:");
            k = scanf(" %d",&itemSelected);
        }while((itemSelected != 1 && itemSelected != 13)|| k != 1);
        i++;
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("Please input your choice:");
            k = scanf("%d",&itemSelected);
        }while(k != 1);
    }
    return itemSelected;
}

/*�����ӿڣ������ͷָ�롢�γ�����ѧ����n���γ���m
  �������ܣ�����ѧ���ĳɼ������֡�ѧ�š�����γ���
  ��������ֵ������ͷָ��*/
STU * ReadScore(STU *head,int n,int m,char coursename[][MAX_LEN],int maxscore[])
{
    STU *p = NULL,*pr = head;
    int i,j;
    printf("Please input %d courses' names and their total points:\n",m);
    for(j = 0;j < m;j++)
    {
        scanf("%s%*c%d",coursename[j],&maxscore[j]);
    }
    for(i = 0;i < n;i++)
    {
        p = (STU *) malloc(sizeof(STU));
        if(p == NULL)
        {
            printf("Arrow!No enough memory!");
            exit(0);
        }
        else
        {
            if(head == NULL)
            {
                head = p;
                pr = p;
                p -> next =  NULL;
            }
            else
            {
                pr->next = p;
                pr = p;
                p->next = NULL;
            }
        }
        printf("Input student%d's ID,name:",i+1);
        scanf("%ld%*c%s",&p->num,p->name);
        for(j = 0;j < m;j++)
        {
            do
            {
                printf("Input his/her score for %s",coursename[j]);
                scanf("%f",&p->score[j]);
            }while(p->score[j] < 0 || p->score[j] > maxscore[j]);
        }
        p->sum = 0;
        p->aver = 0;
    }
    return head;
}

/*�����ӿڣ�����ͷָ�롢ѧ�������γ������γ�����
  �������ܣ�ͳ�Ƹ��γ̵�ƽ���ֺ��ܷ�
  ��������ֵ����*/
void AverSumofEveryCourse(STU *head,int n,int m,char coursename[][MAX_LEN])
{
    STU *p = head;
    int j;
    float sum[m],aver[m];
    for(j = 0;j < m;j++)
    {
        sum[j] = 0;
        while(p != NULL)
        {
            sum[j] = sum[j] + p->score[j];
            p = p->next;
        }
        aver[j]  = sum[j] / n;
        if(p == NULL)
            p = head;
    }
    for(j = 0;j < m;j++)
    {
        printf("%s:sum = %.2f,aver = %.2f\n",coursename[j],sum[j],aver[j]);

    }
}

/*�����ӿڣ�����ͷָ�롢ѧ����n���γ���m
  �������ܣ�ͳ��ѧ����ƽ���ֺ��ܷ�
  ��������ֵ������ͷָ��*/
STU * AverSumofEveryStudent(STU *head,int n,int m)
{
    STU *p = head;
    int j;
    while(p!=NULL)
    {
        p->sum = 0;
        for(j = 0;j < m;j++)
        {
            p->sum = p->sum + p->score[j];
        }
        p->aver = p->sum / m;
        p=p->next;
    }
    p = head;
    while(p!=NULL)
    {
        printf("%ld\t%s\tsum=%.2f\taver=%.2f\t\n",p->num,p->name,p->sum,p->aver);
        p=p->next;
    }
    return head;
}

/*�����ӿڣ������ͷָ�롢ѧ������n���γ���m������ָ��compair
  �������ܣ�����compair��ָ��ʵ�������߽������У����ý�������
  ��������ֵ���������ͷָ��*/
STU * SortbyScore(STU *head,int n,int m,int (*compare)(float a,float b))
{
    STU *p = head,*pr = NULL;
    int j;
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾ�����û��ƽ���ֺ��ֵܷ����
    while(p != NULL)
    {
        pr = p->next;
        while(pr != NULL)
        {
            if((*compare)(p->sum,pr->sum))
            {
                SwapLong(&p->num,&pr->num);//����ѧ��
                SwapChar(p->name,pr->name);//��������
                for(j = 0;j < m;j++)
                {
                    SwapFloat(&p->score[j],&pr->score[j]);
                }//�����ɼ�
                SwapFloat(&p->sum,&pr->sum);//�����ܷ�
                SwapFloat(&p->aver,&pr->aver);//����ƽ����
            }
            pr = pr -> next;
        }
        p = p->next;
    }
    return head;
}

/*��Ϊ��������*/
int Ascending(float a,float b)
{
    return b < a;
}

/*��Ϊ��������*/
int Descending(float a,float b)
{
    return b > a;
}

/*�����ӿڣ�ָ��float�ͱ���������ָ��x��y
  �������ܣ�ͨ�������ý���������
  ��������ֵ����*/
void SwapFloat(float *x,float *y)
{
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*�����ӿڣ�ָ��long�ͱ���������ָ��x��y
  �������ܣ�ͨ�������ý���������
  ��������ֵ����*/
void SwapLong(long *x,long *y)
{
    long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*�����ӿڣ������洢���ַ������ַ�����
  �������ܣ�ͨ���ַ���������������������
  ��������ֵ����*/
void SwapChar(char x[],char y[])
{
    char temp[MAX_LEN];
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}

/*�����ӿڣ������ͷָ�룬ѧ������n���γ���m
  �������ܣ���ѧ����С��������(ѡ������)
  ��������ֵ�������ͷָ��*/
STU * AsSortbyNum(STU *head,int n,int m)
{
    STU *p = head,*pr = NULL,*pt = NULL;
    int j;
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾ�����û��ƽ���ֺ��ֵܷ����
    while(p != NULL)
    {
        pr = p->next;
        pt = p;
        while(pr != NULL)
        {
            if(pr->num < pt->num)
            {
                pt = pr;
            }
            pr = pr -> next;
        }
        if(pt != p)
        {
            SwapLong(&pt->num,&p->num);//����ѧ��
            SwapChar(pt->name,p->name);//��������
            for(j = 0;j < m;j++)
            {
                SwapFloat(&pt->score[j],&p->score[j]);
            }//�����ɼ�
            SwapFloat(&pt->sum,&p->sum);//�����ܷ�
            SwapFloat(&pt->aver,&p->aver);//����ƽ����
        }
        p = p->next;
    }
    return head;
}

/*�����ӿڣ�����ͷָ�롢ѧ���������γ���
  �������ܣ������ֵ����ѧ��������������
  ��������ֵ������ͷָ��*/
STU * SortbyName(STU *head,int n,int m)
{
    STU *p = head,*pr = NULL;
    int j;
    while(p != NULL)
    {
        pr = p->next;
        while(pr != NULL)
        {
            if((strcmp(p->name,pr->name) > 0))
               {
                   SwapLong(&p->num,&pr->num);
                   SwapChar(p->name,pr->name);
                   for(j = 0;j < m;j++)
                   {
                       SwapFloat(&p->score[j],&pr->score[j]);
                   }
                   SwapFloat(&p->sum,&pr->sum);
                   SwapFloat(&p->aver,&p->aver);
               }
               pr = pr -> next;
        }
        p = p -> next;
    }
    return head;
}

/*�����ӿڣ������ͷָ�룬�γ������γ�����
  �������ܣ�����ѧ�Ų��ң���������
  ��������ֵ����*/
void SearchbyNum(STU *head,int n,int m,char coursename[][MAX_LEN])
{
    long target;
    STU *p = head;
    int j;
    printf("Please input the number you want to search:");
    scanf("%ld",&target);
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾͲ���û��ƽ���ֺ��ֵܷ����
    while(p != NULL)
    {
        if(p->num == target)
        {
            printf("%ld\t%s\t",p->num,p->name);
            for(j = 0;j < m;j++)
            {
                printf("%s:%.2f\t",coursename[j],p->score[j]);
            }
            printf("Sum:%.2f\tAver:%.2f\n",p->sum,p->aver);
            return;
        }
        p = p->next;
    }
    printf("Sorry,%ld has not been found!\n",target);
}
/*�����ӿڣ������ͷָ�룬�γ���m���γ�����
  �������ܣ���ѧ�����������в���
  ��������ֵ����*/
void SearchbyName(STU *head,int n,int m,char coursename[][MAX_LEN])
{
    char target[MAX_LEN];
    STU *p = head;
    int j;
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾͲ���û��ƽ���ֺ��ֵܷ����
    printf("Input the name you want to search:\n");
    scanf("%s",target);
    while(p != NULL)
    {
        if((strcmp(p->name,target)) == 0)
        {
            printf("%ld\t%s\t",p->num,p->name);
            for(j = 0;j < m;j++)
            {
                printf("%s:%.2f\t",coursename[j],p->score[j]);
            }
            printf("Sum:%.2f\tAver:%.2f\n",p->sum,p->aver);
            return;
        }
        p = p->next;
    }
    printf("Sorry %s has not been found!",target);
}

/*�����ӿڣ�����ͷָ�롢ѧ���������γ������γ�����
  �������ܣ���ӡѧ����Ϣ
  ��������ֵ����*/
void PrintScore(STU *head,int n,int m,char coursename[][MAX_LEN])
{
    STU *p = head;
    int j;
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾʹ�ӡû��ƽ���ֺ��ֵܷ����
    while(p != NULL)
    {
        printf("%ld\t%s\t",p->num,p->name);
        for(j = 0;j < m;j++)
        {
            printf("%s:%.2f\t",coursename[j],p->score[j]);
        }
        printf("Sum:%.2f\tAver:%.2f\n",p->sum,p->aver);
        p = p -> next;
    }
}

/*�����ӿڣ������ͷָ�룬�γ���m���γ̵����ƣ����ſγ̵���߷�
  �������ܶ�ÿ�ſν��гɼ�����:ͳ�Ƴɼ����ֵܷ�0.6��0.7��0.8��0.9��1.0���������εĳɼ��ε������Լ���ֱ�
  ��������ֵ����*/
void StatisticAnalysis(STU *head,int n,int m,char coursename[][MAX_LEN],int max[])
{
    int i,j,t[6];
    STU *p = head;
    for(j = 0;j < m;j++)
    {
        memset(t,0,sizeof(t));
        while(p != NULL)
        {
            if(p->score[j] >= 0 && p->score[j] < max[j] * 0.6)
                t[0]++;
            else if(p->score[j] < max[j] * 0.7)
                t[1]++;
            else if(p->score[j] < max[j] * 0.8)
                t[2]++;
            else if(p->score[j] < max[j] * 0.9)
                t[3]++;
            else if(p->score[j] < max[j] * 1.0)
                t[4]++;
            else if(fabs(p->score[j] - max[j]) < 1e-7)//�����������ж��Ƿ����
                t[5]++;
            p = p->next;
        }
        printf("%s:\n",coursename[j]);
        for(i = 0;i < 6;i++)
        {
            if(i == 0)
                printf("<%.0f\t%d\t%.2f%%\n",(float)max[j] * 0.6,t[i],(float)t[i]/n*100);
            else if(i == 5)
                printf("%.0f\t%d\t%.2f%%\n",(float)max[j],t[i],(float)t[i]/n*100);
            else
                printf("%.0f--%.0f\t%d\t%.2f%%\n",(float)max[j] * (i + 5) * 0.1,(float)max[j] * (i + 6) * 0.1,t[i],(float)t[i]/n*100);
        }
        if(p == NULL)
            p = head;
    }
}

/*�����ӿڣ������ͷָ�룬ѧ����n���γ���m���γ̵�����
  �������ܣ���ѧ������Ϣд���ĵ�����
  ��������ֵ����*/
void WritetoFile(STU *head,int n,int m,char coursename[][MAX_LEN],int max[])
{
    FILE *fp;
    int j;
    STU *p = head;
    if(p->sum == 0)
        AverSumofEveryStudent2(head,n,m);//��ֹһ�������ݾ�д���ĵ�û��ƽ���ֺ��ֵܷ����
    if((fp = fopen("student.txt","w")) == NULL)
    {
        printf("Fail to open student.txt!\n");
        exit(0);
    }
    fprintf(fp,"StudentNumber: %d Coursenumber: %d\n",n,m);
    while(p != NULL)
    {
        fprintf(fp,"%10ld%10s",p->num,p->name);
        for(j = 0;j < m;j++)
        {
            fprintf(fp,"%10s : %.2f",coursename[j],p->score[j]);
        }
        fprintf(fp,"\tsum=%.2f\taver=%.2f\n",p->sum,p->aver);
        p = p->next;
    }
    for(j = 0;j < m;j++)
    {
        fprintf(fp,"max %s %d\n",coursename[j],max[j]);
    }
    fclose(fp);
    printf("Writing to a file has succeeded!\n");
}

/*�����ӿڣ�һ�������ͷָ�룬ָ��ѧ��������ָ�룬ָ��γ�����ָ�룬��ȡ�Ŀγ���
  �������ܣ���һ���ĵ��ж�������
  ��������ֵ�������ͷָ��*/
STU * ReadfromFlie(int *n,int *m,char coursename[][MAX_LEN],int max[])
{
    FILE *fp;
    STU *head = NULL;
    int j;
    STU *p = NULL;
    if((fp = fopen("student.txt","r")) == NULL)
    {
        printf("Fail to open student.txt!\n");
        exit(0);
    }
    fscanf(fp,"StudentNumber: %d Coursenumber: %d",n,m);//���ļ��ж���ѧ�������Ϳγ�����
    head = AppendEmptyNode(head,*n,*m);//����һ���������ǿյĵ�����ȴ�����������
    p = head;
    while(p != NULL)
    {
        fscanf(fp,"%10ld%10s",&p->num,p->name);
        for(j = 0;j < *m;j++)
        {
            fscanf(fp,"%10s : %f",coursename[j],&p->score[j]);
        }
        fscanf(fp,"\tsum=%f\taver=%f\n",&p->sum,&p->aver);
        p = p->next;
    }
    for(j = 0;j < *m;j++)
    {
        fscanf(fp,"max %*s%d\n",&max[j]);
    }
    printf("Reading from file has succeeded!\n");
    fclose(fp);
    return head;
}

/*�����ӿڣ�����ͷָ�롢ѧ����n���γ���m
  �������ܣ�ͳ��ѧ����ƽ���ֺ��ܷ�
  ��������ֵ����*/
void AverSumofEveryStudent2(STU *head,int n,int m)
{
    STU *p = head;
    int j;
    while(p!=NULL)
    {
        p->sum = 0;
        for(j = 0;j < m;j++)
        {
            p->sum = p->sum + p->score[j];
        }
        p->aver = p->sum / m;
        p=p->next;
    }
}

/*�����ӿڣ������ͷָ��
  �������ܣ�����ڴ�
  ��������ֵ����*/
int DeleteMemory(STU* head)
{
   STU *p = head,*pr = NULL;
   while(p != NULL)
   {
       pr = p;
       p = p->next;
       free(pr);
   }
   return 1;
}

/*�����ӿڣ������ͷָ�룬ѧ������
  �������ܣ�����һ���������ǿյĵ�����
  ��������ֵ�������ͷָ��*/
STU *AppendEmptyNode(STU *head,int n,int m)
{
    STU *p = NULL,*pr = head;
    int i,j;
    for(i = 0;i < n;i++)
    {
        p = (STU *)malloc(sizeof(STU));
        if(p == NULL)
        {
            printf("No enough memory!\n");
            exit(0);
        }
        if(head == NULL)
        {
            head = p;
            pr = p;
            pr->next = NULL;
        }
        else
        {
            pr->next = p;
            pr = p;
            p->next = NULL;
        }
        p->aver = 0;
        p->num = 0;
        for(j = 0;j < m;j++)
        {
            p->score[j]=0;
        }
        p->sum=0;
    }
    return head;
}

/*�����ӿڣ������ͷָ��,ָ��ѧ��������ָ��n
  �������ܣ�����ѧ��ɾ��һ��ͬѧ������
  ��������ֵ�������ͷָ��*/
STU *DeleteNode(STU *head,int *n)
{
    long num1,num2;
    STU *p = head,*pr = head;
    printf("Input the number you want to delete\n");
    scanf("%ld",&num1);
    printf("Please input again to make sure\n");
    scanf("%ld",&num2);
    if(num1 == num2)
    {
        while(p->next != NULL &&p ->num !=num1)/*δ�ҵ���δ����β*/
        {
            pr = p;/*��pr�б��浱ǰ�ڵ��ָ��*/
            p = p->next;/*pָ����һ���ڵ�*/
        }
        if(num1 == p->num)
        {
           if(p == head)    /*����ɾ������ͷ�ڵ�*/
           {
               head = p->next;/*��ͷָ��ָ���ɾ������һ���ڵ�*/
           }
           else /*����ɾ�ڵ㲻��ͷ�ڵ�*/
           {
               pr->next = p->next;/*��ǰһ�ڵ��ָ����ָ���ɾ�ڵ����һ�ڵ�*/
           }
           free(p);
           printf("%ld has been deleted!\n",num1);
           *n = *n - 1;//������һ
        }
        else
        {
            printf("%ld has not been found!",num1);
        }
    }
    return head;
}

/*�����ӿڣ������ͷָ��,�γ������γ����֣�ָ��������ָ��n
  �������ܣ�����һ��ѧ������Ϣ
  ��������ֵ�������ͷָ��*/
STU *Adddata(STU *head,int m,char coursename[][MAX_LEN],int *n)
{
    STU *pr = head,*p = head,*temp = NULL;
    int j;
    p = (STU *)malloc(sizeof(STU));
    if(p == NULL)
    {
        printf("No enough memory!\n");
        exit(0);
    }
    p->next = NULL;
    printf("Input the new student's ID and name:");
    scanf("%ld%*c%s",&p->num,p->name);
    for(j = 0;j < m;j++)
    {
        printf("Input the new student's score for %s",coursename[j]);
        scanf("%f",&p->score[j]);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->num < p->num && pr->next != NULL) //��δ�ҵ�������ڵ���λ��δ����β
        {
            temp = pr;
            pr = pr->next;
        }
        if(pr->num >= p->num)/*��������Ľڵ㲻�ڱ�β*/
        {
            if(pr == head)/*����ͷ�ڵ�ǰ�����½ڵ�*/
            {
                p->next = head;/*���½ڵ��ָ����ָ��ԭ�����ͷ�ڵ�*/
                head = p;/*headָ���µ�ͷ�ڵ�*/
            }
            else
            {
                pr = temp; /*��prָ���Ǹ��պñȴ�����ڵ�numС���Ǹ��ڵ�*/
                p->next = pr->next;/*���½ڵ��ָ����ָ����һ�ڵ�*/
                pr->next = p;/*��ǰһ�ڵ��ָ����ָ���½ڵ�*/
            }
        }
        else//��������Ľڵ��ڱ�β
        {
            pr->next = p;
        }
    }
    *n = *n + 1;//������һ
    return head;
}
