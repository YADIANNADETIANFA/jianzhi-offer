#include<cstdio>
#include<exception>
#include<cstdlib>//rand(),srand()ͷ�ļ�
#include<ctime>
using namespace std;

int RandomInRange(int, int);//����
void Swap(int*, int*);
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (index != small)
			{
				Swap(&data[index], &data[small]);
			}
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
	{
		try
		{
			QuickSort(data, length, start, index - 1);
		}
		catch (exception& e)
		{
			printf("Invalid Parameters.");
		}
	}

	if (index < end)
	{
		try
		{
			QuickSort(data, length, index + 1, end);
		}
		catch (exception& e)
		{
			printf("Invalid Parameters.");
		}
	}
}

int RandomInRange(int start, int end)
{
	if (start < end)
	{
		srand(time(NULL));//rand()�������������ÿ�����е�ʱ��������һ����ͬ�ġ���Ҫ��ͬ,�ú���srand()��ʼ������
		return start + rand() % (end - start);//��������srand((unsigned int)(time(NULL))�ķ�����������ͬ����������ӣ���Ϊÿһ�����г����ʱ���ǲ�ͬ�ġ�
	}
	return start;
}

void Swap(int* elem1, int* elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void Print(int data[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%u\n", data[i]);
	}
}
int main()
{
	int num[9] = { 1,2,3,2,2,2,5,4,2 };
	int length = sizeof(num) / sizeof(num[0]);
	QuickSort(num, 9, 0, length-1);
	Print(num,length);//����������������ʱ���˻�Ϊ��ָͨ�룬�����������׵�ַ�������ڱ�ĺ������޷��������鳤�ȣ�Ҫ�ȼ�������ٴ���ȥ
	return 0;
}

/*void Print(int data[])
{
	for (int i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
	{
		printf("%u\n", data[i]);
	}
}
int main()
{
	int num[9] = { 1,2,3,2,2,2,5,4,2 };
	QuickSort(num, 9, 0, sizeof(num)/sizeof(num[0]) - 1);
	Print(num);//�����ô���Ļ���ֻ����num���׸�Ԫ�أ������Ǵ�ӡ��numȫ����
	return 0;
}*/