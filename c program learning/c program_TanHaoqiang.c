//******************* P239 将数组反转
/*
	将数组的前后相互交换
	将数组进行反转
	将a[0]和a[n-1]相互交换

	定义一个函数inv进行数组反转
*/

//将数组作为 形参 和 实参
#include<stdlib.h>
#include<stdio.h>

int main()
{
	void inv(int a[],int num);
	
	int a[]={3,7,9,11,0,6,7,5,4,2};
	int i;

	printf("The original array:\n");
	for(i = 0; i<10; i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");

	//进行数组反转
	inv(a,10);  //数组为实参
	printf("The array has been inverted:\n");
	for(i = 0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");


	return 0;
}

//数组为形参
void inv(int a[],int num)
{
	int mid = (num-1)/2;
	int temp;
	int i;

	for(i = 0; i<mid; i++)
	{
		temp = a[i];
		a[i] = a[num-1-i];
		a[num-1-i] = temp;
	}

}


//指针为形参
void inv(int *p,int num)
{
	int mid = (num-1)/2;
	int temp;
	int *begin,*end;

	begin = p;
	end = p + num - 1;

	for(; begin<=end; begin++, end--)
	{
		temp = *begin;
		*begin = *end; 
		*end = temp;	
	}

}
//调用--指针为实参
	int *p=a;
	inv(p,10);



//https://blog.csdn.net/rock4you/article/details/81710640
//多维函数在传递形参时需要至少指明最低维度的数量
//**************** P249遍历多维数组

#include<stdlib.h>
#include<stdio.h>


int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};

	int *p;

	for(p = a[0][0]; p<a[0][0]+12; p++)
	{
		if((p-a[0][0])%4 == 0) printf("\n");
		printf("%4d",p);
	}

	printf("\n");
	return 0;
}


//多维数组--以函数传递

#include<stdlib.h>
#include<stdio.h>


int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};

	inverse(a,12);
	return 0;
}
//遍历函数
void inverse(int a[3][4],int num)
{
	int *p;

	for(p = a[0]; p<a[0]+12; p++)
	{
		if((p-a[0])%4 == 0) printf("\n");
		printf("%4d",*p);
	}

	printf("\n");
}


//输出指定位置的元素值

#include<stdlib.h>
#include<stdio.h>


int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};

	int (*p)[4];
	p = a;
	int i,j;

	scanf("%d,%d",&i,&j);
	printf("a[%d][%d] = %d",i,j,*(*(p+i)+j));

	printf("\n");
	return 0;
}

//数组指针

#include<stdlib.h>
#include<stdio.h>
int main()
{
	int a[4]={1,3,5,7};

	int (*p)[4];
	p = &a;

	printf("%d",(*p)[2]);

	printf("\n");
	return 0;
}

//**************P253 多维数组

/*
	对于多维数组，
	a , a+i, a[i], *(a+i), *(a+i)+j, a[i]+j
	都是表示的地址
	
	a[0]相当于一维数组的名称，则为地址
*/
//3个学生，4门功课，计算平均数和查询第n个学生的成绩
#include<stdlib.h>
#include<stdio.h>

int main()
{
		
	void average(float *p, int num);
	void search(float (*p)[4], int index);

	float score[3][4]={{65,67,70,60},{80,87,90,81},{90,99,100,98}};

	float *p;
	p = &score[0][0];

	average(p,12);

	float (*q)[4];
	q = score;
	search(q,2);


	return 0;
}

//平均数
void average(float *p, int num)
{
	float *p_end;
	float sum = 0,aver;

	p_end = p+num-1;

	for(; p<=p_end; p++)
	{
		sum = sum + *p;
	}
	aver = sum / num;
	printf("aver = %5.3f  \n",aver);

}

void search(float (*p)[4], int index)
{
	int i;
	printf("The score of No.%d are:\n",index);

	for(i = 0; i<4; i++)
	{
		printf("%5.2f  ",*(*(p+index)+i));
	}
}

//************************P254 查找不及格学生成绩
//3个学生，4门功课，计算平均数和查询第n个学生的成绩
//查找出一门一门以上不及格的学生，输出全部成绩

#include<stdlib.h>
#include<stdio.h>


