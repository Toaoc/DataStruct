#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"heapsort.h"
int main(void)
{
	char name[30];
	Students stus;
	PriorityQueue H = Initial();

	printf("请依次输入姓名、成绩（输入end结束）：\n");
	int nums = 0, k;										//k为前k名，nums记录输入的组数
	while (scanf("%s", name))								//录入学生及其成绩
	{
		if (getchar() == '\n')
			break;
		stus[nums] = (Student)malloc(sizeof(struct StudentStruct));
		strcpy(stus[nums]->name, name);
		scanf("%d", &stus[nums]->score);
		Insert(stus[nums], H);
		nums++;
		if (nums == NUMBERS)
			break;
	}

	//进行名次选择
	printf("\n请输入要取得名次数量：");
	scanf("%d", &k);
	printf("\n");
	Student tem;
	printf("姓名\t成绩\t名次\n");
	for (int count=0; k != 0; k--,count++)
	{
		if (H->size == 0)
		{
			printf("\n以输出全部数据!\n");
			break;
		}
		tem = DeleteMax(H);
		printf("%s\t%d\t%d\n", tem->name, tem->score, count+1);
	}

	//销毁分配的内存
	DestroyPriorityQueue(H);
	for (int i = 0; i != nums ; i++)
		free(stus[i]);
	return 0;
}
PriorityQueue Initial(void)			//初始化堆的函数
{
	PriorityQueue H = (PriorityQueue)malloc(sizeof(struct QueueStruct));		//为堆的外壳——优先队列分配空间，同时初始化其各个变量
	H->head = NULL;
	H->size = 0;
	H->tail = H->head;
	return H;
}

void DestroyPriorityQueue(PriorityQueue H)		//销毁优先队列的程序
{
	DestroyHeap(H->head);						//先释放堆
	free(H);									//再释放优先队列
}

void DestroyHeap(Heap H)						//销毁堆的函数，递归销毁
{
	if (H == NULL)								//递归结束条件，传入的二叉树已经被完全销毁
		return;
	DestroyHeap(H->lchild);
	DestroyHeap(H->rchild);

	if (H->parent != NULL)						//销毁过程中各节点关系的处理
	{
		if (H == H->parent->lchild)
			H->parent->lchild = NULL;
		else
			H->parent->rchild = NULL;
	}
	free(H);
}


void Insert(Student stu, PriorityQueue H)			//插入的程序，同时也是创建堆的函数
{
	HeapNode tem = (HeapNode)malloc(sizeof(struct HeapStruct));			//新创建一个节点，同时初始化该节点的各个量，其父节点指针在插入完成之后再赋值
	tem->student = stu;								
	tem->lchild = tem->rchild = NULL;
	H->size++;

	if (H->tail == NULL)							//如果尾插节点为NULL,证明堆中还没有元素，故将其插入头节点后返回
	{
		H->head = tem;
		tem->parent = NULL;
		H->tail = H->head;
		return;
	}

	if (H->tail->lchild == NULL)					//堆中有元素的情况，尾插节点左孩子为空则插入左孩子，右孩子为空则插入右孩子
	{
		H->tail->lchild = tem;
	}
	else
	{
		H->tail->rchild = tem;
	}

	tem->parent = H->tail;
	Up(H,tem);										//将插入的节点上滤

	if (H->size%2==1)								//尾插节点已经被插满了，重新寻找尾插节点
	{
		H->tail = FindTail(H);
	}
}
void Up(PriorityQueue H,HeapNode N)					//上滤即是比较该节点与其父节点的大小关系，不符合堆序则交换两节点的内容，递归向上比较
{
	if (N->parent == NULL)							//递归结束条件一：上滤到头节点
	{
		H->head = N;
		return;
	}
	if (N->student->score <= N->parent->student->score)		//递归结束条件二：比较的两节点已经满足堆序关系
		return;
	
	//交换两节点的内容
	Student tem;
	tem = N->student;
	N->student = N->parent->student;
	N->parent->student = tem;
	Up(H,N->parent);
}
HeapNode FindTail(PriorityQueue H)
{
	int deepth, temLay;
	for (deepth = 0, temLay = H->size; temLay != 1; temLay = (temLay >> 1), deepth++);//计算二叉树的深度，左移一位即除以2
	HeapNode temNode = NULL;
	if (1<<(deepth+1)==H->size+1)			//判断二叉树是否已满，即加1后为2的指数倍
	{
		for (temNode = H->head; temNode->lchild != NULL; temNode = temNode->lchild);
		return temNode;
	}
	int turns;
	int LastNodes = H->size - ((1 << deepth) -1);
	turns = deepth-1;						//turns记录了最多要转的弯的数量
	temNode = H->head;
	while (turns!=0)						//turns为0即到了即到了最后一层
	{
		if (LastNodes*2<(1 << (turns+1)))	//判断当前子树最后一层的节点数量是否超过一半
		{
			temNode = temNode->lchild;		//小于一半则要插入的点在左子树，且不用重新计算子树最后一层的节点数量
		}
		else
		{
			temNode = temNode->rchild;		//大于等于一半往右子树走
			LastNodes = LastNodes - (1 << (turns));		//计算仅属于右子树的最后一层节点数，即右子树的最后一层节点数
		}
		if (temNode->lchild == NULL)		//对于左右子树深度不等的情况，如果左孩子为空了，那么就是到了尾插节点
			break;
		turns--;
	}
	return temNode;
}

