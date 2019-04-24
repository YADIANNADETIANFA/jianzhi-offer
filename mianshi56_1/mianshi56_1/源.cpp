#include<cstdio>
#include<exception>

using namespace std;//���ô󷨺�

int theFirstDifferentBit(int* data, int length)//����ֻ������0����������û�п��Ǹ��������
{
	if (data == nullptr || length <= 1)
		return -1;
	int resultXORAll = 0;
	for (int i = 0; i < length; ++i)
		resultXORAll ^= data[i];
	if (resultXORAll == 0)//��û�в�ͬ���֣�����������ȫ��ͬ
		return -1;
	else
	{
		int k = 1;
		while (resultXORAll != 1)
		{
			++k;
			resultXORAll = resultXORAll >> 1;
		}
		return k;
	}
}

void theDifferentNum(int* data, int length, int k, int& num1, int& num2)//��������ֵ�ģ��������������
{
	if (k == -1)
		throw exception("Error Parameter");

	for (int i = 0; i < length; ++i)
	{
		if ((data[i] >> (k - 1)) & 1 == 1)//Ĭ������һ����������ͬ�����֣��������ֻ��һ����ͬ���֣����߳���3�������ϲ�ͬ���ֵ����
			num1 ^= data[i];
		else
			num2 ^= data[i];
	}
}

void Test(const char* testname, int* data, int length,int expected1,int expected2)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int theFirstDifBit = theFirstDifferentBit(data, length);
	int num1 = 0;
	int num2 = 0;
	try
	{
		theDifferentNum(data, length, theFirstDifBit, num1, num2);
	}
	catch(exception& e)
	{
		printf("Error Parameter\n");
		return;//catch֮���ǻ����ִ�к����if���ģ��������������Ǽ�return
	}
	if ((num1 == expected1 && num2 == expected2) || (num1 == expected2 && num2 == expected1))
		printf("Pass\n");
	else
		printf("Fail\n");
}

void test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void test2()
{
	int data[] = { 4,6 };
	Test("test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void test3()
{
	int data[] = { 4,6,1,1,1,1 };//{ 4,6,1,1,1,1 }���ԣ�����{ 4,6,1,1,1 }�����ԣ���Ϊ3��1�໥��������1������0��������ͬ�����ֱ���ɶԳ��ָó��������
	Test("test3", data, sizeof(data) / sizeof(int), 4, 6);
}

void test4()
{
	int data[] = { 1,1,1,1 };
	Test("test4", data, sizeof(data) / sizeof(int), -1, -1);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}