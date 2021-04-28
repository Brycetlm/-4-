//#include<iostream>
//
////优先队列主要的两个API为插入元素Insert和弹出delMax最大元素
////可以简单的用数组实现一个无序或者有序的优先队列，这样的优先队列复杂度为线性N
//
////1.也可以用数组来组织一棵树，复杂度为logN
////2.二叉树中，位置为k的元素其父节点为k/2向下取整，其两个子节点为2k和2k+1，
//// 注意这里从arr[1]开始，不用arr[0]，因为1*2=2，1*2+1=3；0没有作用
////例如位置为5，arr[5]，其父节点为5/2=2，两个子节点为arr[10]，arr[11]
////3.对于这样的树，可以用两种方法使其在元素增加或者减少时重新有序化，树状化
////3.1 swim 上浮。将元素从树的底部往上浮，当这个元素比其父节点大时，与父节点交换，然后继续比较交换直到比父节点小
////3.2 sink 下沉。将元素从树的顶部往下沉，比子节点小就下沉。
////这种数组组织成的树没有结构开销，只在API中体现这种结构
////4.delMax的逻辑是，删除arr[1]，然后arr[last]（数组中最后一个元素）补位到第一个，然后sink(1)
////Insert的逻辑是，插入到数组最后一个，然后swim(last),让这个元素往上游
//
//class MaxPQ
//{
//
//public:
//	static void exch(int* a, int* b)
//	{
//		int temp = 0;
//		temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//
//	MaxPQ(int*arr,int size)  //初始化一个初始size大小的数组（插入后会变化）
//	{
//		this->size = size;
//		this->arr = new int[size];      //!!!在类中声明一个数组首地址后一定记得分配空间
//		for (size_t i = 0; i < size; i++)
//		{
//			this->arr[i] = arr[i];
//			
//		}
//	}
//
//	int Size()
//	{
//		return size;
//	}
//	
//	int delMax()
//	{
//		return arr[1];  //arr[0]不用
//		arr[1] = arr[size - 1];
//		sink(1);
//	}
//
//	void insert(int i)  
//	{
//		int* temp= new int[size]();  //分配空间并全部初始化为0
//		memmove(temp,arr,size*sizeof(int));   //!!!!!!!!!!!!!!!!注意这里的第三个参数，不是元素个数，而是空间字节大小
//		this->arr= new int[size+1]();
//		memmove(arr, temp, size * sizeof(int));  //memmove比memccpy好用
//		arr[size] = i;
//		
//		this->size = size + 1;
//		swim(size-1);
//
//	}
//
//	void show()
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			std::cout << arr[i]<<std::endl;
//		}
//	}
//
//private:
//	int size;
//	int* arr;
//	
//	void swim(int k)
//	{
//		int temp =0;
//		while (true)
//		{
//			temp = floor(k / 2);
//			if (arr[k] > arr[temp])
//			{
//				exch(&arr[k], &arr[temp]);
//				k = temp;
//			}
//			else break;
//		}
//		
//	}
//
//	void sink(int k) {
//		while (true)
//		{
//			int temp = 2 * k;
//			if (arr[k] < arr[temp]) { exch(&arr[k], &arr[temp]);k = temp; }
//			else break;
//		}
//		
//
//	}
//};
//
//int main()
//{
//	
//	int arr[50];
//	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
//	{
//		arr[i] = 0;
//	}
//	//!!!!!!!绝了，c++里数组没有获取长度的函数，可以用sizeof计算
//	//std::cout << sizeof(arr) / sizeof(int);
//	MaxPQ max(arr, sizeof(arr) / sizeof(int)); 
//	
//	max.insert(20);
//	max.insert(30);
//	max.insert(80);
//	max.delMax();
//	max.show();
//	//std::cout << max.Size();
//
//}
//
