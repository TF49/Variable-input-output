#include<stdio.h>
#define FORMAT "%d %s %.1f\n"
#define ELEMENT score[i].id,score[i].name,score[i].grade
#define HEADER "ѧ��  ����  �ɼ�\n"
#include<string.h> 
#define MAX_N 100 
int n=0;//ѧ����ʼ����
struct stuinfor{
	int id;//ѧ��
	char name[10];//����
	float grade;//�ɼ� 
}score[100];
void menu()
{
     	printf("1.�ɼ�¼��\n");
	    printf("2.�ɼ��޸�\n");
	    printf("3.�ɼ�ɾ��\n");
	    printf("4.�ɼ�����\n");
	    printf("5.�ɼ�����\n");
	    printf("6.�ɼ�����\n");
	    printf("0.�˳�ϵͳ\n"); 
	    printf("----------\n");
	    printf("������˵����\n");
 } 
void infor()
{
	int i;
	printf("ѧ��������%d\n",n);
	printf(HEADER);
	for(i=0;i<n;i=i+1)
	 {
	 	printf(FORMAT,ELEMENT);
	 }
}
//¼��ɼ�1���������
void add1()
{
	int a,b,c;
	    printf("�������1���ɼ���\n");
	    scanf("%d",&a);
	    printf("�������2���ɼ���\n");
	    scanf("%d",&b);
    	printf("�������3���ɼ���\n");
		scanf("%d",&c);
		printf("������ĳɼ��ֱ���:\n");
		printf("%d %d %d\n",a,b,c);
} 	
//¼��ɼ�2��һά���� 
void add2()
{
	int a[3];
		printf("�������1���ɼ���\n");
		scanf("%d",&a[0]);
		printf("�������2���ɼ���\n");
		scanf("%d",&a[1]);
		printf("�������3���ɼ���\n");
		scanf("%d",&a[2]);
		printf("������ĳɼ��ֱ���:\n");
		printf("%d %d %d\n",a[0],a[1],a[2]);
}
//¼��ɼ�3��һά���� + ѭ�� 
void add3()
{
	int a[3];
	int i;
	for(i=0;i<3;i=i+1)
	{
	    printf("�������%d���ɼ���\n",i+1);
	    scanf("%d",&a[i]);
	} 
	    printf("������ĳɼ��ֱ���:\n");
	for(i=0;i<3;i++)
	{
	    printf("%d ",a[i]);
	}
		printf("\n");
}
//¼��ɼ�4����ά���� + ѭ�� 
void add4()
{
	int a[3][2];
	int i; 
	for(i=0;i<3;i=i+1)
	{
	    printf("�������%d��ѧ�źͳɼ���\n",i+1);
	    scanf("%d %d",&a[i][0],&a[i][1]);
	}  
	    printf("�������ѧ�źͳɼ��ֱ��ǣ�\n");
	    printf("ѧ�� �ɼ�\n");
	for(i=0;i<3;i=i+1)
	{
		printf("%d %d\n",a[i][0],a[i][1]);
	}
 } 
//¼��ɼ�5���Զ��庯��
void add5()
{
	int i;
	printf("������ѧ��������");
	scanf("%d",&n);
	for(i=0;i<n;i=i+1)
	{
		printf("�������%d��ѧ����ѧ�š������ͳɼ���",i+1);
		scanf("%d %s %f",&score[i].id,&score[i].name,&score[i].grade);
	} 
	    infor();//�����ʾ 
 } 
void edit()
{
	int i,num;
	int k=0;
	if(n==0)
	{
		printf("û��ѧ����\n");
		return;
	}
	printf("������Ҫ�޸ĵ�ѧ�ţ�");
	scanf("%d",&num);
	for(i=0;i<n;i=i+1)
	{
		if(num==score[i].id)
		{
			printf("�ҵ��ˣ��������µĳɼ���");
			scanf("%f",&score[i].grade);
			printf("�޸ĳɹ���\n");
			infor();
			break; 
		}
		 k=k+1;//ÿ��ѧ�Ŷ������ϣ���k����һ�� 
	 } 
	 if(k==n)
	 {
	 	printf("δ�ҵ�ѧ����\n");
	  } 
 } 
 void del()
 {
	int i,j,num;
	int k=0;
	char c[2];
	if(n==0)
	{
		printf("û��ѧ����\n");
		return;
	}
	printf("������Ҫɾ����ѧ�ţ�");
	scanf("%d",&num);
	for(i=0;i<n;i=i+1)
	{
		if(num==score[i].id)
		{
			printf("���Ƿ�Ҫɾ����Y/N����");
			scanf("%s",&c);
			if(strcmp(c,"Y")==0||strcmp(c,"y")==0)
			{
				for(j=i;j<n-i;j=j+1)
				{
					score[j]=score[j+1];//����¼ǰ�ƣ�����ʵ��ɾ��
				}
				printf("ɾ���ɹ���\n");
				n=n-1;
				infor();
				return;				 
			}
			else
			{
				return;
			}
		}
		k++;//ÿ��ѧ�Ŷ������ϣ���k����1�� 
	}
	if(k==n)
	{
		printf("δ�ҵ�ѧ����\n");
	} 	
}

