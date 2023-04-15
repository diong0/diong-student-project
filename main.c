#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#define STU_NUM 50
#define COURSE_NUM 10
#define NAME_LEN 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50

#define POS_X4 65
#define POS_Y 3

typedef struct student
{
    long num;
    char name[NAME_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
    struct student *next;
}STU;

//�Զ��庯������
int Menu(void);//�����˵�
void SetPosition(int x,int y);//������������ڿ���̨�����е���ʼλ��
void InputRecord(STU stu[],int *n,int *m);//����ѧ����Ϣ
void AppendRecord(STU stu[],int *n, int m);//����ѧ����Ϣ
void DeleteRecord(STU stu[],int *n,int m);//ɾ��ѧ����Ϣ(ָɾ��������¼)
void SearchByNumber(STU stu[],int n,int m);//��ѧ�Ų�ѯѧ����Ϣ
void SearchByName(STU stu[],int n,int m);//��������ѯѧ����Ϣ
void ModifyRecord(STU stu[],int n,int m);//�޸�ѧ����Ϣ
void CalculateScoreOfStudent(STU stu[],int n,int m);//����ѧ�����ֺܷ�ƽ����
void CalculateScoreOfCourse(STU stu[],int n,int m);//����ĳ�ſγ̵��ֺܷ�ƽ����
void SortByNum(STU stu[],int n,int m);//��ѧ������
void SortByName(STU stu[],int n,int m);//����������
void SortByScore(STU stu[],int n,int m,int (*compare)(float a,float b));//��ÿ��ѧ��ƽ���ֽ�������
int Ascending(float a,float b);//��������
int Descending(float a,float b);//��������
void StatisticAnalysis(STU stu[],int n,int m);//ͳ�Ʋ��������������ѧ��������ռ��
void PrintRecord(STU stu[],int n,int m);//��ӡѧ���ɼ�
void WriteToFile(STU stu[],int n,int m);//��ѧ����Ϣ�������ļ���
int ReadFromFile(STU stu[],int *n,int *m,int *first);//��ѧ����Ϣ���ļ��ж����������ڴ棬�����ѧ����Ϣ���д���

int main()
{
    int n=0;
    int m=0;
    int i,j;
    char ch;
    int first=1;
    STU stu[STU_NUM];

    system("mode con cols=130 lines=60");
    system("color 0E");
    while(1)
    {
        system("cls");
        ch = Menu();
        switch(ch)
        {
            case 1 :
                system("cls");
                InputRecord(stu,&n,&m);
                for(i=0;i<n;i++)
                {
                    printf("\n��%d��ѧ����ϢΪ��",i+1);
                    printf("%ld %s ",stu[i].num,stu[i].name);
                    for(j=0;j<m;j++)
                    {
                        printf("%f ",stu[i].score[j]);
                    }
                }
                system("pause");
                first=0;
                break;
            case 2:
                system("cls");
                if(first)
                {
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    system("pause");
                    break;
                }
                AppendRecord(stu,&n,m);
                system("pause");
                break;
            case 3:
                system("cls");
                if(first) {
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    system("pause");
                    break;
                }
                 DeleteRecord(stu,&n,m);
                 system("pause");
                 break;
            case 4:
                system( "cls");
                if(first)
                {
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    system("pause");
                    break;
                }
                SearchByNumber(stu,n,m);
                system("pause");
                break;
            case 5:
                system("cls");
                if(first)
                {
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    system("pause");
                    break;
                }
                SearchByName(stu,n,m);
                system("pause");
                break;
            case 6:
                system("cls");
                if(first)
                {
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    system("pause");
                    break;
                }
                ModifyRecord(stu,n,m);
                system("pause");
                break;
            case 7:
                system("cls");
                if(first)
                {
                    printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
                    system("pause");
                    break;
                }
                CalculateScoreOfStudent(stu,n,m);
                system("pause");
                break;
            case 8:
                system("cls");
                if(first)
                {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
                    getch();
                    break;
                }
                CalculateScoreOfCourse(stu,n,m);
                getch();
                break;
            case 9:
                system("cls");
                if(first) {
                    SetPosition(POS_X3, POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    getch();
                    break;
                }
                SortByNum(stu,n,m);
                getch();
                break;
            case 10:
                system("cls");
                if(first) {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    getch();
                    break;
                }
                SortByName(stu,n,m);
                getch();
                break;
            case 11:
                 system("cls");
                 if(first) {
                     SetPosition(POS_X3,POS_Y);
                     printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                     getch();
                     break;
                 }
                 SortByScore(stu,n,m, Descending);
                 getch( );
                 break;
            case 12:
                system("cls");
                if(first) {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    getch();
                    break;
                }
                SortByScore(stu,n,m, Ascending);
                getch( );
                break;
            case 13:
                system("cls");
                if(first)
                {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
                    getch();
                    break;
                }
                StatisticAnalysis(stu,n,m);
                getch();
                break;
            case 14:
                system("cls");
                if(first) {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    getch();
                    break;
                }
                PrintRecord(stu,n,m);
                getch();
                break;
            case 15:
                system( "cls") ;
                if(first)
                {
                    SetPosition(POS_X3,POS_Y);
                    printf("ϵͳ������ѧ���ɼ���Ϣ,��������!\n");
                    getch();
                    break;
                }
                WriteToFile(stu,n,m);
                getch();
                break;
            case 16:
                system("cls");
                if(ReadFromFile(stu,&n,&m,&first)||first)
                {
                    SetPosition(POS_X1,10);
                    printf("��δ����ѧ����Ϣ���ļ���ʧ�ܣ����ȼ�飡\n");
                    getch( );
                    break;
                }
                getch( );
                break;
            case 0:
                system("cls");
                printf("�˳�ϵͳ��\n");
                exit(0);
            default:
                system("cls");
                printf("�������������ѡ�������\n");
                break;
        }
    }
}
int Menu(void)
{
    int posy=5;
    int option;                     //�����û�����Ĳ������ŵı���
    int i,j;
    SetPosition(POS_X3,posy);
    printf("ѧ���ɼ�����ϵͳ\n");//���ϵͳ����
    //���ϵͳ���ֺ͹���˵��֮������ж̺���
    for(i=0;i<2;i++)
    {
        SetPosition(POS_X1,++ posy);
        for(j=0;j<55;j++)
        {
            printf( "-") ;
        }
    }
//���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
    SetPosition(POS_X1,++posy);
    printf("1.����ѧ����Ϣ");
    SetPosition(POS_X4,posy);
    printf("2.����ѧ���ɼ�");
    SetPosition(POS_X1, posy+=2);
    printf("3.ɾ��ѧ����Ϣ");
    SetPosition(POS_X4, posy);
    printf("4.��ѧ�Ų��Ҽ�¼");
    SetPosition(POS_X1, posy+=2);
    printf("5.���������Ҽ�¼");
    SetPosition(POS_X4, posy);
    printf("6.�޸�ѧ����Ϣ");
    SetPosition(POS_X1, posy+=2);
    printf("7.����ѧ���ɼ�");
    SetPosition(POS_X4, posy);
    printf("8.����γ̳ɼ�");
    SetPosition(POS_X1, posy+=2);
    printf("9.��ѧ������");
    SetPosition(POS_X4, posy);
    printf("10.����������");
    SetPosition(POS_X1, posy+=2);
    printf("11.���ܳɼ���������");
    SetPosition(POS_X4, posy);
    printf("12.���ܳɼ���������");
    SetPosition(POS_X1, posy+=2);
    printf("13.ѧ���ɼ�ͳ��");
    SetPosition(POS_X4, posy);
    printf("14.��ӡѧ����¼");
    SetPosition(POS_X1, posy+=2);
    printf("15.ѧ����¼����");
    SetPosition(POS_X4, posy);
    printf("16.�Ӵ��̶�ȡѧ����¼");
    SetPosition(POS_X1, posy+=2);
    printf("0.�˳�");
//���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
    for(i=0;i<2;i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0;j<55;j++)
        {
            printf( "-" ) ;
        }
    }
//��ʾ�û�������Ҫִ�еĹ��ܴ���
    SetPosition(POS_X1,++posy);
    printf("��ѡ������Ҫ���еĲ���[0~16]:[  ]\b\b\b");
    scanf_s("%d",&option);
    return option;
}
/*
�������ܣ����������������ʼλ��
��ʽ���������������ʼλ�õ�����x��y��int����
��������ֵ:void
*/
void SetPosition(int x,int y)
{
    HANDLE hOut;
    COORD pos;

    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut,pos);
}
/*
�������ܣ�����ѧ����Ϣ
��ʽ����: n,m:int*,stu:STU*
��������ֵ:void
*/
void InputRecord(STU *stu,int *n,int *m)
{
    int i, j;
    int posy = 6;
    SetPosition(POS_X2, posy);//���ù��λ�ã�����Ҫ��ʾ��λ��
    printf("����ѧ������(n<%d):", STU_NUM);
    scanf_s("%d", n);
    SetPosition(POS_X2, posy += 2);//���ù��λ�ã�����Ҫ��ʾ��λ��
    printf("����γ�����(m<%d):", COURSE_NUM);
    scanf_s("%d", m);
    for (i=0;i<2;i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    SetPosition(POS_X2, ++posy);
    printf("����ѧ����ѧ�š������͸��ſγ̳ɼ���");
    for (i = 0; i < *n; i++) {
        SetPosition(POS_X2, ++posy);
        printf("�����%d��ѧ����Ϣ:\t", i + 1);
        scanf_s("%ld%s", &stu[i].num, &stu[i].name);
        for (j = 0; j < *m; j++) {
            scanf_s("%f", &stu[i].score[j]);
        }
    }
}
/*
�������ܣ�����ѧ����¼һ��������ѧ����¼
��ʽ����:n:int*,m;int,stu:STU*
��������ֵ:void
*/
void AppendRecord(STU stu[],int*n,int m)
{
    int i,j;
    int num_record;
    printf("��������Ҫ���ӵ�ѧ����¼������");
    scanf_s("%d",& num_record);
    while(*n+num_record>STU_NUM)//�ж�������¼��ԭ�м�¼֮���Ƿ�С���趨����
    {
        printf("Ҫ���ӵļ�¼����̫�࣬���������룺");
        scanf_s("%d",&num_record);
    }
    for(i=*n;i<*n+num_record;i++)
    {
        printf("�����%d��ѧ����Ϣ:\t",i+1);
        scanf_s("%ld%s",&stu[i]. num,stu[i]. name);
        for(j=0;j<m;j++)
        {
            scanf_s("%f",&stu[i]. score[j]);
        }
    }
    *n=*n+num_record;
    printf("������!\n");
}
/*
2 �������ܣ������еĴ����ļ�student. txt�У�����ѧ���������γ������Լ�ÿ��ѧ������Ϣ�����洢���ڴ��ж�Ӧ�����ͱ���n��m�ͽṹ������stu�У�������־����first��ֵ����
3 ��ʽ����:n,m,first:int*,stu:STU*
4 ��������ֵ��int(����1���������ļ�ʧ�ܣ�����0�������ɹ��Ӵ��̶�������)
*/
int ReadFromFile(STU stu[],int *n,int *m,int *first)
{
    //�����ļ�ָ��
    FILE*fp;
    int i,j;
    int posy=8;
    SetPosition(POS_X1, posy);
    //���ļ���ָ�����ļ��Ĵ���ʽΪд�룬����ָ��ָ���ļ�
    if((fp=fopen("\\student.txt","r"))==NULL)
    {
        printf("�����ļ�student. txt�޷���");
        return 1;
    }//�����ݰ�ָ����ʽ�Ӵ����ļ�����������ѧ������n���γ�����m�Լ�ÿλѧ������Ϣ
    fscanf_s(fp,"%10d%10d",n,m);
    for( i=0;i<*n;i++ ) {
        fscanf_s(fp, "%10ld", &stu[i].num);
        fscanf_s(fp, "%10s", stu[i].name);
        for (j = 0; j < *m; j++ ) {
            fscanf_s(fp, "%10f", &stu[i].score[j]);
        }
        fscanf_s(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
    }
    *first=0;//�޸ı�־����
    //�ر��ļ�
    fclose(fp);
    printf("���ݴӴ��̶�ȡ���!");
    return 0;
}
/*
�������ܣ�����ѧ���ɼ�
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void CalculateScoreOfStudent(STU stu[],int n,int m)
{
    int i, j;
    printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
    for (i = 0; i < n; i++) {
        stu[i].sum = 0;
        for (j = 0; j < m; j++) {
            stu[i].sum += stu[i].score[j];
        }
        stu[i].aver = stu[i].sum/(float)m;
        printf("��%d��ѧ��:�ܷ�=%.2f,ƽ����=%.2f\n", i + 1, stu[i].sum, stu[i].aver);
    }
}
/*
�������ܣ�����γ̳ɼ�
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void CalculateScoreOfCourse(STU stu[],int n,int m)
{
    int i, j;
    float sum[COURSE_NUM],aver[COURSE_NUM];
    int posy=7;
    SetPosition(POS_X1,posy);
    printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
    for (j= 0; j<m; j++) {
        sum[j]=0;
        for (i= 0; i < n; i++)
            sum[j] += stu[i].score[j];
        aver[j]=sum[j]/(float)n;
        printf("��%d�ſγ�:�ܷ�=%.2f,ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
    }
}
/*
�������ܣ����ѧ������n���γ�����m�Լ�ÿ��ѧ������Ϣ��student. txt��
��ʽ����:n. m:int,stu:STU��
��������ֵ:void
*/
void WriteToFile(STU stu[],int n,int m)
{
    int i,j;//�����ļ�ָ��
    FILE *fp;//���ļ���ָ�����ļ��Ĵ���ʽΪд�ˣ�����ָ��ָ���ļ�
    if((fp=fopen("\\student.txt","w"))==NULL)
    {
        printf("�ļ�student.txt�޷�������!");
        exit(0) ;
    }
    //�����ݰ�ָ����ʽд���ļ�������ѧ������n���γ�����m�Լ�ÿ��ѧ������Ϣ
    fprintf(fp,"%10d%10d\n",n,m);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%10ld%10s\n",stu[i]. num,stu[i]. name);
        for(j=0;j<m;j++)
        {
            fprintf(fp,"%10.lf",stu[i]. score[j]);
        }
        fprintf(fp,"%10.lf%10.lf\n",stu[i].sum,stu[i].aver);
    }//�ر��ļ�
    fclose(fp);//��ʾ�û����̲������
    printf("�������!\n");
}


/*
�������ܣ���ѧ�Ų���ѧ����¼
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void SearchByNumber(STU *stu,int n,int m)
{
    long id;
    int i, j;
    printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
    scanf_s("%ld", &id);
    for (i = 0; i < n; i++)
    {
        if (stu[i].num == id) {
            printf("�ҵ���,��ѧ�Ŷ�Ӧ��ѧ����ϢΪ:\n");
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f", stu[i].sum, stu[i].aver);
            return;
        }
    }
    printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
}
 /*
�������ܣ�����������ѧ����¼
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void SearchByName(STU*stu,int n,int m)
{
     int flag = 1;
     int i, j;
     int k = 0;
     char name[NAME_LEN];
     printf("��������Ҫ���ҵ�ѧ����������");
     scanf("%s", name);
     for (i = 0; i < n; i++)
     {
         if (strcmp(stu[i].name, name) == 0) {
             printf("�ҵ���,��%dѧ����ϢΪ:\n", ++k);
             printf("%10ld%15s", stu[i].num, stu[i].name);
             for (j = 0; j < m; j++) {
                 printf("%10.2f", stu[i].score[j]);
             }
             printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
             flag = 0;
         }
     }
     if (flag)
     {
         printf("δ�ҵ����������Ӧ��ѧ����¼\n");
     }
 }
 /*
�������ܣ�ɾ��ָ��ѧ�ŵ�ѧ����¼
��ʽ����:n:int*,m:int,stu:STU*
��������ֵ:void
*/
void DeleteRecord(STU stu[],int *n,int m)
{
    int i,j;
    long id;
    char ch;
    printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
    scanf_s("%ld",&id);
    for(i=0;i<*n;i++) {
        if (stu[i].num == id) {
            printf("�ҵ��˸�����¼,��ϢΪ:\n");
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
            printf("��ȷ���Ƿ���Ҫɾ��������¼?(Y/y��N/n):");
            getchar();
            scanf("%c", &ch);
            if (ch == 'Y' || ch == 'y') {
                for (j = i; j < *n - 1; j++) {
                    stu[j] = stu[j + 1];
                }
                (*n)--;
                printf("ɾ�����\n");
                return;
            } else if (ch == 'N' || ch == 'n') {
                printf("�ҵ��˸�ѧ����¼,����ɾ��\n");
                return;
            } else {
                printf("�������!\n");
                return;
            }
        }
    }
    printf("δ�ҵ�������¼!\n");
 }
 /*
�������ܣ��޸�ָ��ѧ�ŵ�ѧ����¼
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void ModifyRecord(STU stu[],int n,int m) {
     int i, j;
     long id;
     char ch;

     printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ�ţ�");

     scanf_s("%ld", &id);
     for (i = 0; i < n; i++) {
         if (stu[i].num == id) {
             printf("�ҵ��˸�����¼,��ϢΪ:\n");
             printf("%10ld%15s", stu[i].num, stu[i].name);
             for (j = 0; j < m; j++) {
                 printf("%10.2f", stu[i].score[j]);
             }
             printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);

             printf("��ȷ���Ƿ���Ҫ�޸�?(Y/N��y/n):-");
             getchar();
             scanf("%c", &ch);

             if (ch == 'Y' || ch == 'y') {
                 printf("������Ҫ�޸ĵ�ѧ����Ϣ:");
                 scanf_s("%ld%s", &stu[i].num, stu[i].name);
                 stu[i].sum = 0;
                 for (j = 0; j < m; j++) {
                     scanf_s("%f", &stu[i].score[j]);
                     stu[i].sum += stu[i].score[j];
                 }
                 stu[i].aver = stu[i].sum / (float) m;
                 printf("�޸����\n");
                 return;
             }
             else if (ch == 'N' || ch == 'n') {
                 printf("�ҵ��˸�����¼,�����޸�\n");
                 return;
             }
             else {
                 printf("�������!\n");
                 return;
             }
         }
     }
     printf("δ�ҵ�������¼!\n");
 }
 /*
�������ܣ��������ѧ����¼
��ʽ����:n. m:int,stu:STU*
��������ֵ:void
*/
void PrintRecord(STU stu[],int n,int m)
{
    int i ,j;
    printf("ѧ��\t\t����\t\t");
    for(j=0;j<m;j++) {
     printf("�γ�%d\t\t",j+1);
    }
    printf("�ܷ�\t\tƽ����\n");
    for(i=0;i<n;i++)
    {
        printf("%-16ld%-16s",stu[i].num,stu[i].name);
        for(j=0;j<m;j++) {
            printf("%-16.1lf", stu[i].score[j]);
        }
        printf("%-16.1lf%-16.1lf\n",stu[i].sum,stu[i].aver);
    }
}
/*
�������ܣ�����ѧ�������ֵ�˳�������ѧ����¼��С��������
��ʽ����:n. m:int. stu:STU*
��������ֵ:void
*/
void SortByName(STU stu[],int n,int m) {
    int i, j;
    STU temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(stu[j].name, stu[j + 1].name) > 0) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("�������ֵ��ѧ����¼�������");
}
/*
�������ܣ�����ѧ�Ŷ�����ѧ����¼��С��������
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void SortByNum(STU*stu,int n,int m) {
    int i, j;
    int k;
    STU temp;
    for (i = 0; i < n; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (stu[j].num < stu[k].num)
                k = j;
        }
        if (k != i) {
            temp = stu[k];
            stu[k] = stu[i];
            stu[i] = temp;
        }
    }
    printf("��ѧ�Ŵ�С�����ѧ����¼�������");
}
/*
�������ܣ�����ѧ���ɼ��ֶܷ�����ѧ����¼���������������
��ʽ����:n,m;int,stu:STU*
��������ֵ:void
*/
void SortByScore(STU*stu,int n,int m,int(*compare)(float a,float b)) {
    {
        int i, j;
        int k;
        STU temp;
        for (i = 0; i < n; i++) {
            k = i;
            for (j = i + 1; j < n; j++) {
                if ((*compare)(stu[j].sum, stu[k].sum))
                    k = j;
            }
            if (k != i) {
                temp = stu[k];
                stu[k] = stu[i];
                stu[i] = temp;
            }
        }
        printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������");
    }
}
/*
�������ܣ��涨�����������
��ʽ����:a,b:float
��������ֵ:int
 */