int main()
{
	void search(float (*p)[4], int num);

	float score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};

	search(score,3);

	return 0;
}
void inverse(float (*p)[4], int index)
{
	int i;
	for(i = 0; i<4; i++)
	{
		printf("%5.2f  ",(*p)[i]);
	}
	printf("\n");

}

void search(float (*p)[4], int num)
{
	int i,j;
	
	int flag,index;
	for(i = 0; i<num; i++,p++)
	{
		flag = 0;
		for(j = 0; j<4; j++)
		{
			if((*p)[j]<60) {flag = 1;index = i;break;}
		}
		if(flag == 1)
		{
			printf("No. %d fails his exams\n",index);
			inverse(p,index);
		}
	}

}

//************************P259 字符串指针赋值

#include<stdlib.h>
#include<stdio.h>

int main()
{
	
	char a[] = "I am a student.";
	printf("string a is:%s \n",a);

	char b[20];

	char *p1, *p2;
	p1 = a; p2 = b;

	for(;*p1 != '\0'; p1++, p2++)
	{
		*p2 = *p1;
	}
	*p2 = '\0';
	printf("string b is:%s ",b);

	return 0;
}


//**************** P269 函数指针
/*
	定义两个函数，通过switch选择
	函数指针可以指向不同的函数
	通过指向不同的函数进行不同的操作
	
*/

#include<stdlib.h>
#include<stdio.h>

int main()
{
	int max(int, int);
	int min(int, int);
	int (*p)(int, int);

	x = 3;
	y = 5;

	int n;
	scanf("%d", &n);
	switch(n)
	{
		case 1: p = max; break;
		case 2: p = min; break;
	}

	printf("%d",(*p)(x, y));
	

	return 0;
} 

int max(int x, int y)
{
	return(x > y? x:y);
}


int min(int x, int y)
{
	return(x > y? y:x);
}


//**************** P269 函数指针作为形参
/*
	定义两个函数，通过switch选择
	函数指针可以指向不同的函数
	通过指向不同的函数进行不同的操作
	
*/

#include<stdlib.h>
#include<stdio.h>

int main()
{
	int max(int, int);
	int min(int, int);
	int add(int x, int y);
	int fun(int x, int y, int (*p)(int , int));
	int (*p)(int, int);

	int x = 3;
	int y = 5;

	int n;
	printf("从1,2,3中输入:\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1: p = max; break;
		case 2: p = min; break;
		case 3: p = add; break;
	}

	printf("%d",fun(x,y,p));
	

	return 0;
} 

int max(int x, int y)
{
	return(x > y? x:y);
}


int min(int x, int y)
{
	return(x > y? y:x);
}

int add(int x, int y)
{
	return x+y;
}

int fun(int x, int y, int (*p)(int , int))
{
	int result;
	result = (*p)(x, y);
	return result;
}


//************************P261 字符串数组
//赋值字符串from到to

#include<stdlib.h>
#include<stdio.h>


int main()
{
	void copy_string(char *from, char *to);
	char a[]="I am a teacher.";
	char b[]="You are a student.";
	printf("string a = %s\nstring b = %s\n",a,b);

	printf("copy string a to string b:\n");
	//数组名作为实参
	//copy_string(a,b);

	//指针作为实参
	char *from=a, *to=b;
	copy_string(from,to);
	printf("string a = %s\nstring b = %s\n",a,b);

	return 0;
}



//指针作为形参
void copy_string(char *from, char *to)
{
	int i;
	while(*from!='\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

//************************P274 输出指定学生的全部成绩
//3个学生，4门功课，计算查询第n个学生的成绩

#include<stdlib.h>
#include<stdio.h>


int main()
{
	float *search(float (*p)[4], int num);
	float *p;

	float score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};

	int k,i;
	printf("enter the number of student: ");
	scanf("%d",&k);
	p = search(score,k);

	for(i = 0; i<4; i++)
	{
		printf("%5.2f\t",*(p+i));
	}
	return 0;
}

float *search(float (*p)[4], int num)
{
	int i,j;
	
	float *pointer;
	pointer = *(p+num);
	return pointer;
}	


//************************P275 输出指定学生的全部成绩
//3个学生，4门功课，输出不及格学生的所有科目

#include<stdlib.h>
#include<stdio.h>


int main()
{
	void search(float (*p)[4]);
	void inverse(float *p,int index);

	float *p;

	float score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};

	search(score);
	return 0;
}
void inverse(float *p,int index)
{
	float *pt;
	pt =p;

	int i;
	printf("No. %d score:",index);
	for(i = 0; i<4; i++)
	{
		printf("%5.2f  ",*(p+i));
	}
	printf("\n");
}

