//#include<iostream>
//#define N 50
//
//class Sort {
//public:
//	static void show(int* arr)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			std::cout << arr[i]<<std::endl;
//		}
//	}
//
//	static void exch(int *a,int *b)
//	{
//		int temp = 0;
//		temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//
//	//三种初级排序（选择，插入，希尔）
//	static void select_sort(int* arr)
//	{
//		
//		for (int i = 0; i < N; i++)
//		{
//			int max = i;
//			
//			for (int j = i+1; j < N; j++)
//			{
//				if (arr[max] < arr[j]) { max = j; }
//			}
//			exch(&arr[i], &arr[max]);
//		}
//		show(arr);
//		
//	}
//
//	static void insert_sort(int* arr)
//	{
//		for (size_t i = 1; i < N; i++) 
//		{
//			//注意这里是往左边比，也就是前面j-1个现在是有序的
//			//然后从j个元素开始往前面插入，这个元素会找到自己的位置
//			for (size_t j = i; j >0;j--)  //注意j--，意思是往左边比较
//			{
//				//!!核心代码
//				//!!如果发现这个元素比它左边的小，就往左去。直到找到自己的位置
//				if (arr[j] < arr[j - 1]) { exch(&arr[j], &arr[j - 1]); }
//			}
//		}
//		show(arr);
//	}
//
//	//改进的插入排序->希尔排序
//	static void shell_sort(int* arr)
//	{
//
//		int h = N;
//		//while (h < N / 3)h = 3 * h + 1;
//		while (h > 1)
//		{
//			h = h / 2;
//			for (size_t i = h; i < N; i++)
//			{
//
//				for (size_t j = i; j >=h;j-=h)
//				{
//
//					if (arr[j] < arr[j - h]) { exch(&arr[j], &arr[j - h]); }
//				}
//				
//			}
//			
//		}
//
//		show(arr);
//	}
//
//
//	
//
//};
//
////归并排序
////归并需要的合并函数merge，合并的规则很重要！！
//static int temp[N]; //@@@@@@@!!!!!!!!11静态成员变量必须在类外定义，并不用加pulic
//class Merge {
//public:
//	
//	
//	static void merge(int* arr, int lo, int mid, int hi)
//	{
//		//两个游标
//		int i = lo;
//		int j = mid + 1;
//		for (size_t k = lo; k <= hi; k++)
//		{
//			temp[k] = arr[k];
//
//		}
//		//算法4书上方法
//		for (size_t k = lo; k <= hi; k++)
//		{
//			//@@@!!!注意这里是j++，也就arr[k]=temp[j],然后j=j+1;
//
//			 //这两句i>mid和j>hi的判断是这个意思：如果左边或者右边先排完，那么剩下的右边或者左边元素依次落座
//			//例如i>mid即左边已经排完，那么剩下的arr位置由右边占据
//			if (i > mid) arr[k] = temp[j++];         
//			else if (j > hi) arr[k] = temp[i++];
//
//			else if (temp[j] < temp[i])arr[k] = temp[j++];
//			else arr[k] = temp[i++];
//
//		}
//		 
//		
//
//	}
//	static void merge_sort(int* arr)
//	{
//
//		merge_sort(arr, 0, N - 1);
//		Sort::show(arr);
//	}
//	static void merge_sort(int* arr, int lo, int hi)
//	{
//		if (hi <= lo)return;    //迭代终止条件
//		int mid = lo + (hi- lo) / 2;
//		merge_sort(arr, lo, mid);
//		merge_sort(arr, mid+1, hi);
//		merge(arr, lo, mid, hi);
//
//
//	}
//};
//
////归并排序和快速排序的异同
////1.两者都是采用了分治的思想，利用递归排序
////1.归并排序只是单纯的调用递归将大数组分为小数组排序
////2.快速排序则根据切分值将数组分为大小两个部分然后递归排序，最后只需要合并就行，不用再对合并的数组排序
//class Quick {
//	
//public:
//	//快排中比较重要的是切分函数
//	//主要过程为:例如指定切分值为x，那么从数列左边开始找到一个大于x的值，从数列右边开始找到一个小于x的值，两者交换位置，保证x左右分别为小于和大于x的值
//	static int partition(int *arr,int lo,int hi)
//	{
//		int i = lo, j = hi + 1;  //左右扫描指针
//		//随便指定一个切分元素x
//		int x = arr[lo];
//		while (true)
//		{
//			//!!!!!!!!!!@@@@@@@@@@while语句注意，和隐去的内容完全是两个意思
//			while (arr[++i] > x) /*{ i++; }*/if (i == hi)break;
//			while (arr[--j] < x) /*{ j--; }*/if (j == lo)break;
//			if (i >= j)break;
//			Sort::exch(&arr[i], &arr[j]);
//		}
//		Sort::exch(&arr[lo], &arr[j]);
//		return j;
//	}
//
//	static void quick_sort(int *arr) {
//
//		quick_sort(arr, 0, N - 1);
//		Sort::show(arr);
//	}
//
//	static void quick_sort(int* arr,int lo,int hi) {
//		if (hi <= lo)return;
//		int j = partition(arr, lo, hi);
//		quick_sort(arr, lo, j-1);
//		quick_sort(arr, j+1, hi);
//
//	}
//
//};
//
//int main()
//{
//	int a[N];
//	
//	for (size_t i = 0; i < N; i++)
//	{
//		a[i] = -2 * i * i + 100 * i + 6;
//	}
//	
//	//!!!c++中访问静态函数是用::而不是.或者->
//	//Sort::select_sort(a);
//	//Sort::insert_sort(a);
//	//Sort::shell_sort(a);
//	//Merge::merge_sort(a);
//	//Quick::quick_sort(a);
//
//	////数组内++实验
//	//std::cout << "数组内++实验";
//	//int t = 0;
//	//int test[3] = { 0,1,2 };
//	//std::cout << test[0] << test[t++];  //表示访问tset[t],然后t++
//	//std::cout <<test[++t];
//
//	////while中++实验
//	int t = 1;
//	while (true)
//	{
//		while (++t > 2) { std::cout << t << std::endl;if (t > 10) { break; } }
//		if (t > 10) break;
//	}
//	std::cout << t << std::endl;
//	
//
//}
//
