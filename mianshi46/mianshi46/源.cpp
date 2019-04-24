#include<cstdio>
#include<string>

using namespace std;

void NumOfTranslation(string& numTostr, string::iterator Begin, string::iterator End, int& count);//stringҲ��һ������������������ü�������

int GetTrans(int number)
{
	if (number < 0)
		return 0;
	string numTostr = to_string(number);//stringʹ��std��to_string��������
	int count = 0;
	NumOfTranslation(numTostr, numTostr.begin(), numTostr.end(), count);
	return count;
}

void NumOfTranslation(string& numTostr, string::iterator Begin, string::iterator End, int& count)//�ݹ����
{
	if (Begin == End)
		return ;
	else if ((Begin + 1) == End)
	{
		++count;//ʲôʱ���뵽����ã�����������ˣ�count��+1
		return;
	}
	else if ((Begin + 2) == End)
	{
		NumOfTranslation(numTostr, Begin + 1, End, count);
		if (((*Begin - '0') * 10 + *(Begin + 1) - '0') <= 25 && (*Begin-'0') != 0)//Լ��������������һ���ǲ���25����һ���ǲ��ܷ��� 00 01 ��������λ�ַ�
			++count;//ͬ�ϣ�ʲôʱ���뵽����ã�����������ˣ�count��+1
		return;
	}
	else//((Begin + 2) < End)��Ҳ�����滹����λ���ϵ��ַ�
	{
		NumOfTranslation(numTostr, Begin + 1, End, count);
		if (((*Begin - '0') * 10 + *(Begin + 1) - '0') <= 25 && (*Begin - '0') != 0)
			NumOfTranslation(numTostr, Begin + 2, End, count);
		return;
	}
}

void Test(const char* testname, int number, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = GetTrans(number);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1", 0, 1);
	Test("test2", 10, 2);
	Test("test3", 125, 3);
	Test("test4", 126, 2);
	Test("test5", 426, 1);
	Test("test6", 100, 2);
	Test("test7", 101, 2);
	Test("test8", 12258, 5);
	Test("test9", -100, 0);

	return 0;
}