void search()
{
	int i,num;
	int k=0;
	if(n==0)
	{
		printf("û��ѧ����\n");
		return;
	}
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==score[i].id)
		{
			printf("�ҵ��ˣ��ɼ��ǣ�\n");
			printf(FORMAT,ELEMENT);
		}
		k++;//ÿ��ѧ�Ŷ������ϣ���k����1�� 
	}
	if(k==n)
	{
		printf("δ�ҵ�ѧ����\n");
	}	
}
void sort1()//���ɼ���С�������� 
{
	int i,j;
	int k=0;
	int tempid;//��ʱ����ѧ�� 
	char tempname[10];//��ʱ�������� 
	float tempgrade; //��ʱ�����ɼ� 
	if(n==0)
	{
		printf("û��ѧ����\n");
		return;
	}
	for(i=0;i<n-1;i=i+1)//���ѭ������ʵ���ܵ�ѭ������������3�����Ƚϣ������ѭ��2�μ���������� 
	{
		for(j=0;j<n-1;j=j+1)//�ڲ�ѭ�������ҳ���ǰѭ�������ɼ����������������ǰ�󽻻���ʹ���ŵ���� 
			{
				if(score[j].grade>score[j+1].grade)//���ǰ��ĳɼ����ں���ĳɼ�
			{
				tempgrade=score[j].grade;//�Ѵ�ĳɼ��浽��ʱ���� 
				score[j].grade=score[j+1].grade;//��С�ĳɼ�����ԭ����ɼ�����λ��
				score[j+1].grade=tempgrade;//����ʱ������ŵĳɼ�����ԭ��С�ɼ�����λ��
				//����ѧ�� 
				tempid=score[j].id;
				score[j].id=score[j+1].id;
				score[j+1].id=tempid; 
				//��������
				//tempname=score[j].name;����ֱ�Ӱ��ַ�����ֵ���ַ������� 
				//score[j].name=score[j+1].name;����ֱ�Ӱ��ַ�����ֵ���ַ������� 
				//score[j+1].name=tempname;����ֱ�Ӱ��ַ�����ֵ���ַ������� 
				//�ַ����ĸ�ֵͨ��strcpy����ʵ�� 
				strcpy(tempname,score[j].name);
				strcpy(score[j].name,score[j+1].name);
				strcpy(score[j+1].name,tempname);
			}
			} 
			
		}
		infor(); 
}
void sort2()//���ɼ���С��������,ʹ�ýṹ����Ϊ�м���ʱ���� 
{
	struct stuinfor t;//���ڴ�Ŵ������ṹ�����ʱ�ռ� 
	int i,j;
	int k=0;
	if(n==0)
	{
		printf("û��ѧ����\n");
		return;
	}
	for(i=0;i<n-1;i=i+1)//���ѭ������ʵ���ܵ�ѭ������������3�����Ƚϣ������ѭ��2�μ���������� 
	{
		for(j=0;j<n-1;j=j+1)//�ڲ�ѭ�������ҳ���ǰѭ�������ɼ����������������ǰ�󽻻���ʹ���ŵ���� 
			{
				if(score[j].grade>score[j+1].grade)//�ѳɼ����������¼��ŵ���ʱ�ṹ��ռ�t 
			{
				t=score[j];//�ѳɼ�С��������¼ǰ��
				score[j]=score[j+1];//����ʱ�ṹ��t�е�������¼������һ���ռ� 
				score[j+1]=t;
		    }
		    }
	}
}
void insert()
{
	int i;
	if(n==MAX_N)//�ж�ѧ�������Ƿ�ﵽ��� 
	{
		printf("��¼�������޷���������¼\n");
		return; 
	} 
	int p;
	printf("������Ҫ�����λ��(0-%d)",n);
	scanf("%d",&p);
	if(p<0||p>n)//�ж������λ���Ƿ���Ч 
	{
		printf("��Ч����λ��\n");
		return; 
	}
	for(i=n;i>p;i=i-1)//������λ�ú��ѧ������ƶ� 
	{
		score[i]=score[i-1];
		break;
	}
	printf("���������ѧ��ѧ�� ���� �ɼ���\n");//����ѧ�� ���� �ɼ�
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
		printf("��������ǣ�%d\n",m);
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
		    printf("�����˳���\n");
		    //exit(0);
		default:
		    printf("�������\n"); 
		 
	}
	}
	
	return 0;
}