int Descending(float a,float b) {
    return a > b;
}
    /*
�������ܣ��涨�����������
��ʽ����:a,b:float
��������ֵ:int
*/
int Ascending(float a,float b) {
    return a < b;
}
/*
�������ܣ�ͳ�Ʋ��������������ѧ��������ռ��
��ʽ����:n,m:int,stu:STU*
��������ֵ:void
*/
void StatisticAnalysis(STU stu[],int n,int m) {
    int i, j, t[6];
    for (j = 0; j < m; j++) {
        printf("\n�γ�%d�ɼ�ͳ�ƽ��Ϊ:\n", j + 1);
        printf("������\t����\tռ��\n");

        memset(t, 0, sizeof(t));
        for (i = 0; i < n; i++) {
            if (stu[i].score[j] >= 0 && stu[i].score[j] < 60)
                t[0]++;
            else if (stu[i].score[j] < 70)
                t[1]++;
            else if (stu[i].score[j] < 80)
                t[2]++;
            else if (stu[i].score[j] < 90)
                t[3]++;
            else if (stu[i].score[j] < 100)
                t[4]++;
            else if (stu[i].score[j] == 100)
                t[5]++;
        }
        for (i = 0; i < 6; i++) {
            if (i == 0)
                printf("<60\t%d\t%.2f%%%\n", t[i], (float) t[i] / (float) n * 100);
            else if (i == 5)
                printf("100\t%d\t%.2f%%\n", t[i], (float) t[i] / (float) n * 100);
            else
                printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float) t[i] / (float) n * 100);
        }
    }

    printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
    printf("������\t����\tռ��\n");
    memset(t, 0, sizeof(t));
    for (i = 0; i < n; i++) {
        if (stu[i].aver >= 0 && stu[i].aver < 60)
            t[0]++;
        else if (stu[i].aver < 70)
            t[1]++;
        else if (stu[i].aver < 80)
            t[2]++;
        else if (stu[i].aver < 90)
            t[3]++;
        else if (stu[i].aver < 100)
            t[4]++;
        else if (stu[i].aver == 100)
            t[5]++;
    }
    for (i = 0; i < 6; i++) {
        if (i == 0)
            printf("<60\t%d\t%.2f%%\n", t[i], (float) t[i] / (float) n * 100);
        else if (i == 5)
            printf("100\t%d\t%.2f%%\n", t[i], (float) t[i] / (float) n * 100);
        else
            printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float) t[i] / (float) n * 100);

    }
}