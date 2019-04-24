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
	//Ҫôû���ظ�ֵ����ʱ���м�ֵ�ɹ���ԣ�����false��Ҫô���ظ�ֵ����ʱ���ٴ���һ����ֵ���޷���Գɹ�������true
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