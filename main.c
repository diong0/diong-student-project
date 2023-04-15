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

//自定义函数声明
int Menu(void);//操作菜单
void SetPosition(int x,int y);//设置输出内容在控制台窗口中的起始位置
void InputRecord(STU stu[],int *n,int *m);//输入学生信息
void AppendRecord(STU stu[],int *n, int m);//增加学生信息
void DeleteRecord(STU stu[],int *n,int m);//删除学生信息(指删除整条记录)
void SearchByNumber(STU stu[],int n,int m);//按学号查询学生信息
void SearchByName(STU stu[],int n,int m);//按姓名查询学生信息
void ModifyRecord(STU stu[],int n,int m);//修改学生信息
void CalculateScoreOfStudent(STU stu[],int n,int m);//计算学生的总分和平均分
void CalculateScoreOfCourse(STU stu[],int n,int m);//计算某门课程的总分和平均分
void SortByNum(STU stu[],int n,int m);//按学号排序
void SortByName(STU stu[],int n,int m);//按姓名排序
void SortByScore(STU stu[],int n,int m,int (*compare)(float a,float b));//按每个学生平均分进行排序
int Ascending(float a,float b);//升序排序
int Descending(float a,float b);//降序排序
void StatisticAnalysis(STU stu[],int n,int m);//统计并输出各个分数段学生人数及占比
void PrintRecord(STU stu[],int n,int m);//打印学生成绩
void WriteToFile(STU stu[],int n,int m);//将学生信息保存至文件中
int ReadFromFile(STU stu[],int *n,int *m,int *first);//将学生信息从文件中读出，存入内存，方便对学生信息进行处理

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
                    printf("\n第%d个学生信息为：",i+1);
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
                    system("pause");
                    break;
                }
                AppendRecord(stu,&n,m);
                system("pause");
                break;
            case 3:
                system("cls");
                if(first) {
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息，请先输入！\n");
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
                    printf("系统中尚无学生成绩信息，请先输入！\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                     printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息，请先输入！\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("系统中尚无学生成绩信息,请先输入!\n");
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
                    printf("尚未输入学生信息或文件打开失败，请先检查！\n");
                    getch( );
                    break;
                }
                getch( );
                break;
            case 0:
                system("cls");
                printf("退出系统！\n");
                exit(0);
            default:
                system("cls");
                printf("输入出错，请重新选择操作！\n");
                break;
        }
    }
}
int Menu(void)
{
    int posy=5;
    int option;                     //保存用户输入的操作代号的变量
    int i,j;
    SetPosition(POS_X3,posy);
    printf("学生成绩管理系统\n");//输出系统名字
    //输出系统名字和功能说明之间的两行短横线
    for(i=0;i<2;i++)
    {
        SetPosition(POS_X1,++ posy);
        for(j=0;j<55;j++)
        {
            printf( "-") ;
        }
    }
//输出系统支持的功能和对应的功能代号
    SetPosition(POS_X1,++posy);
    printf("1.输入学生信息");
    SetPosition(POS_X4,posy);
    printf("2.增加学生成绩");
    SetPosition(POS_X1, posy+=2);
    printf("3.删除学生信息");
    SetPosition(POS_X4, posy);
    printf("4.按学号查找记录");
    SetPosition(POS_X1, posy+=2);
    printf("5.按姓名查找记录");
    SetPosition(POS_X4, posy);
    printf("6.修改学生信息");
    SetPosition(POS_X1, posy+=2);
    printf("7.计算学生成绩");
    SetPosition(POS_X4, posy);
    printf("8.计算课程成绩");
    SetPosition(POS_X1, posy+=2);
    printf("9.按学号排序");
    SetPosition(POS_X4, posy);
    printf("10.按姓名排序");
    SetPosition(POS_X1, posy+=2);
    printf("11.按总成绩降序排序");
    SetPosition(POS_X4, posy);
    printf("12.按总成绩升序排序");
    SetPosition(POS_X1, posy+=2);
    printf("13.学生成绩统计");
    SetPosition(POS_X4, posy);
    printf("14.打印学生记录");
    SetPosition(POS_X1, posy+=2);
    printf("15.学生记录存盘");
    SetPosition(POS_X4, posy);
    printf("16.从磁盘读取学生记录");
    SetPosition(POS_X1, posy+=2);
    printf("0.退出");
//输出系统支持的功能与输入提示语之间的两行短横线
    for(i=0;i<2;i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0;j<55;j++)
        {
            printf( "-" ) ;
        }
    }
