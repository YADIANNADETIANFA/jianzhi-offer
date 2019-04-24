#include<iostream>

int CountNum(const int& start, const int& end, const int* a, const int& length);//����������Ȼ����֡�CountNum�Ҳ�����ʶ�����ı���
int getDuplication(const int *a, int length)
{
	if(a==nullptr || length<2)
	{
		return -1;
	}
	for (int i = 0; i < length; ++i)//ǿ��ʹ��û���ظ����Ļ���ֱ�ӷ���-1
	{
		if (a[i] >= length || a[i] < 1)
		{
			return -1;
		}
	}
	//int middle = (length - 1) / 2;  //��������
	int start = 1;
	int end = length - 1;
	while (end >= start)//>=����>?
	{
		int middle = ((end - start) >> 1 )+ start;//���ԣ�������������������λ�����ʲô��,Ӧ����ȡ��ֵ
		int num = CountNum(start, middle, a, length);
		if (middle - start + 1 < num)
		{
			end = middle;
		}
		else
		{
			start = middle;
		}
		if (start == end)
		{
			return num;
		}
	}
	
}
int CountNum(const int& start, const int& end, const int* a,const int& length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] >= start && a[i] <= end)
		{
			++count;
		}
	}
	return count;
}

void Test1()
{
	int a[8] = { 2,3,5,4,3,2,6,7 };
	int result = getDuplication(a, 8);
	printf("Expect result:%u or %u.\n", 2, 3);
	printf("The actual result:%u.\n", result);
}

void Test2()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	int result = getDuplication(a, 8);
	printf("Expect result:%d.\n", -1);
	printf("The actual result:%d.\n", result);
}

void Test3()
{
	int* a = nullptr;
	int result = getDuplication(a, 2);
	printf("Expect result:%d.\n", -1);
	printf("The actual result:%d.\n", result);
}
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}