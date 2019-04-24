#include<cstdio>
using namespace std;

int NumberOf1_Solution1(int n)//��nֱ�������ƶ������׳�����ѭ��
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			++count;
		}
		n = n >> 1;
	}
	return count;
}

int NumberOf1_Solution2(int n)//��У��λ�����ƶ���ֱ���ƶ�16������
{
	int count = 0;
	unsigned int check = 1;
	while (check)
	{
		if (n & check)
		{
			++count;
		}
		check = check << 1;
	}
	return count;
}


int NumberOf1_Solution3(int n)//�������ļ�һ�����㣬ѭ����������
{
	int count = 0;
	while (n)
	{
		++count;
		n = ((n - 1)&n);
	}
	return count;
}

/*int NumberOf1_Solution4(int n)//��n�������ֿ����ǣ��������ڷ���2
{
	int count = 0;
	if (n >= 0)
	{
		while (n)
		{
			if (n & 1)
			{
				++count;
			}
			n = n >> 1;
		}
		return count;
	}
	else
	{
		
		int absolute_n = ~n;
		//++count;
		while (absolute_n)
		{
			if (absolute_n & 1)
			{
				++count;
			}
			absolute_n=absolute_n >> 1;
		}
		return count;
	}
}*/

void Test(int number, unsigned int expected)
{
	/*int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);*/

	int actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	actual = NumberOf1_Solution3(number);
	if (actual == expected)
		printf("Solution3: Test for %p passed.\n", number);
	else
		printf("Solution3: Test for %p failed.\n", number);

	/*actual = NumberOf1_Solution4(number);
	if (actual == expected)
		printf("Solution4: Test for %p passed.\n", number);
	else
		printf("Solution4: Test for %p failed.\n", number);*/

	printf("\n");
}

int main(int argc, char* argv[])
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);//��Ȼ��-1��ȴҪ��������1�ĸ���

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);

	return 0;
}



/*#include <stdio.h>
int absolute_value(int num)
{
	if (num < 0)
	{
		num = ~(num - 1);
	}
	return num;
}
int main()
{
	printf("%d\n", absolute_value(5));
	printf("%d\n", absolute_value(-5));
	printf("%d\n", absolute_value(0));
	//return 0;
	int b = -5;
	int c = ~(b);
	printf("%d", c);
	return 0;
}*/





