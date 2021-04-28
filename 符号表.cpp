#include<iostream>
#define N 50
//1.关于c++中泛型编程的实现
//1.1主要是模板template<class Type>，class也可用typename关键字以免混淆（一般都用typename）

//2.符号表
//2.1 迭代  需要实现迭代来保证每个键都能被遍历
//2.2 键的等价性：equals方法。要保证键的唯一性，所以需要这个比较函数。一些系统的类型自带这个函数，对于自定义的类型则需要实现
//2.3 符号表主要实现的API就是get和put方法

//3. 符号表的实现
//3.1 两种简单实现
//3.1.1 无序链表中的顺序查找
//3.1.2 有序数组中的二分查找

template<typename T,typename K>
class ST {
public:
	void put()
	{

	}

	void delt()
	{

	}

	T get()
	{
		
	}

	////3.1.2 有序数组中的二分查找
	int rank(int* arr,int key)
	{
		int lo = 0;
		int hi = N;
		while (lo<hi)
		{
			int mid = lo+(hi-lo) / 2;  //!!!!!1注意mid的计算    
			if (key == arr[mid])return arr[mid];
			else if (key < arr[mid]) hi = mid - 1;
			else if(key > arr[mid]) lo = mid + 1;
			//std::cout << lo << "  " << hi;
		}
		//如果找到最后也没找到
		return 0;
	}
};




int main()
{
	int a[N];
	
	for (size_t i = 0; i < N; i++)
	{
		a[i] = i;//有序数组
	}

	ST<int,int> test;
	//传入一个数组，利用二分查找找其中的第四个value
	//但其实算法4的rank函数返回的是数组中小于key值的index位置
	test.rank(a,3); 
	std::cout << test.rank(a, 3) << std::endl;
	std::cout << test.rank(a, 500);
}