//�ʺ������
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
	if (*pBegin == '\0')//�������о����㲻ͬ�С���ͬ�е�Ҫ��
	{
		for (int i = 0; i < SideLength; ++i)
		{
			for (int j = i + 1; j < SideLength; ++j)
			{
				if (i - j == pstr[i] - pstr[j] || j - i == pstr[i] - pstr[j])//���ڶԽ��ߵ�Ҫ�����������㣬ע�����ʼ�ն���pstr[i] - pstr[j]�������i��j����˳��
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