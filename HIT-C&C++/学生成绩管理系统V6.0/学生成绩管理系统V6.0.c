#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10		/*�ַ�����󳤶�*/
#define STU_NUM 30		/*���ѧ����*/
#define COURSE_NUM 6	/*����Ŀ��*/

typedef struct student
{
    long num;                /*ѧ��*/
    char name[MAX_LEN];      /*����*/
    float score[COURSE_NUM]; /*ÿ�ſγɼ�*/
    float sum;               /*ÿ��ѧ���ܳɼ�*/
    float aver;              /*ÿ��ѧ��ƽ���ɼ�*/
}STU;


int Init(STU stu[],int *n,int *m);
int Menu(void);
int Ascending(float a, float b);
int Descending(float a, float b);
void ReadScore(STU stu[],int n,int m);
void AverSumofEveryStudent(STU stu[],int n,int m);
void AverSumofEveryCourse(STU stu[],int n,int m);
void SortbyScore(STU stu[],int n,int m,int(*compare)(float a,float b));
void SwapFloat(float *x,float *y);
void SwapLong(long *x,long *y);
void SwapChar(char x[],char y[]);
void AsSortbyNum(STU stu[],int n,int m);
void SortbyName(STU stu[],int n,int m);
void SearchbyNum(STU stu[],int n,int m);
void SearchbyName(STU stu[],int n,int m);
void StatisticAnalysis(STU stu[],int n,int m);
void PrintScore(STU stu[],int n,int m);
void WriteToFile(STU stu[],int n,int m);
void ReadFromFile(STU stu[],int *n,int *m);

