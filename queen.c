//#include<stdio.h>
//#include<stdlib.h>
//#define QueenNumbers 8						//����ʺ����������8�ʺ�����
//typedef struct QStack {
//	int  y;
//	struct QStack* next;
//}* Node;									//ջ�е���ͨ�ڵ㣬y����������				
//
//
//typedef struct HeadNode {			
//	int size;
//	Node next;
//}*Head,*Stack;								//ջ�е�ͷ�ڵ㣬����һ����ͷ����ջ
//
//typedef Stack QRowStack[QueenNumbers];		//����һ��ջ��������
//
//static int total = 0;						//ͳ������Ľ�ĸ����ı���
//
////һЩջ��صĺ���
//Stack CreateStack(void);					//��ʼ��ջ�ĺ���
//void Push(Stack S,int y);				//��ջ����
//void Pop(Stack S);							//��ջ����
//Node TopOfStack(Stack S);					//����ջ��Ԫ�صĺ���
//void MakeEmpty(Stack S);					//���ջ�ĺ���
//void Destroy(Stack S);						//����ջ�ĺ���
//
//int FindPositions(int queue[], int row, QRowStack RowStack);				//Ѱ�ҵ�ǰ�����п��Բ����λ��
//void Search_Queens(Stack answer, QRowStack RowStack);						//���в��һʺ�λ�õ���Ҫ����
//void print_answer(int queen[]);												//��ӡ����ĺ���
//	
//int main(void)
//{
//	Stack answer = CreateStack();
//	QRowStack RowStack;						//��ջ��������ÿһ�п��õ�λ��
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
//	int queen[QueenNumbers];						//������¼ÿ�лʺ�λ�õ����飬����ȷֵΪ0-7
//	int i ;
//	for (i = 0; i < QueenNumbers; i++)				//���ʺ�����ȫ����ʼ��Ϊ-1����-1�ǲ����ܵ�ȡֵ
//		queen[i] = -1;
//	for (i = 0; i>-1&&i < QueenNumbers; )
//	{
//		if (queen[i]==-1)											//��ֵΪ-1�����������δ����Ѱ
//		{
//			if (!FindPositions(queen, i, RowStack))					//δ�ҵ����Է��õ�λ�ã�����л���
//			{
//				Pop(answer);										//�����³�һ��
//				i--;												//�ص���һ��
//				continue;											//�������ж����
//			}
//		}
//		if(TopOfStack(RowStack[i])!=NULL)							//�ò�������ǽ�����λ����ȡ��������һ�У����򣬼���λ�ÿ���ȡ������
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
//		if (answer->size == QueenNumbers)							//����ջ���Ԫ�������ﵽ8�������ҵ���8���ʺ󣬻��ݣ����µ�8��			
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
//	int i, not[QueenNumbers] = { 0 };					//not����Ϊ0����ɴ�ŵ�λ�ã�Ϊ1�����ɴ�ŵ�λ��
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
//	for (i = 0; i < QueenNumbers; i++)					//���ɴ�ŵ�λ����ջ
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
