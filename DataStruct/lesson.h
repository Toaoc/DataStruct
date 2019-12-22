#pragma once
#ifndef _lesson_H
#define _lesson_H
#define TOTAL_LESSONS 50
typedef struct AocAdvanceNode {	//每个顶点的链表,
	char advance_lesson[40];		//先行课程名称
	struct AocAdvanceNode* next;	//指向下一个关联顶点，即先行课程
}* AdvanceNode;
enum NodeStatus{Empty,Filled,Deleted,Visited};

typedef struct NodeList {	//总链表
	float value;				//权值
	int hours;				//学时
	int front_numbers;
	char lesson_name[40];		//代表一门课程
	enum NodeStatus status;
	AdvanceNode next;				//使其链接成一个子链表
}* AdjList[TOTAL_LESSONS],* GraphNode;	

typedef struct AocGraph {
	AdjList lessons;		//一个多门课的数组
	int vexnum, arcnum;		//存储已存边数和节点数
}*Graph;

typedef struct AocStack {
	GraphNode Vertex;
	struct AocStack* next;
}*Stack,*StackNode;				//栈要带头节点，用于深度优先搜索

typedef struct AocQueueNode {
	GraphNode Vertex;
	struct AocQueueNode* next;
}*QueueNode;
typedef struct AocQueue {
	QueueNode head;		
	QueueNode tail;
}*Queue;						//队列主要用于拓扑排序储存，因为拓扑排序课程先进先出比较好

int hash(char* str,Graph G);
int FindPosition(char* str,Graph G);

Graph InitGraph();
void Dfs(Graph G, GraphNode lesson, Stack DfsStack, Queue SortedQueue);			//深度优先搜索函数
void topological_sort(Graph G);	//拓扑排序函数，可在该函数中输出答案
void print_answer(Queue Q);		//打印拓扑排序结果
void print_semester(int semester);
void destroy_graph(Graph G);	//销毁图的函数

//栈相关的函数
Stack InitStack();		//有返回值，要使用赋值来初始化，即S=InitStack();
void Push(GraphNode G, Stack S);
GraphNode TopOfStack(Stack S);
void Pop(Stack S);
void MakeEmptyStack(Stack S);
void destroy_stack(Stack S);

//队列相关的函数
Queue InitQueue();		//有返回值，要使用赋值来初始化，即Q=InitQueue();
void EnQueue(GraphNode G, Queue Q);
void DeQueue(Queue Q);
GraphNode Front_Queue(Queue Q);
int NotEmptyQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void destroy_queue(Queue Q);
#endif //_lesson_H