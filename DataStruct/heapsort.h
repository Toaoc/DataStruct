#pragma once
#ifndef _heapsort_H
#define _heapsort_H

#define NUMBERS 100					//������������
typedef struct StudentStruct {		//ѧ���ɼ��ṹ��
	int score;
	char name[40];
}*Student;
typedef struct HeapStruct {			//�����������ڵ�ṹ��
	Student student;				//������
	struct HeapStruct* parent;		//ָ���׵�ָ�룬�������Ļ���
	struct HeapStruct* lchild;		//����
	struct HeapStruct* rchild;		//�Һ���
}*HeapNode, * Heap;

typedef struct QueueStruct {
	HeapNode head;					//��������ͷ�ڵ㣬������ɾ���Ȳ���
	HeapNode tail;					//��������Ӧ����ڵ�ĸ��ڵ㣨����β�ڵ㣩����Ҫ���ڲ��룬
	int size;	
}*PriorityQueue;					//��װ�����ȶ����У��������ȶ��е�һ�֣�
typedef Student Students[NUMBERS];	

PriorityQueue Initial(void);					//��ʼ�����ȶ���
void DestroyPriorityQueue(PriorityQueue H);		//�������ȶ���
void DestroyHeap(Heap H);						//���ٶ�

void Insert(Student stu,PriorityQueue H);		//�ѵĲ���
HeapNode FindTail(PriorityQueue H);				//�ҵ�Ҫ����ڵ�ĸ��ڵ�
void Up(PriorityQueue H, HeapNode N);			//���˲�������������

Student DeleteMax(PriorityQueue H);				//����ѵ�ɾ�����ѵ�ͷ�ڵ�ΪH->head��
HeapNode FindLast(PriorityQueue H);				//�ҵ��ѵ����Ԫ�صĺ���
void Down(PriorityQueue H, HeapNode N);			//���˲�����ɾ�������

#endif //_heapsort_H