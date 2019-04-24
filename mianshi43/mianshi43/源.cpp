#include<cstdio>
#include<cstring>//strlenͷ

using namespace std;

int NumberOf1(const char* strN);
int PowerBase10(int n);

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	//sprintf(strN, "%d", n);
	sprintf_s(strN, "%d", n);//�°�����ת�ַ���

	return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
	unsigned int length = strlen(strN);

	if (length == 1)//��һλ�ĵ�������
	{
		if ((*(strN)-'0') >= 1)
			return 1;
		else
			return 0;
	}
	//���ȴ������λ
	int Sum = 0;
	if ((*(strN)-'0') > 1)
	{
		Sum+= PowerBase10(length - 1);//���λ����1�����������1����
	}
	else
	{
		++Sum;
		for (int i = 1; i < length; ++i)//���λ����1����������ں������ĸ����ټ�1
			Sum += (*(strN + i) - '0')*PowerBase10(length - 1 - i);//Ҫ�ǵü�ȥ��0������
	}
	//�������ķ����λ
	for (int i = 1; i < length; ++i)
	{
		int forward_value = 0;//ĳһ�����λ��ǰ��
		int back_value = 0;//ĳһ�����λ�ĺ�

		for (int j = 0; j < i; ++j)
			forward_value += ((*(strN + j) - '0')*PowerBase10(i - j - 1));//ǰ���ж��ٸ�������λ���ж��ٸ�1������
		if ((*(strN + i)-'0') > 1)//�����λ�Լ�����ʹ���1�����ټ�һ������
			++forward_value;
		else if ((*(strN + i) - '0') == 1)//�����λ�Լ��������1�����ټӺ������ĸ����ټ�1
		{
			++back_value;
			for (int k = i+1; k < length; ++k)
				back_value += (*(strN + k) - '0')*PowerBase10(length - 1 - k);
		}
		Sum += forward_value * PowerBase10(length - i - 1)+back_value;
	}
	return Sum;
}

int PowerBase10(int n)
{
	int result = 1;
	while (n >= 1)
	{
		result *= 10;
		--n;
	}
	return result;
}

void Test(const char* testname, int n, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = NumberOf1Between1AndN(n);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");

}

int main()
{
	Test("test1", 1, 1);
	Test("test2", 5, 1);
	Test("test3", 10, 2);
	Test("test4", 55, 16);
	Test("test5", 99, 20);
	Test("test6", 10000, 4001);
	Test("test7", 21345, 18821);
	Test("test8", 0, 0);

	return 0;
}