//提示用户输入所要执行的功能代号
    SetPosition(POS_X1,++posy);
    printf("请选择你想要进行的操作[0~16]:[  ]\b\b\b");
    scanf_s("%d",&option);
    return option;
}
/*
函数功能：设置文字输出的起始位置
形式参数：文字输出起始位置的坐标x，y，int类型
函数返回值:void
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
函数功能：输入学生信息
形式参数: n,m:int*,stu:STU*
函数返回值:void
*/
void InputRecord(STU *stu,int *n,int *m)
{
    int i, j;
    int posy = 6;
    SetPosition(POS_X2, posy);//设置光标位置，即需要显示的位置
    printf("输入学生人数(n<%d):", STU_NUM);
    scanf_s("%d", n);
    SetPosition(POS_X2, posy += 2);//设置光标位置，即需要显示的位置
    printf("输入课程门数(m<%d):", COURSE_NUM);
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
    printf("输入学生的学号、姓名和各门课程成绩：");
    for (i = 0; i < *n; i++) {
        SetPosition(POS_X2, ++posy);
        printf("输入第%d个学生信息:\t", i + 1);
        scanf_s("%ld%s", &stu[i].num, &stu[i].name);
        for (j = 0; j < *m; j++) {
            scanf_s("%f", &stu[i].score[j]);
        }
    }
}
/*
函数功能：增加学生记录一条至多条学生记录
形式参数:n:int*,m;int,stu:STU*
函数返回值:void
*/
void AppendRecord(STU stu[],int*n,int m)
{
    int i,j;
    int num_record;
    printf("请输入需要增加的学生记录条数：");
    scanf_s("%d",& num_record);
    while(*n+num_record>STU_NUM)//判断新增记录与原有记录之和是否小于设定上限
    {
        printf("要增加的记录条数太多，请重新输入：");
        scanf_s("%d",&num_record);
    }
    for(i=*n;i<*n+num_record;i++)
    {
        printf("输入第%d个学生信息:\t",i+1);
        scanf_s("%ld%s",&stu[i]. num,stu[i]. name);
        for(j=0;j<m;j++)
        {
            scanf_s("%f",&stu[i]. score[j]);
        }
    }
    *n=*n+num_record;
    printf("添加完毕!\n");
}
/*
2 函数功能：从已有的磁盘文件student. txt中，读出学生人数，课程门数以及每个学生的信息，并存储到内存中对应的整型变量n，m和结构体数组stu中，并将标志变量first的值清零
3 形式参数:n,m,first:int*,stu:STU*
4 函数返回值：int(返回1，表明打开文件失败，返回0，表明成功从磁盘读出数据)
*/
int ReadFromFile(STU stu[],int *n,int *m,int *first)
{
    //定义文件指针
    FILE*fp;
    int i,j;
    int posy=8;
    SetPosition(POS_X1, posy);
    //打开文件，指定对文件的处理方式为写入，并让指针指向文件
    if((fp=fopen("\\student.txt","r"))==NULL)
    {
        printf("磁盘文件student. txt无法打开");
        return 1;
    }//将数据按指定格式从磁盘文件读出，包括学生人数n、课程门数m以及每位学生的信息
    fscanf_s(fp,"%10d%10d",n,m);
    for( i=0;i<*n;i++ ) {
        fscanf_s(fp, "%10ld", &stu[i].num);
        fscanf_s(fp, "%10s", stu[i].name);
        for (j = 0; j < *m; j++ ) {
            fscanf_s(fp, "%10f", &stu[i].score[j]);
        }
        fscanf_s(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
    }
    *first=0;//修改标志变量
    //关闭文件
    fclose(fp);
    printf("数据从磁盘读取完毕!");
    return 0;
}
/*
函数功能：计算学生成绩
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void CalculateScoreOfStudent(STU stu[],int n,int m)
{
    int i, j;
    printf("每个学生各门课程的总分和平均分为：\n");
    for (i = 0; i < n; i++) {
        stu[i].sum = 0;
        for (j = 0; j < m; j++) {
            stu[i].sum += stu[i].score[j];
        }
        stu[i].aver = stu[i].sum/(float)m;
        printf("第%d个学生:总分=%.2f,平均分=%.2f\n", i + 1, stu[i].sum, stu[i].aver);
    }
}
/*
函数功能：计算课程成绩
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void CalculateScoreOfCourse(STU stu[],int n,int m)
{
    int i, j;
    float sum[COURSE_NUM],aver[COURSE_NUM];
    int posy=7;
    SetPosition(POS_X1,posy);
    printf("各门课程的总分和平均分的计算结果为：");
    for (j= 0; j<m; j++) {
        sum[j]=0;
        for (i= 0; i < n; i++)
            sum[j] += stu[i].score[j];
        aver[j]=sum[j]/(float)n;
        printf("第%d门课程:总分=%.2f,平均分=%.2f\n", j + 1, sum[j], aver[j]);
    }
}
/*
函数功能：输出学生人数n，课程门数m以及每个学生的信息到student. txt中
形式参数:n. m:int,stu:STU·
函数返回值:void
*/
void WriteToFile(STU stu[],int n,int m)
{
    int i,j;//定义文件指针
    FILE *fp;//打开文件，指定对文件的处理方式为写人，并让指针指向文件
    if((fp=fopen("\\student.txt","w"))==NULL)
    {
        printf("文件student.txt无法正常打开!");
        exit(0) ;
    }
    //将数据按指定格式写入文件，包括学生人数n，课程门数m以及每个学生的信息
    fprintf(fp,"%10d%10d\n",n,m);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%10ld%10s\n",stu[i]. num,stu[i]. name);
        for(j=0;j<m;j++)
        {
            fprintf(fp,"%10.lf",stu[i]. score[j]);
        }
        fprintf(fp,"%10.lf%10.lf\n",stu[i].sum,stu[i].aver);
    }//关闭文件
    fclose(fp);//提示用户存盘操作完毕
    printf("存盘完毕!\n");
}


