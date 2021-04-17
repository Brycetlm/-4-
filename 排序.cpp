#include<iostream>
#define N 50

class Sort {
public:
	static void show(int* arr)
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << arr[i]<<std::endl;
		}
	}

	static void exch(int *a,int *b)
	{
		int temp = 0;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	//三种初级排序（选择，插入，希尔）
	static void select_sort(int* arr)
	{
		
		for (int i = 0; i < N; i++)
		{
			int max = i;
			
			for (int j = i+1; j < N; j++)
			{
				if (arr[max] < arr[j]) { max = j; }
			}
			exch(&arr[i], &arr[max]);
		}
		show(arr);
		
	}

	static void insert_sort(int* arr)
	{
		for (size_t i = 1; i < N; i++) 
		{
			//注意这里是往左边比，也就是前面j-1个现在是有序的
			//然后从j个元素开始往前面插入，这个元素会找到自己的位置
			for (size_t j = i; j >0;j--)  //注意j--，意思是往左边比较
			{
				//!!核心代码
				//!!如果发现这个元素比它左边的小，就往左去。直到找到自己的位置
				if (arr[j] < arr[j - 1]) { exch(&arr[j], &arr[j - 1]); }
			}
		}
		show(arr);
	}

	//改进的插入排序->希尔排序
	static void shell_sort(int* arr)
	{

		int h = N;
		//while (h < N / 3)h = 3 * h + 1;
		while (h > 1)
		{
			h = h / 2;
			for (size_t i = h; i < N; i++)
			{

				for (size_t j = i; j >=h;j-=h)
				{

					if (arr[j] < arr[j - h]) { exch(&arr[j], &arr[j - h]); }
				}
				
			}
			
		}

		show(arr);
	}


	

};

//归并排序
//归并需要的合并函数merge，合并的规则很重要！！
static int temp[N]; //@@@@@@@!!!!!!!!11静态成员变量必须在类外定义，并不用加pulic
class Merge {
public:
	
	
	static void merge(int* arr, int lo, int mid, int hi)
	{
		//两个游标
		int i = lo;
		int j = mid + 1;
		for (size_t k = lo; k <= hi; k++)
		{
			temp[k] = arr[k];

		}
		//算法4书上方法
		for (size_t k = lo; k <= hi; k++)
		{
			//@@@!!!注意这里是j++，也就arr[k]=temp[j],然后j=j+1;

			 //这两句i>mid和j>hi的判断是这个意思：如果左边或者右边先排完，那么剩下的右边或者左边元素依次落座
			//例如i>mid即左边已经排完，那么剩下的arr位置由右边占据
			if (i > mid) arr[k] = temp[j++];         
			else if (j > hi) arr[k] = temp[i++];

			else if (temp[j] < temp[i])arr[k] = temp[j++];
			else arr[k] = temp[i++];

		}
		 
		

	}
	static void merge_sort(int* arr)
	{

		merge_sort(arr, 0, N - 1);
		Sort::show(arr);
	}
	static void merge_sort(int* arr, int lo, int hi)
	{
		if (hi <= lo)return;    //迭代终止条件
		int mid = lo + (hi- lo) / 2;
		merge_sort(arr, lo, mid);
		merge_sort(arr, mid+1, hi);
		merge(arr, lo, mid, hi);


	}
};

int main()
{
	int a[N];
	
	for (size_t i = 0; i < N; i++)
	{
		a[i] = -2 * i * i + 100 * i + 6;
	}
	
	//!!!c++中访问静态函数是用::而不是.或者->
	//Sort::select_sort(a);
	//Sort::insert_sort(a);
	//Sort::shell_sort(a);
	Merge::merge_sort(a);

	////数组内++实验
	//std::cout << "数组内++实验";
	//int t = 0;
	//int test[3] = { 0,1,2 };
	//std::cout << test[0] << test[t++];
	//std::cout <<test[++t];

}