/*���ܣ������������û�������ø������ܺ���
  ��������
  ����ֵ��������������������0
*/
int main(void)
{
    char ch;
    char k;
    int n=0,m=0;       /*ѧ������Ϊn,�γ�����Ϊm */
    STU stu[STU_NUM];
    if(Init(stu, &n, &m)) ;
    else{
        printf("Input student number(n<=%d)",STU_NUM);
        scanf("%d",&n);
        printf("Input course number(m<=%d)",COURSE_NUM);
        scanf("%d",&m);
    }
    do
    {
        ch = Menu();    /*��ʾ�˵�������ȡ�û�����*/
        switch (ch)
        {
            case 1:ReadScore(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 2:AverSumofEveryCourse(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 3:AverSumofEveryStudent(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 4:SortbyScore(stu,n,m,Descending);
                   printf("\nSort in descending order by score:\n");
                   PrintScore(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 5:SortbyScore(stu,n,m,Ascending);
                   printf("\nSort in ascending order by score:\n");
                   PrintScore(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 6:AsSortbyNum(stu,n,m);
                   printf("\nSort in ascending order by number:\n");
                   PrintScore(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 7:SortbyName(stu,n,m);
                   printf("\nSort in ascending order by name:\n");
                   PrintScore(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 8:SearchbyNum(stu,n,m);
                   printf("\nPress Enter to continue...");
                   scanf("%c",&k);
                   break;
            case 9:SearchbyName(stu,n,m);
                   printf("\nPress Enter to continue...");
                   getchar();
                   getchar();
                   break;
            case 10:StatisticAnalysis(stu,n,m);
                    printf("\nPress Enter to continue...");
                    getchar();
                    getchar();
                    break;
            case 11:PrintScore(stu,n,m);
                    break;
            case 12:
                    WriteToFile(stu, n, m);
                    printf("\nPress Enter to continue...");
                    getchar();
                   getchar();
                    break;
            case 13:
                    ReadFromFile(stu,&n,&m);
                    printf("\nPress Enter to continue...");
                    getchar();
                   getchar();
                    break;
            case 0:printf("End of program!");
                   exit(0);
            default:printf("Input error!");
        }
    }while(1);
    return 0;
}

/*���ܣ���ʾ�˵�������û����������ѡ��
��������
����ֵ���û��ļ���ֵ
*/
int Menu(void)
{
    int itemSelected;
    printf("Management For Students' Score\n");
    printf("(YOU MUST CHOOSE 1 AND 3!!!)\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of every course\n");
    printf("3.Caculate total and average score of every student\n");
    printf("4.Sort in descending order by score\n");
    printf("5.Sort in ascending order by score\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis\n");
    printf("11.List record\n");
    printf("12.Write to a file\n");
    printf("13.Read from a file\n");
    printf("0.Exit\n");
    printf("Please Input your choice:\n");
    scanf("%d",&itemSelected);       /*�����û�����*/
    return itemSelected;
}


/*���ܣ�����n��ѧ����m�ſγ̳ɼ�
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void ReadScore(STU stu[],int n,int m)
{
    int i,j;
    printf("Input student's ID,name and score:\n");
    for(i=0;i<n;i++)
    {
        scanf("%ld%s",&stu[i].num,stu[i].name);
        for(j=0;j<m;j++)
        {
            scanf("%f",&stu[i].score[j]);
        }
    }
}

/*���ܣ�����ÿ��ѧ�����ųɼ����ֺܷ�ƽ����
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void AverSumofEveryStudent(STU stu[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        stu[i].sum=0;
        for(j=0;j<m;j++)
        {
            stu[i].sum=stu[i].sum+stu[i].score[j];
        }
        stu[i].aver=m>0?stu[i].sum/m:-1;
        printf("student %d:sum = %.0f,aver = %.0f\n",i+1,stu[i].sum,stu[i].aver);
    }
}

/*���ܣ�����ÿ�ſγ̵��ֺܷ�ƽ����
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ��
*/
void AverSumofEveryCourse(STU stu[],int n,int m)
{
    int i,j;
    float sum[COURSE_NUM],aver[COURSE_NUM];
    for(j=0;j<m;j++)
    {
        sum[j]=0;
        for(i=0;i<n;i++)
        {
            sum[j]+=stu[i].score[j];
        }
        aver[j]=n>0?sum[j]/n:-1;
        printf("course %d:sum = %.0f,aver = %.0f\n",j+1,sum[j],aver[j]);
    }
}

/*���ܣ���ѡ�񷨽�����sum��Ԫ��ֵ����
������ѧ����Ϣ�ṹ������stu������n���γ���m���ȽϷ�������ָ��
����ֵ����
*/
void SortbyScore(STU stu[],int n,int m,int(*compare)(float a,float b))
{
    int i,j,k,t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].sum,stu[k].sum)) k=j;
        }
        if(k!=i)
        {
            for(t=0;t<m;t++)    /*����m�ſγ̳ɼ�*/
            {
                SwapFloat(&stu[k].score[t],&stu[i].score[t]);
            }
            SwapFloat(&stu[k].sum,&stu[i].sum);   /*�����ܷ�*/
            SwapFloat(&stu[k].aver,&stu[i].aver); /*����ƽ����*/
            SwapLong(&stu[k].num,&stu[i].num);    /*����ѧ��*/
            SwapChar(stu[k].name,stu[i].name);    /*��������*/
        }
    }
}

/*���ܣ�ʹ���ݰ���������
���������Ƚϵĸ�����a��b
����ֵ���ȽϽ���Ĳ���ֵ
*/
int Ascending(float a,float b)
{
    return a<b;
}

/*���ܣ�ʹ���ݰ���������
���������Ƚϵĸ�����a��b
����ֵ���ȽϽ���Ĳ���ֵ
*/
int Descending(float a,float b)
{
    return a>b;
}


/*���ܣ��������������ȸ���������
�������������ĸ�����x��y
����ֵ����
*/
void SwapFloat(float *x,float *y)
{
    float t;
    t=*x;
    *x=*y;
    *y=t;
}


/*���ܣ�������������������
�������������ĳ�������x��y
����ֵ����
*/
void SwapLong(long *x,long *y)
{
    long t;
    t=*x;
    *x=*y;
    *y=t;
}

/*���ܣ����������ַ���
���������������ַ���x��y
����ֵ����
*/
void SwapChar(char x[],char y[])
{
    char t[MAX_LEN];
    strcpy(t,x);
    strcpy(x,y);
    strcpy(y,t);
}

/*���ܣ���ѡ�񷨽�����num��Ԫ��ֵ���ӵ͵�������
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void AsSortbyNum(STU stu[],int n,int m)
{
    int i,j,k,t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(stu[j].num<stu[k].num) k=j;
        }
        if(k!=i)
        {
            for(t=0;t<m;t++)    /*����m�ſγ̳ɼ�*/
            {
                SwapFloat(&stu[k].score[t],&stu[i].score[t]);
            }
            SwapFloat(&stu[k].sum,&stu[i].sum);   /*�����ܷ�*/
            SwapFloat(&stu[k].aver,&stu[i].aver); /*����ƽ����*/
            SwapLong(&stu[k].num,&stu[i].num);    /*����ѧ��*/
            SwapChar(stu[k].name,stu[i].name);    /*��������*/
        }
    }
}


/*���ܣ�������ʵ���ַ������ֵ�˳������
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void SortbyName(STU stu[],int n,int m)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        t=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[j].name,stu[i].name)<0)
            {
                for(t=0;t<m;t++)    /*����m�ſγ̳ɼ�*/
                {
                    SwapFloat(&stu[i].score[t],&stu[j].score[t]);
                }
                SwapFloat(&stu[i].sum,&stu[j].sum);   /*�����ܷ�*/
                SwapFloat(&stu[i].aver,&stu[j].aver); /*����ƽ����*/
                SwapLong(&stu[i].num,&stu[j].num);    /*����ѧ��*/
                SwapChar(stu[i].name,stu[j].name);    /*��������*/
            }
        }
    }
}