void search(float (*p)[4])
{
	int i,j;
	int index;

	float *begin;
	for(i = 0; i<3; i++)
	{	
		float *pointer;
		pointer = *(p+i);
		for(j = 0; j<4; j++,pointer++)
			if(*pointer<=60){index = i; begin = *(p+i); inverse(begin, index);break;}
	}
}

//************************P275 输出不及格学生的全部成绩
//3个学生，4门功课
//设定一个数组指针，一旦有不及格就指向数组的首行，如果指针不为空，则输出所有

#include<stdlib.h>
#include<stdio.h>


int main()
{
	float *search(float (*p)[4]);
	float *p;

	float score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};

	int i,j;
	
	for(i = 0; i<3; i++)
	{
		p = search(score+i);
		if(p!=NULL)
		{
			for(j = 0; j<4; j++)
			{
				printf("%5.2f  ",*(p+j));
			}
			printf("\n");
		}
	}
	return 0;
}

float *search(float (*p)[4])
{
	int i,j;
	
	float *pointer;
	pointer = NULL;

	for(i = 0; i<4; i++)
	{
		if(*(*p+i)<60) pointer = *p;
	}

	return pointer;
}	


//************************P278 指针数组
//char *name[4]--包括4个指针的数组，这些指针都是指向char类型

#include<stdlib.h>
#include<stdio.h>


int main()
{
	void sort(char *name[],int n);
	void print(char *name[], int n);
	
	char *name[]={"Follow me","BASIC","Great Wall","hello","Computer"};
	int n = 5;

	sort(name,n);
	print(name,n);

	return 0;
}

void sort(char *name[],int n)
{
	int i,j,k;
	char *temp;

	for(i = 0; i<n-1; i++)
	{
		k = i;
		for(j = i+1; j<n; j++)
		{
			if(strcmp(name[k],name[j])>0) k=j;
		}
		if(k!=i)
		{
			temp = name[i];name[i] = name[k]; name[k] =temp;
		}
	}
}

void print(char *name[], int n)
{
	int i;
	for(i = 0; i<n; i++)
		printf("%s\n",name[i]);
}

//************************P300 结构体数组

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct person
{
	char name[20];
	int count;
}leader[3]={"Li",0,"Zhang",0,"Sun",0}

int main()
{
	char leader_name[20];
	int i,j;

	for(i=1; i<=5; i++)
	{
		scanf("%s",leader_name);
		for(j=0; j<3; j++)
		if(strcmp(leader_name,leader[j].name)==0) leader[j].count++;
	}
	
	printf("The result is:\n");
	for(j=0; j<3; j++)
	{
		printf("%s: %d",leader[j].name,leader[j].count);
		printf("\n");
	}
	return 0;
}


//************************P300 结构体数组

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student
{
	int num;
	char name[20];
	float score;
};

int main()
{
	struct student stu[5] = {{10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},{10108,"Ling",73.5},{10110,"Sun",100}};
	struct student temp;
	
	int i,j,k;
	printf("Before sorting:\n");
	for(i = 0; i<5; i++)
	{
		printf("num: %6d\tname:%6s\tscore:%5f\t",stu[i].num,stu[i].name,stu[i].score);
		printf("\n");
	}


	for(i=0; i<4; i++)
	{
		k = i;
		for(j = i+1; j<5 ;j++)
		{
			if(stu[k].score<=stu[j].score) k=j;
		}
		if(k!=i)
		{
			temp = stu[k]; stu[k] = stu[i]; stu[i] = temp;
		}
	}
	
	printf("After sorting:\n");
	for(i = 0; i<5; i++)
	{
		printf("num: %6d\tname:%6s\tscore:%5f\t",stu[i].num,stu[i].name,stu[i].score);
		printf("\n");
	}
	return 0;
}


//************************P305 结构体指针
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student
{
	int num;
	char name[20];
	float score;
};

