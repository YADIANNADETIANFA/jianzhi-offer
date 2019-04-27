// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
#include<cstdio>

bool Find(int* matrix, int rows, int columns, int number)
{
	bool Found = false;
	if (matrix == nullptr || rows < 1 || columns < 1)
	{
		return false;
	}
	int position_x = columns - 1;
	int position_y = 0;
	while (position_x >= 0 && position_y <= (rows - 1))
	{
		int compare = matrix[position_x + position_y * columns];
		if (number==compare)
		{
			return true;
		}
		if (number > compare)
		{
			++position_y;
		}
		if (number < compare)
		{
			--position_x;
		}
	}
	return false;
}

void Test1()
{
	int a[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int search = 80;
	if (Find((int*)a, 4, 4, search))//强制类型转换，将a转换为int类型的指针
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test2()
{
	int*a = nullptr;
	int search = 13;
	if (Find((int*)a, 4, 4, search))//强制类型转换，将a转换为int类型的指针
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}

}

void Test3()
{
	int a[] = { 1,2,3 };
	int b[] = { 1,2,3 };
	if (a == b)
	{
		printf("True!");
	}
	else
	{
		printf("False!");
	}
}

void Test4()
{
	//除了char* a = "123";不行，下面这两种强制转换倒是都行。。。
	char* a = (char*)"123";
	const char* b = "123";
	if (a == b)
	{
		printf("True!");
	}
	else
	{
		printf("False!");
	}
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}
