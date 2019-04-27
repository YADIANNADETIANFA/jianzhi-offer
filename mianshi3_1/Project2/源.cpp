// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
#include<cstdio>
bool FindTheSame(int a[], int length, int* thevalue)
{
	if (a == nullptr || length<=0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (a[i] >= length || a[i] < 0)
		{
			return false;
		}
	}
	//要么没有重复值，这时所有键值成功配对，返回false；要么有重复值，这时至少存在一个键值对无法配对成功，返回true
	for (int i = 0; i < length; ++i)
	{
		while (i != a[i])
		{
			if (a[i] == a[a[i]])
			{
				*thevalue = a[i];
				return true;
			}
			int temp = a[i];
			a[i] = a[temp];
			a[temp] = temp;
			//a[i] = a[a[i]];
			//a[a[i]] = temp;
			//printf("%u", a[i]);
		}
	}
	return false;
}

void test()
{
	int num[6]= { 2,1,0,3,4,5 };
	int pvalue = 0;
	int len = 6;
	if (FindTheSame(num,len,&pvalue))
	{
		printf("Pass.");
	}
	else
	{
		printf("Not Pass.");
	}

}

int main()
{
	test();
	return 0;

}
