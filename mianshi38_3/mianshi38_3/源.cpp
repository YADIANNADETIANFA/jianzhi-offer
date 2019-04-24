//皇后的问题
#include<cstdio>
#include<iostream>
using namespace std;

void Permutation(char* pstr, char* pBegin,int SideLength);

void Permutation(char* pstr,int SideLength)
{
	if (pstr == nullptr)
		return;

	Permutation(pstr, pstr,SideLength);
}

void Permutation(char* pstr, char* pBegin,int SideLength)
{
	if (*pBegin == '\0')//所有排列均满足不同行、不同列的要求
	{
		for (int i = 0; i < SideLength; ++i)
		{
			for (int j = i + 1; j < SideLength; ++j)
			{
				if (i - j == pstr[i] - pstr[j] || j - i == pstr[i] - pstr[j])//关于对角线的要求在这里满足，注意后面始终都是pstr[i] - pstr[j]，后面的i、j不变顺序！
					return;
			}
		}
		printf("%s\n", pstr);
	}
	else
	{
		for (char* ch = pBegin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
			Permutation(pstr, pBegin + 1,SideLength);
			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

void Test(const char*testname, char* pstr,int SideLength)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	Permutation(pstr,SideLength);
	cout << endl;
}

void test1()
{
	char pstr[] = "0123";
	Test("test1", pstr,4);
}


int main()
{
	test1();

	return 0;
}