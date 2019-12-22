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

	printf("�����������������ɼ�������end��������\n");
	int nums = 0, k;										//kΪǰk����nums��¼���������
	while (scanf("%s", name))								//¼��ѧ������ɼ�
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

	//��������ѡ��
	printf("\n������Ҫȡ������������");
	scanf("%d", &k);
	printf("\n");
	Student tem;
	printf("����\t�ɼ�\t����\n");
	for (int count=0; k != 0; k--,count++)
	{
		if (H->size == 0)
		{
			printf("\n�����ȫ������!\n");
			break;
		}
		tem = DeleteMax(H);
		printf("%s\t%d\t%d\n", tem->name, tem->score, count+1);
	}

	//���ٷ�����ڴ�
	DestroyPriorityQueue(H);
	for (int i = 0; i != nums ; i++)
		free(stus[i]);
	return 0;
}
PriorityQueue Initial(void)			//��ʼ���ѵĺ���
{
	PriorityQueue H = (PriorityQueue)malloc(sizeof(struct QueueStruct));		//Ϊ�ѵ���ǡ������ȶ��з���ռ䣬ͬʱ��ʼ�����������
	H->head = NULL;
	H->size = 0;
	H->tail = H->head;
	return H;
}

void DestroyPriorityQueue(PriorityQueue H)		//�������ȶ��еĳ���
{
	DestroyHeap(H->head);						//���ͷŶ�
	free(H);									//���ͷ����ȶ���
}

void DestroyHeap(Heap H)						//���ٶѵĺ������ݹ�����
{
	if (H == NULL)								//�ݹ��������������Ķ������Ѿ�����ȫ����
		return;
	DestroyHeap(H->lchild);
	DestroyHeap(H->rchild);

	if (H->parent != NULL)						//���ٹ����и��ڵ��ϵ�Ĵ���
	{
		if (H == H->parent->lchild)
			H->parent->lchild = NULL;
		else
			H->parent->rchild = NULL;
	}
	free(H);
}


void Insert(Student stu, PriorityQueue H)			//����ĳ���ͬʱҲ�Ǵ����ѵĺ���
{
	HeapNode tem = (HeapNode)malloc(sizeof(struct HeapStruct));			//�´���һ���ڵ㣬ͬʱ��ʼ���ýڵ�ĸ��������丸�ڵ�ָ���ڲ������֮���ٸ�ֵ
	tem->student = stu;								
	tem->lchild = tem->rchild = NULL;
	H->size++;

	if (H->tail == NULL)							//���β��ڵ�ΪNULL,֤�����л�û��Ԫ�أ��ʽ������ͷ�ڵ�󷵻�
	{
		H->head = tem;
		tem->parent = NULL;
		H->tail = H->head;
		return;
	}

	if (H->tail->lchild == NULL)					//������Ԫ�ص������β��ڵ�����Ϊ����������ӣ��Һ���Ϊ��������Һ���
	{
		H->tail->lchild = tem;
	}
	else
	{
		H->tail->rchild = tem;
	}

	tem->parent = H->tail;
	Up(H,tem);										//������Ľڵ�����

	if (H->size%2==1)								//β��ڵ��Ѿ��������ˣ�����Ѱ��β��ڵ�
	{
		H->tail = FindTail(H);
	}
}
void Up(PriorityQueue H,HeapNode N)					//���˼��ǱȽϸýڵ����丸�ڵ�Ĵ�С��ϵ�������϶����򽻻����ڵ�����ݣ��ݹ����ϱȽ�
{
	if (N->parent == NULL)							//�ݹ��������һ�����˵�ͷ�ڵ�
	{
		H->head = N;
		return;
	}
	if (N->student->score <= N->parent->student->score)		//�ݹ�������������Ƚϵ����ڵ��Ѿ���������ϵ
		return;
	
	//�������ڵ������
	Student tem;
	tem = N->student;
	N->student = N->parent->student;
	N->parent->student = tem;
	Up(H,N->parent);
}
HeapNode FindTail(PriorityQueue H)
{
	int deepth, temLay;
	for (deepth = 0, temLay = H->size; temLay != 1; temLay = (temLay >> 1), deepth++);//�������������ȣ�����һλ������2
	HeapNode temNode = NULL;
	if (1<<(deepth+1)==H->size+1)			//�ж϶������Ƿ�����������1��Ϊ2��ָ����
	{
		for (temNode = H->head; temNode->lchild != NULL; temNode = temNode->lchild);
		return temNode;
	}
	int turns;
	int LastNodes = H->size - ((1 << deepth) -1);
	turns = deepth-1;						//turns��¼�����Ҫת���������
	temNode = H->head;
	while (turns!=0)						//turnsΪ0�����˼��������һ��
	{
		if (LastNodes*2<(1 << (turns+1)))	//�жϵ�ǰ�������һ��Ľڵ������Ƿ񳬹�һ��
		{
			temNode = temNode->lchild;		//С��һ����Ҫ����ĵ������������Ҳ������¼����������һ��Ľڵ�����
		}
		else
		{
			temNode = temNode->rchild;		//���ڵ���һ������������
			LastNodes = LastNodes - (1 << (turns));		//��������������������һ��ڵ������������������һ��ڵ���
		}
		if (temNode->lchild == NULL)		//��������������Ȳ��ȵ�������������Ϊ���ˣ���ô���ǵ���β��ڵ�
			break;
		turns--;
	}
	return temNode;
}