Student DeleteMax(PriorityQueue H)			//堆的删除，本例中是删除最大值
{
	if (H->head == NULL)					//对于过度删除的处理
	{
		printf("\n堆为空！\n");
		exit(1);
	}
	Student max = H->head->student;
	Student ex_stu;
	HeapNode Head = H->head;
	HeapNode move_node;

	if (H->size < 3)						//对于少于3个元素的特殊情况，无须再进行下滤等操作，直接删除头节点
	{
		H->head = Head->lchild;
		H->tail = H->head;
		free(Head);
		H->size--;
		return max;
	}

	//对于普通情况的删除，找到最后一个元素，用其内容代替头节点内容，再将其下滤、释放尾节点即可
	if (H->size%2==0)						//对于有一棵二叉树的尾插节点只有一个左孩子的情况，该左孩子即是最后一个节点，提取出其即可
	{
		move_node = H->tail->lchild;
		ex_stu = Head->student;
		Head->student = move_node->student;
		move_node->student = ex_stu;
		H->tail->lchild = NULL;
	}
	else{									//尾插节点的左孩子不为最后一个节点的情况，需重新找到最后一个节点，并且重新找到尾插节点
		move_node = FindLast(H);
		ex_stu = Head->student;
		Head->student = move_node->student;
		move_node->student = ex_stu;
		move_node->parent->rchild = NULL;
	}

	//交换后的处理，大小减1、释放节点、下滤
	H->size--;
	free(move_node);
	Down(H, Head);
	return max;
}

void Down(PriorityQueue H, HeapNode N)		//交换结点内容的递归下滤操作
{
	if (N->lchild == NULL)					//左孩子为空意味着两孩子都为空，即下滤到底层了
	{
		if (H->size % 2 == 1)				//如果没有节点只拥有一个孩子，需重新找到
			H->tail = FindTail(H);
		return;
	}

	//以下是将两个孩子中的较大者提上去
	Student temStu;
	if (N->rchild == NULL)
	{
		if (N->lchild->student->score > N->student->score)
		{
			temStu = N->lchild->student;
			N->lchild->student = N->student;
			N->student = temStu;
		}
		return;
	}
	HeapNode temNode;
	if (N->lchild->student->score > N->rchild->student->score)
		temNode = N->lchild;
	else
		temNode = N->rchild;
	temStu = temNode->student;
	temNode->student = N->student;
	N->student = temStu;
	Down(H, temNode);
}

HeapNode FindLast(PriorityQueue H)
{
	int deepth, temLay;
	for (deepth = 0, temLay = H->size; temLay != 1; temLay = (temLay >> 1), deepth++);//获取二叉树深度
	HeapNode temNode = NULL;
	if (1 << (deepth + 1) == H->size + 1)			//判断二叉树是否已满
	{
		for (temNode = H->head; temNode->lchild != NULL; temNode = temNode->rchild);
		H->tail = temNode->parent;
		return temNode;
	}
	int turns;
	int LastNodes = H->size - ((1 << deepth) - 1);
	turns = deepth -1;
	temNode = H->head;
	while (1)		//该循环中一直往最底层不满的那边走
	{
		if ((1 <<( turns+1)) == 2)
			break;
		if (LastNodes  <= (1 << (turns)))
		{
			temNode = temNode->lchild;
		}
		else
		{
			temNode = temNode->rchild;
			LastNodes = LastNodes - (1 << (turns));
		}
		turns--;
	}
	H->tail = temNode;
	temNode = temNode->rchild;
	return temNode;
}



