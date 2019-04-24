#include<cstdio>

void Insert(int A1[], int A2[], int length,int length1,int length2)//length为A1的总容量,length1和length2分别是A1和A2目前元素的数目
{
	if (A1 == nullptr || A2 == nullptr || length <(length1+length2))
	{
		return;
	}
	int final_pos = length1 + length2 - 1;
	int A1_pos = length1 - 1;
	int A2_pos = length2 - 1;
	while (A2_pos >= 0)//A2遍历完之后，就没有继续遍历A1的必要的，这样能节省时间
	{
		if (A1[A1_pos] >= A2[A2_pos])
		{
			A1[final_pos--] = A1[A1_pos--];
		}
		else
		{
			A1[final_pos--] = A2[A2_pos--];
		}
	}

}

void Test1()//A1全部小于A2
{
	int A1[15] = { 1,2,3,4,5 };
	int A2[4] = { 6,7,8,9 };
	Insert(A1, A2, 15, 5, 4);
	int result[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 15; i++)
	{
		if (A1[i] != result[i])
		{
			printf("Fail.");
			return;
		}
	}
	printf("Pass.");
}

void Test2()//A1和A2有大有小
{
	int A1[15] = { 1,3,5,7,9 };
	int A2[4] = { 2,4,6,8 };
	Insert(A1, A2, 15, 5, 4);
	int result[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 15; i++)
	{
		if (A1[i] != result[i])
		{
			printf("Fail.");
			return;
		}
	}
	printf("Pass.");
}

void Test3()//A2全都小于A1
{
	int A1[15] = { 5,6,7,8,9 };
	int A2[4] = { 1,2,3,4 };
	Insert(A1, A2, 15, 5, 4);
	int result[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 15; i++)
	{
		if (A1[i] != result[i])
		{
			printf("Fail.");
			return;
		}
	}
	printf("Pass.");
}

void Test4()//存在空指针
{
	//int A1[1] = nullptr;
	int A2[4] = { 1,2,3,4 };
	Insert(nullptr, A2, 0, 0, 4);
	printf("Pass.");
}

void Test5()//A1总容量不足
{
	int A1[6] = { 1,2,3,4,5 };
	int A2[4] = { 6,7,8,9 };
	Insert(A1, A2, 6, 5, 4);
	int result[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if ((sizeof(A1) / sizeof(int)) > 9)
	{
		for (int i = 0; i < 15; i++)
		{
			if (A1[i] != result[i])
			{
				printf("Fail.");
				return;
			}
		}
		printf("Pass.");
		return;
	}
	printf("Fail,not enough space.");
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}