Student DeleteMax(PriorityQueue H)			//�ѵ�ɾ������������ɾ�����ֵ
{
	if (H->head == NULL)					//���ڹ���ɾ���Ĵ���
	{
		printf("\n��Ϊ�գ�\n");
		exit(1);
	}
	Student max = H->head->student;
	Student ex_stu;
	HeapNode Head = H->head;
	HeapNode move_node;

	if (H->size < 3)						//��������3��Ԫ�ص���������������ٽ������˵Ȳ�����ֱ��ɾ��ͷ�ڵ�
	{
		H->head = Head->lchild;
		H->tail = H->head;
		free(Head);
		H->size--;
		return max;
	}

	//������ͨ�����ɾ�����ҵ����һ��Ԫ�أ��������ݴ���ͷ�ڵ����ݣ��ٽ������ˡ��ͷ�β�ڵ㼴��
	if (H->size%2==0)						//������һ�ö�������β��ڵ�ֻ��һ�����ӵ�����������Ӽ������һ���ڵ㣬��ȡ���伴��
	{
		move_node = H->tail->lchild;
		ex_stu = Head->student;
		Head->student = move_node->student;
		move_node->student = ex_stu;
		H->tail->lchild = NULL;
	}
	else{									//β��ڵ�����Ӳ�Ϊ���һ���ڵ��������������ҵ����һ���ڵ㣬���������ҵ�β��ڵ�
		move_node = FindLast(H);
		ex_stu = Head->student;
		Head->student = move_node->student;
		move_node->student = ex_stu;
		move_node->parent->rchild = NULL;
	}

	//������Ĵ�����С��1���ͷŽڵ㡢����
	H->size--;
	free(move_node);
	Down(H, Head);
	return max;
}

void Down(PriorityQueue H, HeapNode N)		//����������ݵĵݹ����˲���
{
	if (N->lchild == NULL)					//����Ϊ����ζ�������Ӷ�Ϊ�գ������˵��ײ���
	{
		if (H->size % 2 == 1)				//���û�нڵ�ֻӵ��һ�����ӣ��������ҵ�
			H->tail = FindTail(H);
		return;
	}

	//�����ǽ����������еĽϴ�������ȥ
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
	for (deepth = 0, temLay = H->size; temLay != 1; temLay = (temLay >> 1), deepth++);//��ȡ���������
	HeapNode temNode = NULL;
	if (1 << (deepth + 1) == H->size + 1)			//�ж϶������Ƿ�����
	{
		for (temNode = H->head; temNode->lchild != NULL; temNode = temNode->rchild);
		H->tail = temNode->parent;
		return temNode;
	}
	int turns;
	int LastNodes = H->size - ((1 << deepth) - 1);
	turns = deepth -1;
	temNode = H->head;
	while (1)		//��ѭ����һֱ����ײ㲻�����Ǳ���
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



