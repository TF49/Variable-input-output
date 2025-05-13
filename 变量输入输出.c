#include<stdio.h>
#define FORMAT "%d %s %.1f\n"
#define ELEMENT score[i].id,score[i].name,score[i].grade
#define HEADER "学号  姓名  成绩\n"
#include<string.h> 
#define MAX_N 100 
int n=0;//学生初始数量
struct stuinfor{
	int id;//学号
	char name[10];//姓名
	float grade;//成绩 
}score[100];
void menu()
{
     	printf("1.成绩录入\n");
	    printf("2.成绩修改\n");
	    printf("3.成绩删除\n");
	    printf("4.成绩查找\n");
	    printf("5.成绩排序\n");
	    printf("6.成绩插入\n");
	    printf("0.退出系统\n"); 
	    printf("----------\n");
	    printf("请输入菜单编号\n");
 } 
void infor()
{
	int i;
	printf("学生数量：%d\n",n);
	printf(HEADER);
	for(i=0;i<n;i=i+1)
	 {
	 	printf(FORMAT,ELEMENT);
	 }
}
//录入成绩1：多个变量
void add1()
{
	int a,b,c;
	    printf("请输入第1个成绩：\n");
	    scanf("%d",&a);
	    printf("请输入第2个成绩：\n");
	    scanf("%d",&b);
    	printf("请输入第3个成绩：\n");
		scanf("%d",&c);
		printf("你输入的成绩分辨是:\n");
		printf("%d %d %d\n",a,b,c);
} 	
//录入成绩2：一维数据 
void add2()
{
	int a[3];
		printf("请输入第1个成绩：\n");
		scanf("%d",&a[0]);
		printf("请输入第2个成绩：\n");
		scanf("%d",&a[1]);
		printf("请输入第3个成绩：\n");
		scanf("%d",&a[2]);
		printf("你输入的成绩分辨是:\n");
		printf("%d %d %d\n",a[0],a[1],a[2]);
}
//录入成绩3：一维数据 + 循环 
void add3()
{
	int a[3];
	int i;
	for(i=0;i<3;i=i+1)
	{
	    printf("请输入第%d个成绩：\n",i+1);
	    scanf("%d",&a[i]);
	} 
	    printf("你输入的成绩分别是:\n");
	for(i=0;i<3;i++)
	{
	    printf("%d ",a[i]);
	}
		printf("\n");
}
//录入成绩4：二维数据 + 循环 
void add4()
{
	int a[3][2];
	int i; 
	for(i=0;i<3;i=i+1)
	{
	    printf("请输入第%d个学号和成绩：\n",i+1);
	    scanf("%d %d",&a[i][0],&a[i][1]);
	}  
	    printf("你输入的学号和成绩分别是：\n");
	    printf("学号 成绩\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %d\n",a[i][0],a[i][1]);
	}
 } 
//录入成绩5：自定义函数
void add5()
{
	int i;
	printf("请输入学生个数：");
	scanf("%d",&n);
	for(i=0;i<n;i=i+1)
	{
		printf("请输入第%d个学生的学号、姓名和成绩：",i+1);
		scanf("%d %s %f",&score[i].id,&score[i].name,&score[i].grade);
	} 
	    infor();//输出显示 
 } 
void edit()
{
	int i,num;
	int k=0;
	if(n==0)
	{
		printf("没有学生！\n");
		return;
	}
	printf("请输入要修改的学号：");
	scanf("%d",&num);
	for(i=0;i<n;i=i+1)
	{
		if(num==score[i].id)
		{
			printf("找到了！请输入新的成绩：");
			scanf("%f",&score[i].grade);
			printf("修改成功！\n");
			infor();
			break; 
		}
		 k=k+1;//每次学号都不符合，则k自增一次 
	 } 
	 if(k==n)
	 {
	 	printf("未找到学生！\n");
	  } 
 } 
 void del()
 {
	int i,j,num;
	int k=0;
	char c[2];
	if(n==0)
	{
		printf("没有学生！\n");
		return;
	}
	printf("请输入要删除的学号：");
	scanf("%d",&num);
	for(i=0;i<n;i=i+1)
	{
		if(num==score[i].id)
		{
			printf("你是否要删除（Y/N）：");
			scanf("%s",&c);
			if(strcmp(c,"Y")==0||strcmp(c,"y")==0)
			{
				for(j=i;j<n-i;j=j+1)
				{
					score[j]=score[j+1];//将记录前移，变相实现删除
				}
				printf("删除成功！\n");
				n=n-1;
				infor();
				return;				 
			}
			else
			{
				return;
			}
		}
		k++;//每次学号都不符合，则k自增1次 
	}
	if(k==n)
	{
		printf("未找到学生！\n");
	} 	
}

