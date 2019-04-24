#include<vector>
#include<cstdio>
using namespace std;

bool IsPopOrder(vector<int> pInput, vector<int> pOutput, int length)
{
	if (pInput.size() != pOutput.size() || length <= 0)
		return false;

	int num = length - 1;
	while (pInput[num] != pOutput[0])//����ջ�ĸо����Ӻ���ǰ����ƥ��Ļ��һ���
	{                                 //�ҵ���һ����ȵ�ֵ
		num -= 1;
		if (num < 0)
			return false;
	}

	int num_left = num;//��Ӧ�õ�һ����ȵ�ֵ�󣬽������ڶ���output��ֵֻ�ܵ��ڵ�һ��input��ֵ�����һ��ֵ���ұ�һ��ֵ
	int num_right = num;
	int now_left = pOutput[0];//���ò��ظ��ԣ�����һ�ζ�Ӧ�ɹ���ֵ��Ϊ�����Ĳ�����ȡ���ĵ�
	int now_right = pOutput[0];

	if (num_left > 0)
	{
		num_left -= 1;//input��ֵ����
		now_left = pInput[num_left];
	}
	if (num_right < length - 1)
	{
		num_right += 1;//��ֵ����
		now_right = pInput[num_right];
	}

	for (int i = 1; i <= length - 1; ++i)//��ʼ��Ӧ�����ļ���ֵ
	{
		if (pOutput[i] != now_left && pOutput[i] != now_right)
			return false;


		if (pOutput[i] == now_left)
		{
			if (i == length - 1)//output�ߵ�ͷ�ˣ�����Ӧ����
				return true;
			if (num_left > 0)
			{
				num_left -= 1;
				now_left = pInput[num_left];
			}
			else
				now_left = pOutput[0];
		}

		if (pOutput[i] == now_right)
		{
			if (i == length - 1)//ͬ��
				return true;
			if (num_right < length - 1)
			{
				num_right += 1;
				now_right = pInput[num_right];
			}
			else
				now_right = pOutput[0];
		}
	}
	return true;
}

void Test(const char* testname, vector<int> pInput, vector<int> pOutput, int length,bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	bool result = IsPopOrder(pInput, pOutput, length);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

}

void test1()
{
	vector<int> pInput = { 1,2,3,4,5 };
	vector<int> pOutput = { 4,5,3,2,1 };
	Test("test1", pInput, pOutput, 5, true);
}

void test2()
{
	vector<int> pInput = { 1,2,3,4,5 };
	vector<int> pOutput = { 4,5,3,1,2 };
	Test("test2", pInput, pOutput, 5, false);
}

void test3()
{
	vector<int> pInput;
	vector<int> pOutput;
	Test("test3", pInput, pOutput, 0, false);
}

void test4()
{
	vector<int> pInput = { 1,2,3,4 };
	vector<int> pOutput = { 4,5,3,2,1 };
	Test("test4", pInput, pOutput, 4, false);
}

void test5()
{
	vector<int> pInput = {1};
	vector<int> pOutput = {1};
	Test("test5", pInput, pOutput, 1, true);
}

void test6()
{
	vector<int> pInput = { 1 };
	vector<int> pOutput = { 2 };
	Test("test6", pInput, pOutput, 1, false);
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