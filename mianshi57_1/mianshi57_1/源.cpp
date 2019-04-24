#include<cstdio>
#include<exception>

using namespace std;

void theNumPair(int* data, int length, int s,int& num1,int& num2)//������start��end����ָ�봫�����������ں����ڲ�����ָ�룬��ֱ�Ӱ�num1��num2���������������򵥲��׳�������
{
	if (data == nullptr || length < 2)
		throw exception("Bad Parameter");//�����ǲ���return�ģ�����

	int i = 0;
	int j = length - 1;

	if (data[i] + data[j] == s)
	{
		num1 = data[i];
		num2 = data[j];
		return;
	}

	while (data[i] + data[j] != s)
	{
		while ((data[i] + data[j] > s) && (i != j - 1))
			j = j - 1;
		while ((data[i] + data[j] < s) && (i != j - 1))
			i = i + 1;
		if ((i == j - 1) && (data[i] + data[j] != s))
			throw exception("Bad Parameter");
	}
	num1 = data[i];
	num2 = data[j];
	return;
}

void Test(const char* testname, int* data, int length, int s)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int num1 = 0;
	int num2 = 0;
	try
	{
		theNumPair(data, length, s, num1, num2);
	}
	catch (exception& e)
	{
		printf("Bad Parameter\n");
		return;
	}
	printf("%d,%d\n", num1, num2);
}

// ���ں�Ϊs���������֣�����������λ��������м�
void Test1()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, sizeof(data) / sizeof(int), 15 );
}

// ���ں�Ϊs���������֣�����������λ�����������
void Test2()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, sizeof(data) / sizeof(int), 17 );
}

// �����ں�Ϊs����������
void Test3()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, sizeof(data) / sizeof(int), 10 );
}

// ³���Բ���
void Test4()
{
	Test("Test4", nullptr, 0, 0 );
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}