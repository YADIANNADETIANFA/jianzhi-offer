#include<cstdio>
#include<exception>

using namespace std;

void theDifferentNum(int* data, int length,int& result)//���ô�ֵ��ʡ��try���涫����������
{
	if (data == nullptr || length <= 0)
		throw exception("Bad Parameters");

	int bitSum[3] = { 0 };//ȫ����0��������Ĭ����������ȫ��1~7������

	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((data[i] >> j) & 1 == 1)
				++bitSum[j];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if ((bitSum[i] % 3) != 0)//�����࣬�����������㣡
			result += (1 << i);
	}

	return;
}

void Test(const char* testname, int* data, int length, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = 0;

	try
	{
		theDifferentNum(data, length, result);
	}
	catch (exception& e)
	{
		printf("Bad Parameters\n");
		return;
	}
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

void Test1()
{
	int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
	int expected = 3;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �������ֶ���������Ψһ�����ֵĴ�Сλ���м�
void Test2()
{
	int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
	int expected = 4;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// �������ֶ���������Ψһ������������
void Test3()
{
	int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
	int expected = 7;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test4()
{
	int expected = 0;
	Test("Test4", nullptr, 0, expected);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

