//#include<iostream>
//
////���ȶ�����Ҫ������APIΪ����Ԫ��Insert�͵���delMax���Ԫ��
////���Լ򵥵�������ʵ��һ�����������������ȶ��У����������ȶ��и��Ӷ�Ϊ����N
//
////1.Ҳ��������������֯һ���������Ӷ�ΪlogN
////2.�������У�λ��Ϊk��Ԫ���丸�ڵ�Ϊk/2����ȡ�����������ӽڵ�Ϊ2k��2k+1��
//// ע�������arr[1]��ʼ������arr[0]����Ϊ1*2=2��1*2+1=3��0û������
////����λ��Ϊ5��arr[5]���丸�ڵ�Ϊ5/2=2�������ӽڵ�Ϊarr[10]��arr[11]
////3.�����������������������ַ���ʹ����Ԫ�����ӻ��߼���ʱ�������򻯣���״��
////3.1 swim �ϸ�����Ԫ�ش����ĵײ����ϸ��������Ԫ�ر��丸�ڵ��ʱ���븸�ڵ㽻����Ȼ������ȽϽ���ֱ���ȸ��ڵ�С
////3.2 sink �³�����Ԫ�ش����Ķ������³������ӽڵ�С���³���
////����������֯�ɵ���û�нṹ������ֻ��API���������ֽṹ
////4.delMax���߼��ǣ�ɾ��arr[1]��Ȼ��arr[last]�����������һ��Ԫ�أ���λ����һ����Ȼ��sink(1)
////Insert���߼��ǣ����뵽�������һ����Ȼ��swim(last),�����Ԫ��������
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
//	MaxPQ(int*arr,int size)  //��ʼ��һ����ʼsize��С�����飨������仯��
//	{
//		this->size = size;
//		this->arr = new int[size];      //!!!����������һ�������׵�ַ��һ���ǵ÷���ռ�
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
//		return arr[1];  //arr[0]����
//		arr[1] = arr[size - 1];
//		sink(1);
//	}
//
//	void insert(int i)  
//	{
//		int* temp= new int[size]();  //����ռ䲢ȫ����ʼ��Ϊ0
//		memmove(temp,arr,size*sizeof(int));   //!!!!!!!!!!!!!!!!ע������ĵ���������������Ԫ�ظ��������ǿռ��ֽڴ�С
//		this->arr= new int[size+1]();
//		memmove(arr, temp, size * sizeof(int));  //memmove��memccpy����
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
//	//!!!!!!!���ˣ�c++������û�л�ȡ���ȵĺ�����������sizeof����
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
