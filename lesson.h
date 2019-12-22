#pragma once
#ifndef _lesson_H
#define _lesson_H
#define TOTAL_LESSONS 50
typedef struct AocAdvanceNode {	//ÿ�����������,
	char advance_lesson[40];		//���пγ�����
	struct AocAdvanceNode* next;	//ָ����һ���������㣬�����пγ�
}* AdvanceNode;
enum NodeStatus{Empty,Filled,Deleted,Visited};

typedef struct NodeList {	//������
	float value;				//Ȩֵ
	int hours;				//ѧʱ
	int front_numbers;
	char lesson_name[40];		//����һ�ſγ�
	enum NodeStatus status;
	AdvanceNode next;				//ʹ�����ӳ�һ��������
}* AdjList[TOTAL_LESSONS],* GraphNode;	

typedef struct AocGraph {
	AdjList lessons;		//һ�����ſε�����
	int vexnum, arcnum;		//�洢�Ѵ�����ͽڵ���
}*Graph;

typedef struct AocStack {
	GraphNode Vertex;
	struct AocStack* next;
}*Stack,*StackNode;				//ջҪ��ͷ�ڵ㣬���������������

typedef struct AocQueueNode {
	GraphNode Vertex;
	struct AocQueueNode* next;
}*QueueNode;
typedef struct AocQueue {
	QueueNode head;		
	QueueNode tail;
}*Queue;						//������Ҫ�����������򴢴棬��Ϊ��������γ��Ƚ��ȳ��ȽϺ�

int hash(char* str,Graph G);
int FindPosition(char* str,Graph G);

Graph InitGraph();
void Dfs(Graph G, GraphNode lesson, Stack DfsStack, Queue SortedQueue);			//���������������
void topological_sort(Graph G);	//���������������ڸú����������
void print_answer(Queue Q);		//��ӡ����������
void print_semester(int semester);
void destroy_graph(Graph G);	//����ͼ�ĺ���

//ջ��صĺ���
Stack InitStack();		//�з���ֵ��Ҫʹ�ø�ֵ����ʼ������S=InitStack();
void Push(GraphNode G, Stack S);
GraphNode TopOfStack(Stack S);
void Pop(Stack S);
void MakeEmptyStack(Stack S);
void destroy_stack(Stack S);

//������صĺ���
Queue InitQueue();		//�з���ֵ��Ҫʹ�ø�ֵ����ʼ������Q=InitQueue();
void EnQueue(GraphNode G, Queue Q);
void DeQueue(Queue Q);
GraphNode Front_Queue(Queue Q);
int NotEmptyQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void destroy_queue(Queue Q);
#endif //_lesson_H