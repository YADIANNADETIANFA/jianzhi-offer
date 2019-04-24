#include<cstdio>

bool hasPathCore(const char*, int, int, int, int, const char*, bool*, int&);
bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == nullptr || str == nullptr || rows <= 0 || cols <= 0)
	{
		return false;
	}
	bool* visited = new bool[rows*cols];
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			visited[(i - 1)*cols+ j-1] = false;
		}
	}

	int PathLength = 0;
	for (int row = 1; row <= rows; ++row)
	{
		for (int col = 1; col <= cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, visited,PathLength))
			{
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, bool* visited, int& PathLength)
{
	if (str[PathLength] == '\0')
		return true;
	
	bool hasPath = false;
	if (row > 0 && row <= rows && col > 0 && col <= cols && matrix[(row - 1)*cols + col-1] == str[PathLength] && visited[(row - 1)*cols + col-1] == false)
	{
		++PathLength;
		visited[(row - 1)*cols + col-1] = true;
		hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, visited, PathLength) \
			|| hasPathCore(matrix, rows, cols, row, col - 1, str, visited, PathLength)\
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, visited, PathLength)\
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, visited, PathLength);
		if (hasPath != true)
		{
			--PathLength;
			visited[(row - 1)*cols + col-1] = false;
		}
	}
	return hasPath;
}

void Test(const char* testname, const char* matrix, int rows, int cols, const char* str, bool expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Pass.\n");
	else
		printf("Fail.\n");
}

void Test1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";
	Test("Test1", matrix, 3, 4, str, true);
}

void Test2()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	Test("Test2", (const char*)matrix, 3, 4, str, false);
}

void Test3()
{
	const char* matrix = "A";
	const char* str = "A";

	Test("Test3", (const char*)matrix, 1, 1, str, true);
}

void Test4()
{
	Test("Test4", nullptr, 0, 0, nullptr, false);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;

}

