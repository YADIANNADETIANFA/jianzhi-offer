// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#include<cstdio>

int numOfBlockCore(int, int, int, int, int, bool*);
bool check(int, int, int, int, int, bool*);
int getSum(int);
int numOfBlock(int rows, int cols, int threshold)//row表示第几行（0~rows-1），rows表示一共有几行
{
	if (rows <= 0 || cols <= 0 || threshold < 0)
		return 0;
	int row = 0;
	int col = 0;
	bool* visited = new bool[rows*cols];//这里是visited有多少个元素，不要rows*cols-1！！不要减一
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			visited[i*cols + j] = false;
		}
	}
	int count = numOfBlockCore(rows, cols, row, col, threshold, visited);
	delete[] visited;
	return count;
}

int numOfBlockCore(int rows, int cols, int row, int col, int threshold, bool* visited)
{
	int num = 0;
	if (check(rows, cols, row, col, threshold, visited))
	{
		visited[row*cols + col] = true;
		num = 1 + numOfBlockCore(rows, cols, row - 1, col, threshold, visited) + \
			numOfBlockCore(rows, cols, row, col - 1, threshold, visited) + \
			numOfBlockCore(rows, cols, row + 1, col, threshold, visited) + \
			numOfBlockCore(rows, cols, row, col + 1, threshold, visited);
	}
	return num;
}

bool check(int rows, int cols, int row, int col, int threshold, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && getSum(row) + getSum(col) <= threshold && visited[row*cols + col] == false)
	{
		return true;
	}
	return false;
}

int getSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}

void Test(const char* testname,int rows, int cols, int threshold, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = numOfBlock(rows, cols, threshold);
	if (result == expected)
		printf("Pass.\n");
	else
		printf("Fail.\n");

}

int main()
{
	Test("test1", 1, 1, 0, 1);
	Test("test2", 3, 3, 4, 9);
	Test("test3", -1, 1, 0, 0);
	Test("test4", 10, 10, 5, 21);
	Test("test5", 20, 20, 15, 359);
	Test("test6", 10, 10, -1, 0);
	Test("test7", 10, 1, 15, 10);
}
