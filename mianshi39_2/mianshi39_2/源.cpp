//����2�����øı�ԭ������
#include<cstdio>

using namespace std;


bool CheckInvalidArray(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return true;

	return false;
}

bool CheckMoreThanHalf(int* number, int length, int result)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == result)
			++times;
	}
	if (times * 2 > length)
		return true;

	return false;
}

int MoreThanHalfNum(int* number, int length)//Ѱ�������г��ִ��������Ǹ���ֵ
{                                           //����������ִ�������һ�룬������times�ض����ڵ���1,  ����times���ڵ���1δ�ظ������ִ�������һ�룡������
	if (CheckInvalidArray(number, length))  //�����߲������Ի��ƣ����β����ҪУ���Ƿ��������һ�������
		return 0;

	int SelectNum = number[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (SelectNum == number[i])
			++times;
		else
		{
			--times;
			if (times == 0)
			{
				SelectNum = number[i];
				times = 1;
			}
		}
	}

	int result = 0;
	if (times >= 1)
	{
		result = SelectNum;
		if (!CheckMoreThanHalf(number, length, result))
			return 0;
		return result;
	}
	return result;
}

void Test(const char*testname, int* number, int length, int ExcepNum)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

		int result = MoreThanHalfNum(number, length);
		if (result == ExcepNum)
			printf("Pass\n");
		else
			printf("Fail\n");

	
}

void test1()
{
	int number[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test("test1", number, sizeof(number) / sizeof(int), 2);
}

void test2()
{
	int number[] = { 1, 2, 3, 2, 2, 3, 5, 4, 4 };
	Test("test2", number, sizeof(number) / sizeof(int), 0);
}

void test3()
{
	int number[] = { 2,2,2,2,2,1,3,4,5 };
	Test("test3", number, sizeof(number) / sizeof(int), 2);
}

void test4()
{
	int number[] = { 1,3,4,5,2,2,2,2,2 };
	Test("test4", number, sizeof(number) / sizeof(int), 2);
}

void test5()
{
	int number[] = { 2 };
	Test("test5", number, sizeof(number) / sizeof(int), 2);
}

void test6()
{
	Test("test6", nullptr, 0, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}