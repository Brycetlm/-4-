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

	//���ֳ�������ѡ�񣬲��룬ϣ����
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
			//ע������������߱ȣ�Ҳ����ǰ��j-1�������������
			//Ȼ���j��Ԫ�ؿ�ʼ��ǰ����룬���Ԫ�ػ��ҵ��Լ���λ��
			for (size_t j = i; j >0;j--)  //ע��j--����˼������߱Ƚ�
			{
				//!!���Ĵ���
				//!!����������Ԫ�ر�����ߵ�С��������ȥ��ֱ���ҵ��Լ���λ��
				if (arr[j] < arr[j - 1]) { exch(&arr[j], &arr[j - 1]); }
			}
		}
		show(arr);
	}

	//�Ľ��Ĳ�������->ϣ������
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

//�鲢����
//�鲢��Ҫ�ĺϲ�����merge���ϲ��Ĺ������Ҫ����
static int temp[N]; //@@@@@@@!!!!!!!!11��̬��Ա�������������ⶨ�壬�����ü�pulic
class Merge {
public:
	
	
	static void merge(int* arr, int lo, int mid, int hi)
	{
		//�����α�
		int i = lo;
		int j = mid + 1;
		for (size_t k = lo; k <= hi; k++)
		{
			temp[k] = arr[k];

		}
		//�㷨4���Ϸ���
		for (size_t k = lo; k <= hi; k++)
		{
			//@@@!!!ע��������j++��Ҳ��arr[k]=temp[j],Ȼ��j=j+1;

			 //������i>mid��j>hi���ж��������˼�������߻����ұ������꣬��ôʣ�µ��ұ߻������Ԫ����������
			//����i>mid������Ѿ����꣬��ôʣ�µ�arrλ�����ұ�ռ��
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
		if (hi <= lo)return;    //������ֹ����
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
	
	//!!!c++�з��ʾ�̬��������::������.����->
	//Sort::select_sort(a);
	//Sort::insert_sort(a);
	//Sort::shell_sort(a);
	Merge::merge_sort(a);

	////������++ʵ��
	//std::cout << "������++ʵ��";
	//int t = 0;
	//int test[3] = { 0,1,2 };
	//std::cout << test[0] << test[t++];
	//std::cout <<test[++t];

}

