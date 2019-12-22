//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<string>
//using namespace std;
//
//class progress {
//private:
//	int key;
//	string name;
//public:
//	progress(int key, string name)
//	{
//		this->key = key;
//		this->name = name;
//	}
//	progress(){}
//	int get_key()
//	{
//		return key;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	void set_key(int key)
//	{
//		this->key = key;
//	}
//	bool operator> (progress& P)
//	{
//		if (this->key > P.key)
//			return true;
//		else
//			return false;
//	}
//	bool operator< (progress & P)
//	{
//		if (this->key < P.key)
//			return true;
//		else
//			return false;
//	}
//};
//
//class PriorityQueue {
//private:
//	vector<progress> heap;
//public:
//	PriorityQueue() 
//	{
//		Init();
//	}
//	void Init()
//	{
//		progress tem = progress(-1, "null");
//		heap.push_back(tem);
//	}
//	progress Top();
//	progress DeleteMin();
//	void insert(progress a);
//	void clear();
//	void adjustKey();
//	void IncreaseKey(int i);
//	void DecreaseKey(int i);
//	void PrintResult();
//};
//
//
//int main()
//{
//	string name;
//	int key;
//	PriorityQueue P;
//
//	cout << "请输入所要运行的程序名及其资源数(end结束输入)：" << endl;
//	while (cin >> name)
//	{
//		if (name == "end")
//			break;
//		cin >> key;
//		P.insert(progress(key, name));
//	}
//
//	P.adjustKey();
//	P.adjustKey();
//	P.PrintResult();
//	return 0;
//}
//
//
//
//
//void PriorityQueue::insert(progress a)
//{
//	heap.push_back(a);
//	if (heap.size() == 1)
//	{
//		return;
//	}
//
//	int i;
//	progress tem;
//	for (i = heap.size()-1; heap[i] < heap[i / 2];)
//	{
//		tem = heap[i];
//		heap[i] = heap[i / 2];
//		heap[i / 2] = tem;
//	}
//}
//progress PriorityQueue::Top()
//{
//	return heap[1];
//}
//progress PriorityQueue::DeleteMin()
//{
//	
//	progress MinProg, temProg;
//	MinProg = heap[1];
//	temProg = heap[heap.size() - 1];
//	heap[heap.size() - 1] = heap[1];
//	heap[1] = temProg;
//	heap.pop_back();
//
//	int i, child;
//	for (i = 1; 2 * i <= heap.size() - 1; i *= 2)
//	{
//		child = i * 2;
//		if (child+1 != heap.size() && heap[child + 1] < heap[child])
//			child++;
//		if (heap[i] > heap[child])
//		{
//			temProg = heap[child];
//			heap[child] = heap[i];
//			heap[i] = temProg;
//		}
//		else
//			break;
//	}
//	return MinProg;
//}
//void PriorityQueue::adjustKey()
//{
//	string Proname;
//	int position, newKey;
//	cout << "\n请输入要调整的程序名：" << flush;
//	cin >> Proname;
//	for (position = 1; position != heap.size(); position++)
//	{
//		if (heap[position].get_name() == Proname)
//			break;
//	}
//	if (position == heap.size())
//	{
//		cout << "无此程序！" << endl;
//		return;
//	}
//	cout << "程序的旧资源数为:" << heap[position].get_key() << endl;
//	cout << "请输入新的资源数:" << flush;
//	cin >> newKey;
//	if (newKey > heap[position].get_key())
//	{
//		heap[position].set_key(newKey);
//		IncreaseKey(position);
//	}
//	else if (newKey < heap[position].get_key())
//	{
//		heap[position].set_key(newKey);
//		DecreaseKey(position);
//	}
//	else{}
//}
//void PriorityQueue::IncreaseKey(int position)
//{
//	int i, child;
//	progress temProg;
//	for (i = position; 2 * i <= heap.size() - 1; i *= 2)
//	{
//		child = i * 2;
//		if (child != heap.size() && heap[child + 1] < heap[child])
//			child++;
//		if (heap[i] > heap[child])
//		{
//			temProg = heap[child];
//			heap[child] = heap[i];
//			heap[i] = temProg;
//		}
//		else
//			break;
//	}
//}
//void PriorityQueue::DecreaseKey(int position)
//{
//	int i, parent, newKey;
//	newKey = heap[position].get_key();
//	progress temProg;
//	for (parent = i = position; parent != 0;i=parent)
//	{
//		parent = i / 2;
//		if (newKey < heap[parent].get_key())
//		{
//			temProg = heap[parent];
//			heap[parent] = heap[i];
//			heap[i] = temProg;
//		}
//		else
//			break;
//	}
//}
//void PriorityQueue::clear()
//{
//	heap.clear();
//	Init();
//}
//
//void PriorityQueue::PrintResult()
//{
//	cout << "\n程序运行顺序为：" << endl;
//	cout << "程序\t\t资源数" << endl;
//	int i = 1;
//	progress tem;
//	while (heap.size() != 1)
//	{
//		tem = DeleteMin();
//		cout << setiosflags(ios::left)<<setw(18) << tem.get_name() <<  tem.get_key()<< '\n'<<flush;
//		i++;
//	}
//}