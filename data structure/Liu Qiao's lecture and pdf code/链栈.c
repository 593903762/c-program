//****************************链栈

//come from liuqiao
//必须用指针的指针用于传递
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//链栈节点
typedef struct node 
{
	int data;
	struct node *next;
}TNode, *Pstack;

//judge_empty
int isempty_stack(Pstack ps)
{
	return ps==NULL;
}

// push
void push_stack(Pstack *pps, int insert_data)
{
	Pstack pnode;
	pnode = (Pstack)malloc(sizeof(TNode));
	if(pnode)
	{
		pnode->data = insert_data;
		pnode->next = *pps;
		*pps = pnode;
	}else
		printf("push_stack failed\n");
}

void inverse_stack(Pstack *pps)
{
	Pstack pnode = *pps;//detect the node
	while(pnode!=NULL)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}
}

//clear
void clear_stack(Pstack *pps)
{
	if(!(*pps)) return;
	Pstack pfree = *pps;//use to free the node
	Pstack pnode = *pps;//ues to detect the node
	while(pnode!=NULL)
	{
		pnode = pnode->next;
		free(pfree);
		pfree = pnode;
	}
	*pps = NULL;
	return;
}

int main()
{
	//initialize
	Pstack ps = NULL;
	Pstack *pps;
	pps = &ps;
	if(isempty_stack(ps)) printf("the stack is empty\n");
	else printf("the stack is not empty\n");

	//push
	printf("input the data:\n");
	int i;
	int data;
	for(i = 0; i<4; i++)
	{
		scanf("%d", &data);
		push_stack(pps,data);
	}

	//inverse
	inverse_stack(pps);
	printf("\n");
	
	
	if(isempty_stack(ps)) printf("the stack is empty\n");
	else printf("the stack is not empty\n");
	
	//clear
	clear_stack(pps);
	if(isempty_stack(ps)) printf("the stack is empty\n");
	else printf("the stack is not empty\n");
	
	return 0;
}


//****************************链栈


//必须用指针的指针用于传递
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//链栈节点
typedef struct node 
{
	int data;
	struct node *next;
}TNode;

//链栈
typedef struct stack
{
	TNode *top;//栈顶指针
}Linkstack;


void initialize_stack(Linkstack *s)
{
	s->top = NULL;
}

int isempty_stack(Linkstack *s)
{
	if(s->top == NULL) return 1;
	else return 0;
}

void push_stack(Linkstack *s, int insert_data)
{

	TNode *node;
	node = (TNode *)malloc(sizeof(TNode));
	if(node==NULL)printf("insert the data failed");
	else{
		node->data = insert_data;
		node->next = s->top;
		s->top = node;
	}
}

void inverse_stack(Linkstack *s)
{
	TNode *node;
	node = s->top;

	while(node!=NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}


int main()
{
	//在初始化的时候，一定要为栈顶节点分配空间
	Linkstack *s;
	s = (Linkstack *)malloc(sizeof(Linkstack));	
	initialize_stack(s);

	printf("input the number:\n");
	
	int i;
	int data;
	for(i = 0; i<4; i++)
	{
		scanf("%d", &data);
		push_stack(s,data);
	}
	inverse_stack(s);


	return 0;
}


//****************************链栈


//必须用指针的指针用于传递
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//链栈节点
typedef struct node 
{
	int data;
	struct node *next;
}TNode, *Pstack;

//judge_empty
int isempty_stack(Pstack ps)
{
	return ps==NULL;
}
// push
void push_stack(Pstack *pps, int insert_data)
{
	Pstack pnode;
	pnode = (Pstack)malloc(sizeof(TNode));
	if(pnode)
	{
		pnode->data = insert_data;
		if(*pps == NULL)
		{
			pnode->next = NULL;
			*pps = pnode;
		}else{
			pnode->next = *pps;
			*pps = pnode;
		}
		
	}else
		printf("push_stack failed\n");
}

//num 为十进制数，base 为n进制
Pstack* dec2base(int num, int base)
{
	int a;
	Pstack *pps;//ps 指向栈顶的节点，是一个指针
	struct node *ps;//一定要加这两句话，不然pps刚开始会指向不明存储空间，后面打印出来是乱的 
	ps = NULL;
	pps = &ps;
	while(num!=0)
	{
		a = num%base;
		num = (num-a)/base;
		push_stack(pps, a);
	}
	return pps;
}

void inverse_stack(Pstack *pps)
{
	Pstack pnode = *pps;//detect the node
	while(pnode!=NULL)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}
}

int main()
{
	Pstack *pps;
	
	pps = dec2base(1348,8);
	inverse_stack(pps);

	return 0;
}

