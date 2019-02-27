//************************P9 冒泡排序
//有n个数需要进行排序

//每一次选出一个最大（小）的数，第二次就不计入排序名单
//理论上需要进行n-1趟排序


#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	
	int a[100];
	int num,i,j,temp;
	printf("please enter the number you want to input: ");
	scanf("%d", &num);

	printf("please enter the list you want to input: ");
	for(i = 0; i<num; i++)
	{
		scanf("%d",&a[i]);
	}


//冒泡排序核心代码
//冒泡排序,有num个数，要进行num-1次排序
	for(i = 0;i<num-1; i++)
	{
		for(j=0; j<=num-1-i; j++)
		{
			if(a[j]<a[j+1]){temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;}
		}
	}

	for(i = 0; i<num; i++)
	{
		printf("%5d",a[i]);
	}

	return 0;
}



//************************P9 冒泡排序结合结构体


#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct student
{
	char name[20];
	float score;

};


int main()
{
	
	struct student stu[100],temp;
	int num,i,j;
	printf("please enter the number of student you want to input: ");
	scanf("%d", &num);

	printf("please enter the list of the student you want to input: \n");
	for(i = 0; i<num; i++)
	{
		scanf("%s %f",stu[i].name, &stu[i].score);
	}

//冒泡排序,有num个数，要进行num-1次排序
	for(i = 0;i<num-1; i++)
	{
		for(j=0; j<=num-1-i; j++)
		{
			if(stu[j].score < stu[j+1].score){temp = stu[j]; stu[j] = stu[j+1]; stu[j+1] = temp;}
		}
	}

	printf("print the list after sorting:\n");
	for(i = 0; i<num; i++)
	{
		printf("%-10s: %5f",stu[i].name, stu[i].score);
		printf("\n");
	}

	return 0;
}
