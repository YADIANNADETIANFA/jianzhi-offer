#include<iostream>
#include<cstdio>
using namespace std;

void Reorder(int* pData, bool(*func)(int), unsigned int length)//����ָ��
{
	if (pData == nullptr || length == 0)
		return;

	int* pfront = pData;
	int* pend = pData + length - 1;
	while (pfront < pend)
	{
		while (pfront < pend && !func(*pfront))//����ָ��
			++pfront;
		while (pfront < pend && func(*pend))
			--pend;

		if (pfront < pend)
		{
			int temp = *pfront;
			*pfront = *pend;
			*pend = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven(int* pData, unsigned int length)
{
	Reorder(pData, isEven, length);//����ָ��
}

void Print(int* pData,unsigned int length)
{
	if (pData == nullptr)
		return;
	printf("Print start:\n");
	int i = 0;
	while (i < length)
	{
		cout << pData[i] << " ";
		++i;
	}
	cout << endl;
	cout << "Print end."<<endl;
}

void Test(const char* testname,int* pData, unsigned int length)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	printf("Before Reorder:\n");
	Print(pData, length);
	printf("After Reorder:\n");
	ReorderOddEven(pData, length);
	Print(pData, length);
	cout << endl;
}

void test1()
{
	int num[] = { 1,2,3,4,5,6,7 };
	Test("test1", num, 7);
}

void test2()
{
	int num[] = { 2,4,6,1,3,5,7 };
	Test("test2", num, 7);
}

void test3()
{
	int num[] = { 1,3,5,7,2,4,6 };
	Test("test3", num, 7);
}

void test4()
{
	int num[] = { 1 };
	Test("test4", num, 1);
}

void test5()
{
	int num[] = { 2 };
	Test("test5", num, 1);
}

void test6()
{
	Test("test6", nullptr, 0);
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}