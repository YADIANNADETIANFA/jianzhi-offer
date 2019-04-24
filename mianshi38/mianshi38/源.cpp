#include<cstdio>
#include<iostream>
using namespace std;

void Permutation(char* pstr, char* pBegin);

void Permutation(char* pstr)
{
	if (pstr == nullptr)
		return;

	Permutation(pstr, pstr);
}

void Permutation(char* pstr, char* pBegin)
{
	if (*pBegin == '\0')
		printf("%s\n", pstr);
	else
	{
		for (char* ch = pBegin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
			Permutation(pstr, pBegin + 1);
			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

void Test(const char*testname, char* pstr)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	Permutation(pstr);
	cout << endl;
}

void test1()
{
	//char* pstr[] = "abc";//�ᱨ��ģ������޸������� ���ԣ�����Ҳ����ִ�в���
	char pstr[] = "abc";//����ע��һ�£�char* pstr1 = "abc";����������Ǹ���������char pstr2[] = "abc";����������Ǹ����顣
	Test("test1", pstr);//pstr1ָ���ַ������������ܸı���ָ������ݣ�pstr2�ռ�����ڶ�ջ�ϣ����Զ���������޸�
}

void test2()
{
	char pstr[] = "aaa";
	Test("test2", pstr);
}

void test3()
{
	char pstr[] = "a";
	Test("test3", pstr);
}

void test4()
{
	char pstr[] = " ";
	Test("test4", pstr);
}

void test5()
{
	Test("test5", nullptr);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
