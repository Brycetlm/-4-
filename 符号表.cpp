#include<iostream>
#define N 50
//1.����c++�з��ͱ�̵�ʵ��
//1.1��Ҫ��ģ��template<class Type>��classҲ����typename�ؼ������������һ�㶼��typename��

//2.���ű�
//2.1 ����  ��Ҫʵ�ֵ�������֤ÿ�������ܱ�����
//2.2 ���ĵȼ��ԣ�equals������Ҫ��֤����Ψһ�ԣ�������Ҫ����ȽϺ�����һЩϵͳ�������Դ���������������Զ������������Ҫʵ��
//2.3 ���ű���Ҫʵ�ֵ�API����get��put����

//3. ���ű��ʵ��
//3.1 ���ּ�ʵ��
//3.1.1 ���������е�˳�����
//3.1.2 ���������еĶ��ֲ���

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

	////3.1.2 ���������еĶ��ֲ���
	int rank(int* arr,int key)
	{
		int lo = 0;
		int hi = N;
		while (lo<hi)
		{
			int mid = lo+(hi-lo) / 2;  //!!!!!1ע��mid�ļ���    
			if (key == arr[mid])return arr[mid];
			else if (key < arr[mid]) hi = mid - 1;
			else if(key > arr[mid]) lo = mid + 1;
			//std::cout << lo << "  " << hi;
		}
		//����ҵ����Ҳû�ҵ�
		return 0;
	}
};




int main()
{
	int a[N];
	
	for (size_t i = 0; i < N; i++)
	{
		a[i] = i;//��������
	}

	ST<int,int> test;
	//����һ�����飬���ö��ֲ��������еĵ��ĸ�value
	//����ʵ�㷨4��rank�������ص���������С��keyֵ��indexλ��
	test.rank(a,3); 
	std::cout << test.rank(a, 3) << std::endl;
	std::cout << test.rank(a, 500);
}