/*���ܣ���ѧ�Ų���ѧ���ɼ�����ʾ���ҽ��
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void SearchbyNum(STU stu[],int n,int m)
{
    long number;
    int i,j;
    printf("Input the number you want to search:");
    scanf("%ld",&number);
    for(i=0;i<n;i++)
    {
        if(stu[i].num==number)
        {
            printf("%ld\t%s\t",stu[i].num,stu[i].name);
            for(j=0;j<m;j++)
            {
                printf("%.0f\t",stu[i].score[j]);
            }
            printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
            return;
        }
    }
    printf("\nNot found! \n");
}


/*���ܣ�����������ѧ���ɼ�����ʾ���ҽ��
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void SearchbyName(STU stu[],int n,int m)
{
    char x[MAX_LEN];
    int i,j;
    printf("Input the name you want to search:");
    scanf("%s",x);
    for(i=0;i<n;i++)
    {
        if(strcmp(stu[i].name,x)==0)
        {
            printf("%ld\t%s\t",stu[i].num,stu[i].name);
            for(j=0;j<m;j++)
            {
                printf("%.0f\t",stu[i].score[j]);
            }
            printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
            return;
        }
    }
    printf("\nNot found! \n");
}


/*���ܣ�ͳ�Ƹ������ε�ѧ����������ռ�İٷֱ�
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void StatisticAnalysis(STU stu[],int n,int m)
{
    int i,j,total,t[6],g;
    for(j=0;j<m;j++)
    {
        printf("For course %d:\n",j+1);
        for(g=0;g<6;g++)    /*������t��Ԫ�س�ʼ��Ϊ0*/
        {
            t[g]=0;
        }
        for(i=0;i<n;i++)
        {
            if(stu[i].score[j]>=0&&stu[i].score[j]<60) t[0]++;
            else if(stu[i].score[j]<70) t[1]++;
            else if(stu[i].score[j]<80) t[2]++;
            else if(stu[i].score[j]<90) t[3]++;
            else if(stu[i].score[j]<100) t[4]++;
            else if(stu[i].score[j]==100) t[5]++;
        }
        for(total=0,i=0;i<=5;i++)
        {
            total=total+t[i];
        }
        for(i=0;i<=5;i++)
        {
            if(i==0) printf("<60\t%d\t%.2f%%\n",t[i],(float)t[i]/n*100);
            else if(i==5) printf("%d\t%d\t%.2f\t%%\n",(i+5)*10,t[i],(float)t[i]/n*100);
            else printf("%d-%d\t%d\t%.2f%%\n",(i+5)*10,(i+5)*10+9,t[i],(float)t[i]/n*100);
        }
    }
}


/*���ܣ���ӡѧ���ɼ�
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void PrintScore(STU stu[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++)
        {
            printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
    }
}

/*���ܣ�����ѧ����Ϣ���ļ���
������ѧ����Ϣ�ṹ������stu������n���γ���m
����ֵ����
*/
void WriteToFile(STU stu[],int n,int m)
{
    FILE *ClassInfo;
    if( ( ClassInfo = fopen("grade.date","wt+") ) == NULL ) printf("Can not open the file!\n");
    fprintf(ClassInfo,"%d %d\n",n,m);
    fwrite(stu,sizeof(STU),n,ClassInfo);
    fclose(ClassInfo);
    printf("\nWrite successfully!");
    return ;
}

/*���ܣ���ȡ����ѧ����Ϣ���ļ�
������ѧ����Ϣ�ṹ������stu������nָ�룬�γ���mָ��
����ֵ����
*/
void ReadFromFile(STU stu[],int *n,int *m)
{
    FILE *ClassInfo;
    if( ( ClassInfo = fopen("grade.date","rt") ) == NULL ) printf("Can not open the file!\n");
    fscanf(ClassInfo,"%d %d",n,m);
    fgetc(ClassInfo);
    fread(stu,sizeof(STU),*n,ClassInfo);
    fclose(ClassInfo);
    printf("\nRead successfully. The student number is %d,and the course number is %d.\n",*n,*m);
    return ;
}

/*���ܣ���ȡ�ļ��ӵĿγ���Ϣ�������û�����
������ѧ����Ϣ�ṹ������stu������n��ָ�룬�γ���mָ��
����ֵ���û�ѡ��������ֵ
*/
int Init(STU stu[],int *n,int *m)
{
    FILE *ClassInfo;
    char c;
    if( ( ClassInfo = fopen("grade.date","rt") ) != NULL ) printf("Some grade data has been found,do you want to load?(Y/N):");
    else return 0;
    scanf("%c",&c);
    if(c=='n'||c=='N') return 0;
    fscanf(ClassInfo,"%d %d",n,m);
    fgetc(ClassInfo);
    fread(stu,sizeof(STU),*n,ClassInfo);
    fclose(ClassInfo);
    printf("The student number is %d,and the course number is %d.\n",*n,*m);
    return 1;
}
