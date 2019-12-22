//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<math.h>
//#include "lesson.h"
//int main(void)
//{
//	Graph G = InitGraph();
//	topological_sort(G);
//	destroy_graph(G);
//	return 0;
//	
//}
//
//Graph InitGraph()
//{
//	Graph G = (Graph)malloc(sizeof(struct AocGraph));
//	G->arcnum = 0;
//	G->vexnum = 0;
//	for (int i = 0; i < TOTAL_LESSONS; i++)
//	{
//		G->lessons[i] = (GraphNode)malloc(sizeof(struct NodeList));
//		G->lessons[i]->status = Empty;
//	}
//	int  hours, front_numbers;
//	float value;
//	char advance[40];
//	printf("请输入课程、学分、学时、先行课门数、先行课名称（若有）（空格隔开，输入一个end结束）：\n");
//	while (scanf("%s", advance))		//EOF不知道用来判断是否可行
//	{
//		if (getchar() == '\n')
//			break;
//		scanf("%f%d%d", &value, &hours, &front_numbers);
//		if (value == -1)
//			break;
//		G->vexnum++;
//		G->arcnum += front_numbers;
//
//		//printf("\n长度%d\n", sizeof(advance));
//
//		int position = hash(advance ,G);
//		G->lessons[position] = (GraphNode)malloc(sizeof(struct NodeList));
//		strcpy(G->lessons[position]->lesson_name, advance);
//		G->lessons[position]->hours = hours;
//		G->lessons[position]->value = value;
//		G->lessons[position]->front_numbers = front_numbers;
//		G->lessons[position]->next = NULL;
//		G->lessons[position]->status = Filled;
//
//		int j;
//		for (j = 0; j < front_numbers; j++)
//		{
//			scanf("%s", advance);
//			AdvanceNode tem = (AdvanceNode)malloc(sizeof(struct AocAdvanceNode));
//			strcpy(tem->advance_lesson, advance);
//			tem->next = G->lessons[position]->next;
//			G->lessons[position]->next = tem;
//		}
//	}
//	return G;
//}
//
//void destroy_graph(Graph G)
//{
//	int i;
//	for (i = 0; i < TOTAL_LESSONS;i++)
//	{
//		if (G->lessons[i]->status == Empty)
//		{
//			free(G->lessons[i]);
//			continue;
//		}
//		while (G->lessons[i]->next != NULL)
//		{
//			AdvanceNode tem = G->lessons[i]->next;
//			G->lessons[i]->next = tem->next;
//			free(tem);
//		}
//		free(G->lessons[i]);
//	}
//	free(G);
//}
//
//void topological_sort(Graph G)
//{
//	int i, j, k;			//临时性计数变量
//	Queue SortedQueue = InitQueue();
//	Stack DfsStack = InitStack();
//	for (i = j = 0; i < TOTAL_LESSONS&&j<G->vexnum; i++)
//	{
//		if (G->lessons[i]->status != Empty)
//		{
//			j++;
//			if (G->lessons[i]->status != Visited)
//				Dfs(G, G->lessons[i], DfsStack,SortedQueue);
//		}
//	}
//	print_answer(SortedQueue);
//	destroy_queue(SortedQueue);
//	destroy_stack(DfsStack);
//	
//}
//
//void Dfs(Graph G,GraphNode lesson, Stack DfsStack,Queue SortedQueue)
//{
//	int i, j;
//	if (lesson->front_numbers == 0)
//	{
//		Push(lesson, DfsStack);
//		EnQueue(lesson, SortedQueue);
//		lesson->status = Visited;
//		return;
//	}
//	else
//	{
//		int position;
//		AdvanceNode tem;
//		for (tem = lesson->next; tem != NULL; tem = tem->next)
//		{
//			lesson->front_numbers--;
//			position = FindPosition(lesson->next->advance_lesson, G);
//			if (G->lessons[position]->status == Visited)
//				continue;
//			Dfs(G,G->lessons[position], DfsStack,SortedQueue);
//		}
//		Push(lesson, DfsStack);
//		EnQueue(lesson, SortedQueue);
//		lesson->status = Visited;
//	}
//}
//
//void print_answer(Queue Q)
//{
//	int  semester_time, semester_lesson,  total_time, total_lesson;
//	float semester_value, total_value;
//	float per_value;
//	int per_lesson;
//	printf("\n请输入每学期授课学分上限：");
//	scanf("%f", &per_value);
//	printf("\n请输入每学期授课门数上限：");
//	scanf("%d", &per_lesson);
//	semester_lesson = semester_value = semester_time = 0;
//	total_time = total_value = total_lesson = 0;
//	int  semester = 1,pre_semester=1;
//
//	printf("\n第%d学期授课计划：\n", semester);
//	printf("\t\t  课程名称\t\t学分 \t\t学时\n");
//	while (NotEmptyQueue(Q))
//	{
//		GraphNode TemLesson = Front_Queue(Q);
//		total_lesson++;
//		total_time += TemLesson->hours;
//		total_value += TemLesson->value;
//		if (total_lesson > per_lesson* semester || total_value > per_value* semester)
//		{
//			printf("第%d学期授课门数：%d，总学分：%.2f，总学时：%d\n\n", semester, semester_lesson,semester_value, semester_time);
//
//			semester++;
//			semester_lesson = semester_value = semester_time = 0;
//			printf("第%d学期授课计划：\n", semester);
//			printf("\t\t  课程名称\t\t学分 \t\t学时\n");
//		}
//		semester_lesson++;
//		semester_value += TemLesson->value;
//		semester_time += TemLesson->hours;
//		printf("%30s\t\t%.2f\t\t%d\n", TemLesson->lesson_name, TemLesson->value, TemLesson->hours);
//		DeQueue(Q);
//
//	}
//
//	printf("第%d学期授课门数：%d，总学分：%.2f，总学时：%d\n\n", semester, semester_lesson, semester_value, semester_time);
//	printf("大学总授课门数：%d，总学分：%.2f，总学时：%d\n", total_lesson, total_value, total_time);
//}
//
//
//int hash(char* str,Graph G)
//{
//	int position, i;
//	for (position = 0, i = 0; str[i] != '\0'; i++)
//	{
//		position += abs(str[i]);
//	}
//	position = position % TOTAL_LESSONS;
//	if (G->lessons[position]->status == Empty)
//	{
//		//printf("%s1\t%d\n", str, position);
//		return position;
//	}
//	else
//	{
//		for(i=1;G->lessons[position]->status != Empty&&i<TOTAL_LESSONS;i++)
//		{
//			position = position + i * 2 - 1;
//			position = position % TOTAL_LESSONS;
//		}
//		if (i == TOTAL_LESSONS)
//		{
//			printf("空间不足！\n");
//			exit(-1);
//		}
//		//printf("%s2\t%d\n", str, position);
//		return position;
//	}
//	
//}
//int FindPosition(char *str,Graph G)
//{
//	int position , i;
//	for (position = i = 0; str[i] != '\0'; i++)
//		position += abs(str[i]);
//	position = position % TOTAL_LESSONS;
//	if (strcmp(G->lessons[position]->lesson_name, str) == 0)
//		return position;
//	else
//	{
//		for (i = 1; strcmp(G->lessons[position]->lesson_name, str) != 0 && i < TOTAL_LESSONS; i++)
//		{
//			position = position + i * 2 - 1;
//			position = position % TOTAL_LESSONS;
//		}
//		if (i == TOTAL_LESSONS)
//		{
//			//printf("%s\t%d\n", str, position);
//			printf("%s课程信息不完整\n", str);
//			exit(1);
//		}
//		return position;
//	}
//}
//
//Stack InitStack()
//{
//	Stack S = (Stack)malloc(sizeof(struct AocStack));
//	S->next = NULL;
//	return S;
//}
//void Push(GraphNode G, Stack S)
//{
//	StackNode tem;
//	tem = (StackNode)malloc(sizeof(struct AocStack));
//	tem->Vertex = G;
//	tem->next = S->next;
//	S->next = tem->next;
//}
//void Pop(Stack S)
//{
//	if (S->next != NULL)
//	{
//		StackNode tem;
//		tem = S->next;
//		S->next = tem->next;
//		free(tem);				
//	}
//}
//GraphNode TopOfStack(Stack S)
//{
//	return S->next->Vertex;
//}
//void MakeEmptyStack(Stack S)
//{
//	while (S->next != NULL)
//		Pop(S);
//}
//void destroy_stack(Stack S)
//{
//	MakeEmptyStack(S);
//	free(S);
//}
//
//Queue InitQueue()
//{
//	Queue Q = (Queue)malloc(sizeof(struct AocQueue));
//	Q->head = (QueueNode)malloc(sizeof(struct AocQueueNode));		//队列带头节点
//	Q->tail = Q->head;
//	Q->tail->next = NULL;
//	return Q;
//}
//void EnQueue(GraphNode G, Queue Q)
//{
//	QueueNode tem = (QueueNode)malloc(sizeof(struct AocQueueNode));
//	tem->Vertex = G;
//	tem->next = NULL;
//	Q->tail->next = tem;
//	Q->tail = Q->tail->next;
//}
//void DeQueue(Queue Q)
//{
//	if (Q->head->next != NULL)
//	{
//		QueueNode tem = Q->head->next;
//		Q->head->next = tem->next;
//		free(tem);
//	}
//	if (Q->tail == NULL)//如果尾节点被删除，将尾节点指向头节点
//	{
//		Q->tail = Q->head;
//	}
//}
//GraphNode Front_Queue(Queue Q)
//{
//	return Q->head->next->Vertex;
//}
//void MakeEmptyQueue(Queue Q)
//{
//	Q->tail = Q->head;
//	while (Q->head->next != NULL)
//		DeQueue(Q);
//}
//int NotEmptyQueue(Queue Q)
//{
//	return	Q->head->next;
//}
//void destroy_queue(Queue Q)
//{
//	MakeEmptyQueue(Q);
//	free(Q->head);
//	free(Q);
//}