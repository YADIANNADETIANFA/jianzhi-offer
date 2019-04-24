#include<cstdio>
#include<iostream>

using namespace std;

void Combination(char* pBegin1, char* pBegin2, char* temp);


void Combination(char* pstr, int length)//�Լ�д�ģ��Ը�����
{
	if (pstr == nullptr || length < 1)
		return;

	for (int getlength = 1; getlength <= length; ++getlength)
	{
		char* temp = new char[getlength + 1];//�������飬ʵΪָ��
		temp[getlength] = '\0';
		Combination(pstr, temp, temp);
		delete[] temp;
	}
}

void Combination(char* pBegin1, char* pBegin2, char* temp)
{
	if (*pBegin2 == '\0')
		printf("%s\n", temp);
	else if (*pBegin1 != '\0')
	{
		*pBegin2 = *pBegin1;//�׸��ַ�ѹ��temp
		Combination(pBegin1 + 1, pBegin2 + 1, temp);//�����ַ�

		Combination(pBegin1 + 1, pBegin2, temp);//�׸��ַ�����ѹ��temp
	}
}

void Test(const char*testname, char* pstr, int length)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	Combination(pstr, length);
	cout << endl;
}

void test1()
{
	char str[] = "abc";
	Test("test1", str, 3);
}

void test2()
{
	char str[] = "a";
	Test("test2", str, 1);
}

void test3()
{
	Test("test3", nullptr, 0);
}

void test4()
{
	char str[] = "aaa";
	Test("test1", str, 3);
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}