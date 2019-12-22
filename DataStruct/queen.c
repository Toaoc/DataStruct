//#include<stdio.h>
//#include<stdlib.h>
//#define QueenNumbers 8						//代表皇后的数量，即8皇后问题
//typedef struct QStack {
//	int  y;
//	struct QStack* next;
//}* Node;									//栈中的普通节点，y代表纵坐标				
//
//
//typedef struct HeadNode {			
//	int size;
//	Node next;
//}*Head,*Stack;								//栈中的头节点，这是一个带头结点的栈
//
//typedef Stack QRowStack[QueenNumbers];		//定义一个栈数组类型
//
//static int total = 0;						//统计问题的解的个数的变量
//
////一些栈相关的函数
//Stack CreateStack(void);					//初始化栈的函数
//void Push(Stack S,int y);				//入栈函数
//void Pop(Stack S);							//出栈函数
//Node TopOfStack(Stack S);					//返回栈顶元素的函数
//void MakeEmpty(Stack S);					//清空栈的函数
//void Destroy(Stack S);						//销毁栈的函数
//
//int FindPositions(int queue[], int row, QRowStack RowStack);				//寻找当前行所有可以插入的位置
//void Search_Queens(Stack answer, QRowStack RowStack);						//进行查找皇后位置的主要函数
//void print_answer(int queen[]);												//打印结果的函数
//	
//int main(void)
//{
//	Stack answer = CreateStack();
//	QRowStack RowStack;						//该栈数组存的是每一行可用的位置
//
//	for (int i = 0; i < QueenNumbers; i++)
//		RowStack[i]=CreateStack();
//
//	Search_Queens(answer,RowStack);
//
//	Destroy(answer);
//	for (int i = 0; i < QueenNumbers; i++)
//		Destroy(RowStack[i]);
//	printf("total: %d\n", total);
//	return 0;
//}
//
//void Search_Queens(Stack answer,QRowStack RowStack)
//{
//	int queen[QueenNumbers];						//用来记录每行皇后位置的数组，其正确值为0-7
//	int i ;
//	for (i = 0; i < QueenNumbers; i++)				//将皇后数组全部初始化为-1，因-1是不可能的取值
//		queen[i] = -1;
//	for (i = 0; i>-1&&i < QueenNumbers; )
//	{
//		if (queen[i]==-1)											//该值为-1，即代表改行未被搜寻
//		{
//			if (!FindPositions(queen, i, RowStack))					//未找到可以放置的位置，则进行回溯
//			{
//				Pop(answer);										//将答案吐出一个
//				i--;												//回到上一行
//				continue;											//不下面判断语句
//			}
//		}
//		if(TopOfStack(RowStack[i])!=NULL)							//该部分语句是将可用位置提取，进入下一行，否则，既无位置可提取，回溯
//		{
//			Push(answer, i, TopOfStack(RowStack[i])->y);
//			queen[i] = TopOfStack(RowStack[i])->y;
//			Pop(RowStack[i]);
//			i++;
//		}
//		else
//		{
//			queen[i] = -1;
//			Pop(answer);
//			i--;
//		}
//		if (answer->size == QueenNumbers)							//若答案栈里的元素数量达到8个，即找到了8个皇后，回溯，找新的8个			
//		{
//			print_answer(queen);
//			Pop(answer);
//			if(i < QueenNumbers)
//				MakeEmpty(RowStack[i]);
//			i--;
//		}
//	}
//}
//
//int FindPositions(int queen[], int row, QRowStack RowStack)
//{
//	int i, not[QueenNumbers] = { 0 };					//not数组为0代表可存放的位置，为1代表不可存放的位置
//	for (i = 0; i < row; i++)
//	{
//		if (queen[i] == -1)
//			continue;
//		not[queen[i]] = 1;
//		if (queen[i] + (row - i) < QueenNumbers)
//			not[queen[i] + (row - i)] = 1;
//		if (queen[i] - (row - i) > -1)
//			not[queen[i] - (row - i)] = 1;
//	}
//	for (i = 0; i < QueenNumbers; i++)					//将可存放的位置入栈
//	{
//		if (not[i] == 0)
//			Push(RowStack[row], row, i);
//	}
//	return RowStack[row]->size;
//}
//
//void print_answer(int queen[])
//{
//	int i;
//	for (i = 0; i < QueenNumbers; i++)
//	{
//		printf("(%d , %d)\t", i, queen[i]);
//	}
//	printf("\n");
//	total++;
//}
//Stack CreateStack(void)
//{
//	Stack S;
//	S = (Head)malloc(sizeof(struct HeadNode));
//	S->size = 0;
//	S->next = NULL;
//	return S;
//}
//void Push(Stack S,int x,int y)
//{
//	Node NewNode;
//	NewNode =(struct QStack*)malloc(sizeof(struct QStack));
//	NewNode->y = y;
//	NewNode->next = S->next;
//	S->next = NewNode;
//	S->size++;
//}
//void Pop(Stack S)
//{
//	if (S->next == NULL)
//		return;
//	Node tem;
//	tem = S->next;
//	S->next = S->next->next;
//	free(tem);
//	S->size--;
//}
//Node TopOfStack(Stack S)
//{
//	return S->next;
//}
//void MakeEmpty(Stack S)
//{
//	while (S->next != NULL)
//		free(S->next);
//}
//void Destroy(Stack S)
//{
//	MakeEmpty(S);
//	free(S);
//}
//
