#include<cstdio>

int NumOfInverseCore(int*, int*, int, int);

int NumOfInverse(int*data, int length)
{
	if (data == nullptr || length <= 0)
		return 0;

	int* copy = new int[length];//Ĭ�ϳ�ʼ��Ϊ0��,������,Ҫ������г�ʼ��������鲢�㷨Ҳ��Ҫ������и���ֵ
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];

	int start = 0;
	int end = length - 1;

	int count = NumOfInverseCore(data, copy, start, end);
	delete[] copy;//���Ե�ʱ������ˣ���Ȼը��
	return count;
}

int NumOfInverseCore(int* data, int* copy, int start, int end)
{
	
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = NumOfInverseCore(copy, data, start, start + length);//�鲢�㷨�����������໥�����Ź鲢�������ݽṹ455
	int right = NumOfInverseCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int count = 0;
	int copyIndex = end;
	while (i >= start && j >= start + length + 1)//������Ƶĺܾ��ѧϰһ��
	{
		if (data[i] > data[j])
		{
			count += j - start - length;
			copy[copyIndex--] = data[i--];
		}
		else
		{
			copy[copyIndex--] = data[j--];
		}
	}

	if (i < start)//�����ԣ���for���������ظ�������ʡ�ԣ�����������forѭ��ֻ��һ���ᱻִ�У���Ϊ��������whileѭ��ֻ����i��j����һ��������ѭ��
	{
		for (; j >= start + length + 1; --j)
			copy[copyIndex--] = data[j];
	}
	if (j < start + length + 1)
	{
		for (; i >= start; --i)
			copy[copyIndex--] = data[i];
	}

	return left + right + count;
}

void Test(const char* testname, int* data, int length, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = NumOfInverse(data, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void Test1()
{
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// �ݼ���������
void Test2()
{
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int expected = 15;

	Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// ������������
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5, 6 };
	int expected = 0;

	Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ��һ������
void Test4()
{
	int data[] = { 1 };
	int expected = 0;

	Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// ������ֻ���������֣���������
void Test5()
{
	int data[] = { 1, 2 };
	int expected = 0;

	Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ���������֣��ݼ�����
void Test6()
{
	int data[] = { 2, 1 };
	int expected = 1;

	Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// ����������ȵ�����
void Test7()
{
	int data[] = { 1, 2, 1, 2, 1 };
	int expected = 3;

	Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
	int expected = 0;

	Test("Test8", nullptr, 0, expected);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	return 0;
}