/*
函数功能：按学号查找学生记录
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void SearchByNumber(STU *stu,int n,int m)
{
    long id;
    int i, j;
    printf("请输入你要查找的学生的学号：");
    scanf_s("%ld", &id);
    for (i = 0; i < n; i++)
    {
        if (stu[i].num == id) {
            printf("找到了,该学号对应的学生信息为:\n");
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f", stu[i].sum, stu[i].aver);
            return;
        }
    }
    printf("未找到这个学号对应的学生记录\n");
}
 /*
函数功能：按姓名查找学生记录
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void SearchByName(STU*stu,int n,int m)
{
     int flag = 1;
     int i, j;
     int k = 0;
     char name[NAME_LEN];
     printf("请输入你要查找的学生的姓名：");
     scanf("%s", name);
     for (i = 0; i < n; i++)
     {
         if (strcmp(stu[i].name, name) == 0) {
             printf("找到了,第%d学生信息为:\n", ++k);
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
         printf("未找到这个姓名对应的学生记录\n");
     }
 }
 /*
函数功能：删除指定学号的学生记录
形式参数:n:int*,m:int,stu:STU*
函数返回值:void
*/
void DeleteRecord(STU stu[],int *n,int m)
{
    int i,j;
    long id;
    char ch;
    printf("请输入你要删除学生信息对应的学号：");
    scanf_s("%ld",&id);
    for(i=0;i<*n;i++) {
        if (stu[i].num == id) {
            printf("找到了该生记录,信息为:\n");
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
            printf("请确认是否需要删除这条记录?(Y/y或N/n):");
            getchar();
            scanf("%c", &ch);
            if (ch == 'Y' || ch == 'y') {
                for (j = i; j < *n - 1; j++) {
                    stu[j] = stu[j + 1];
                }
                (*n)--;
                printf("删除完毕\n");
                return;
            } else if (ch == 'N' || ch == 'n') {
                printf("找到了该学生记录,但不删除\n");
                return;
            } else {
                printf("输入出错!\n");
                return;
            }
        }
    }
    printf("未找到该生记录!\n");
 }
 /*
函数功能：修改指定学号的学生记录
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void ModifyRecord(STU stu[],int n,int m) {
     int i, j;
     long id;
     char ch;

     printf("请输入需要修改信息对应的学号：");

     scanf_s("%ld", &id);
     for (i = 0; i < n; i++) {
         if (stu[i].num == id) {
             printf("找到了该生记录,信息为:\n");
             printf("%10ld%15s", stu[i].num, stu[i].name);
             for (j = 0; j < m; j++) {
                 printf("%10.2f", stu[i].score[j]);
             }
             printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);

             printf("请确认是否需要修改?(Y/N或y/n):-");
             getchar();
             scanf("%c", &ch);

             if (ch == 'Y' || ch == 'y') {
                 printf("请输入要修改的学生信息:");
                 scanf_s("%ld%s", &stu[i].num, stu[i].name);
                 stu[i].sum = 0;
                 for (j = 0; j < m; j++) {
                     scanf_s("%f", &stu[i].score[j]);
                     stu[i].sum += stu[i].score[j];
                 }
                 stu[i].aver = stu[i].sum / (float) m;
                 printf("修改完毕\n");
                 return;
             }
             else if (ch == 'N' || ch == 'n') {
                 printf("找到了该生记录,但不修改\n");
                 return;
             }
             else {
                 printf("输入出错!\n");
                 return;
             }
         }
     }
     printf("未找到该生记录!\n");
 }
 /*
函数功能：输出所有学生记录
形式参数:n. m:int,stu:STU*
函数返回值:void
*/
void PrintRecord(STU stu[],int n,int m)
{
    int i ,j;
    printf("学号\t\t姓名\t\t");
    for(j=0;j<m;j++) {
     printf("课程%d\t\t",j+1);
    }
    printf("总分\t\t平均分\n");
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
函数功能：按照学生姓名字典顺序对所有学生记录从小到大排序
形式参数:n. m:int. stu:STU*
函数返回值:void
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
    printf("按姓名字典对学生记录排序完毕");
}
/*
函数功能：按照学号对所有学生记录从小到大排序
形式参数:n,m:int,stu:STU*
函数返回值:void
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
    printf("按学号从小到大对学生记录排序完毕");
}
/*
函数功能：按照学生成绩总分对所有学生记录进行升序或降序排序
形式参数:n,m;int,stu:STU*
函数返回值:void
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
        printf("按学生成绩总分对学生记录排序完毕");
    }
}
/*
函数功能：规定降序排序规则
形式参数:a,b:float
函数返回值:int
 */
int Descending(float a,float b) {
    return a > b;
}
    /*
函数功能：规定升序排序规则
形式参数:a,b:float
函数返回值:int
*/
int Ascending(float a,float b) {
    return a < b;
}
/*
函数功能：统计并输出各个分数段学生人数及占比
形式参数:n,m:int,stu:STU*
函数返回值:void
*/
void StatisticAnalysis(STU stu[],int n,int m) {
    int i, j, t[6];
    for (j = 0; j < m; j++) {
        printf("\n课程%d成绩统计结果为:\n", j + 1);
        printf("分数段\t人数\t占比\n");

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

    printf("\n学生成绩平均分统计结果为：\n");
    printf("分数段\t人数\t占比\n");
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