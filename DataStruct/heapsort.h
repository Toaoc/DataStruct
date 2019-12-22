#pragma once
#ifndef _heapsort_H
#define _heapsort_H

#define NUMBERS 100					//排序的最大数量
typedef struct StudentStruct {		//学生成绩结构体
	int score;
	char name[40];
}*Student;
typedef struct HeapStruct {			//二叉树单个节点结构体
	Student student;				//数据域
	struct HeapStruct* parent;		//指向父亲的指针，方便插入的回溯
	struct HeapStruct* lchild;		//左孩子
	struct HeapStruct* rchild;		//右孩子
}*HeapNode, * Heap;

typedef struct QueueStruct {
	HeapNode head;					//二叉树的头节点，可用于删除等操作
	HeapNode tail;					//二叉树的应插入节点的父节点（不是尾节点），主要用于插入，
	int size;	
}*PriorityQueue;					//包装在优先队列中（堆是优先队列的一种）
typedef Student Students[NUMBERS];	

PriorityQueue Initial(void);					//初始化优先队列
void DestroyPriorityQueue(PriorityQueue H);		//销毁优先队列
void DestroyHeap(Heap H);						//销毁堆

void Insert(Student stu,PriorityQueue H);		//堆的插入
HeapNode FindTail(PriorityQueue H);				//找到要插入节点的父节点
void Up(PriorityQueue H, HeapNode N);			//上滤操作，插入后进行

Student DeleteMax(PriorityQueue H);				//大根堆的删除（堆的头节点为H->head）
HeapNode FindLast(PriorityQueue H);				//找到堆的最后元素的函数
void Down(PriorityQueue H, HeapNode N);			//下滤操作，删除后进行

#endif //_heapsort_H