void search()
{
	int i,num;
	int k=0;
	if(n==0)
	{
		printf("没有学生！\n");
		return;
	}
	printf("请输入要查找的学号：");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==score[i].id)
		{
			printf("找到了！成绩是：\n");
			printf(FORMAT,ELEMENT);
		}
		k++;//每次学号都不符合，则k自增1次 
	}
	if(k==n)
	{
		printf("未找到学生！\n");
	}	
}
void sort1()//按成绩从小到大排序 
{
	int i,j;
	int k=0;
	int tempid;//临时变量学号 
	char tempname[10];//临时变量姓名 
	float tempgrade; //临时变量成绩 
	if(n==0)
	{
		printf("没有学生！\n");
		return;
	}
	for(i=0;i<n-1;i=i+1)//外层循环用于实现总的循环次数，比如3个数比较，则最多循环2次即可完成排序 
	{
		for(j=0;j<n-1;j=j+1)//内层循环用于找出当前循环的最大成绩，如果满足条件则前后交换，使其排到最后 
			{
				if(score[j].grade>score[j+1].grade)//如果前面的成绩大于后面的成绩
			{
				tempgrade=score[j].grade;//把大的成绩存到临时变量 
				score[j].grade=score[j+1].grade;//把小的成绩赋给原来大成绩所在位置
				score[j+1].grade=tempgrade;//把临时变量存放的成绩赋给原来小成绩所在位置
				//交换学号 
				tempid=score[j].id;
				score[j].id=score[j+1].id;
				score[j+1].id=tempid; 
				//交换姓名
				//tempname=score[j].name;不能直接把字符串赋值给字符串变量 
				//score[j].name=score[j+1].name;不能直接把字符串赋值给字符串变量 
				//score[j+1].name=tempname;不能直接把字符串赋值给字符串变量 
				//字符串的赋值通过strcpy函数实现 
				strcpy(tempname,score[j].name);
				strcpy(score[j].name,score[j+1].name);
				strcpy(score[j+1].name,tempname);
			}
			} 
			
		}
		infor(); 
}
void sort2()//按成绩从小到大排序,使用结构体作为中间临时交换 
{
	struct stuinfor t;//用于存放代交换结构体的临时空间 
	int i,j;
	int k=0;
	if(n==0)
	{
		printf("没有学生！\n");
		return;
	}
	for(i=0;i<n-1;i=i+1)//外层循环用于实现总的循环次数，比如3个数比较，则最多循环2次即可完成排序 
	{
		for(j=0;j<n-1;j=j+1)//内层循环用于找出当前循环的最大成绩，如果满足条件则前后交换，使其排到最后 
			{
				if(score[j].grade>score[j+1].grade)//把成绩大的整条记录存放到临时结构体空间t 
			{
				t=score[j];//把成绩小的整条记录前移
				score[j]=score[j+1];//把临时结构体t中的整条记录赋给后一个空间 
				score[j+1]=t;
		    }
		    }
	}
}
void insert()
{
	int i;
	if(n==MAX_N)//判断学生数量是否达到最大 
	{
		printf("记录已满，无法输入更多记录\n");
		return; 
	} 
	int p;
	printf("请输入要插入的位置(0-%d)",n);
	scanf("%d",&p);
	if(p<0||p>n)//判断输入的位置是否有效 
	{
		printf("无效插入位置\n");
		return; 
	}
	for(i=n;i>p;i=i-1)//将插入位置后的学生向后移动 
	{
		score[i]=score[i-1];
		break;
	}
	printf("请输入插入学生学号 姓名 成绩：\n");//输入学号 姓名 成绩
	scanf("%d %s %.1f\n",&score[i].id,&score[i].name,&score[i].grade);
	n=n+1;

	infor();
}
int main()
{
    while(1)
	{
	    int m; 
	    menu();
		scanf("%d",&m);
		printf("你输入的是：%d\n",m);
		switch(m)
	{
		case 1:
		    //add1();
		    //add2(); 
		    //add3();
		    //add4();
		    add5();
		    break;
		case 2:
		    edit();
			break;
		case 3:
		    del();
			break;
		case 4:
		    search();
			break;
		case 5:
		    //sort1();
		    sort2();
		    break;
		case 6:
			insert();
			break;
		case 0:
		    printf("您已退出！\n");
		    //exit(0);
		default:
		    printf("输入错误！\n"); 
		 
	}
	}
	
	return 0;
}