int main()
{
	struct student stu[5] = {{10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},{10108,"Ling",73.5},{10110,"Sun",100}};
	struct student *pointer;
	pointer = stu;

	int i,j,k;
	
	printf("使用箭头访问:\n");
	for(i = 0; i<5; i++,pointer++)
	{
		printf("num: %6d\tname:%6s\tscore:%5f\t",pointer->num,pointer->name,pointer->score);
		printf("\n");
	}

	pointer = stu;
	printf("使用指针访问:\n");
	for(i = 0; i<5; i++,pointer++)
	{
		printf("num: %6d\tname:%6s\tscore:%5f\t",(*pointer).num,(*pointer).name,(*pointer).score);
		printf("\n");
	}
	return 0;
}


//************************P307 结构体数组
//input--输入数据，求各个平均成绩
//max--找平均成绩最高的学生
//print--输出成绩最高的学生

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student
{
	int num;
	char name[20];
	float score[3];
	float aver;
};

int main()
{
	void input(struct student stu[]);
	struct student max(struct student stu[]);
	void print(struct student stu);

	struct student stu1[3];
	struct student *p;
	p = stu1;
	input(stu1);

	print(max(stu1));
	
	return 0;
}

void input(struct student stu[])
{	
	int i;
	printf("please input the data:\n");
	for(i =0; i<3; i++)
	{
		scanf("%5d %6s %5f %5f %5f",&stu[i].num,&stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2])/3;
	}

	printf("the students is\n");
	for(i = 0; i<3; i++)
	{
		printf("No.%5d student is:",stu[i].num);
		printf("%6s %5f %5f %5f %5f",stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].aver);
		printf("\n")
	}


}


struct student max(struct student stu[])
{
	int i,index;
	index = 0;
	for(i = 0; i<3; i++)
	{
		if(stu[index].aver<stu[i].aver) index = i;
	}
	
	return stu[index];
}

void print(struct student stu)
{
	printf("the highest student is:\n");
	printf("No.%5d: %6s %5f %5f %5f %5f",stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2], stu.aver);

}


//************************P311 静态链表

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student
{
	int num;
	float score;
	struct student *next;
};

int main()
{
	struct student stu1={10101,89.5},stu2={10103,90},stu3={10105,85};
	struct student *head,*p;

	head = &stu1;
	stu1.next = &stu2;
	stu2.next = &stu3;
	stu3.next = NULL;
	
	p = head;
	for(;p!=NULL;p = p->next)
	{
		printf("%5d  %5.3f", p->num, p->score);
		printf("\n");
	}
	return 0;
}

//************************P313 动态链表

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

# define LEN sizeof(struct student)

struct student
{
	int num;
	float score;

	struct student *next;
};

struct student *creat(void)
{
	struct student *head, *p1, *p2;
	head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);

	scanf("%5d %f",&p1->num, &p1->score);

	int count = 0;
	while(p1->num != 0)
	{
		count++;
		if(count==1) head = p1;
		else p2->next = p1;

		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%5d %f",&p1->num, &p1->score);

		p2->next = NULL;
	}
	return head;
}


int main()
{
	struct student *pt;
	pt = creat();
	printf("the first mumber is:\n");
	printf("num:%5d score:%5.3f",pt->num, pt->score);

	return 0;
}


//************************P317 链表

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

# define LEN sizeof(struct student)

struct student
{
	int num;
	float score;

	struct student *next;
};

struct student *creat(void)
{
	struct student *head, *p1, *p2;
	head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);

	scanf("%5d %f",&p1->num, &p1->score);

	int count = 0;
	while(p1->num != 0)
	{
		count++;
		if(count==1) head = p1;
		else p2->next = p1;

		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%5d %f",&p1->num, &p1->score);

		p2->next = NULL;
	}
	return head;
}

void print(struct student *head)
{
	struct student *p;
	p = head;

	printf("Print the record:\n");
	if(head != NULL)
	{
		while(p != NULL)
		{
			printf("the num:%5d, the score:%5.3f",p->num, p->score);
			printf("\n");
			p = p->next;
		}
	}

}

int main()
{
	struct student *pt;
	pt = creat();
	
	print(pt);

	return 0;
}


