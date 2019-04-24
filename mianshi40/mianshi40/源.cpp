#include<cstdio>
#include<vector>
#include<set>//multiset头
#include<functional>//greater头
#include<cstdlib>//rand,srand头
#include<ctime>//time头

using namespace std;

int Partition(int* numbers, int length, int start, int end);
int RandomInRange(int start, int end);
void Swap(int* data1, int* data2);

typedef multiset<int, greater<int>> inSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers1(int* input, int* output, int k, int length)
{
	if (input == nullptr || length <= 0 || k <= 0 || output == nullptr || k > length)
		return;

	int start = 0;
	int end = length - 1;
	int index = Partition(input, length, start, end);

	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, length, start, end);
		}
	}

	for (int i = 0; i < k; ++i)
		output[i] = input[i];
}

int Partition(int* numbers, int length, int start, int end)
{
	if (numbers == nullptr || length <= 0 || start < 0 || end >= length)
		return 0;

	int index = RandomInRange(start, end);
	Swap(&numbers[index], &numbers[end]);
	int small = start-1;

	for (index = start; index < end; ++index)
	{
		if (numbers[index] < numbers[end])
		{
			++small;
			if (small != index)
				Swap(&numbers[small], &numbers[index]);
		}
	}
	++small;
	Swap(&numbers[small], &numbers[end]);
	return small;
}

void Swap(int* data1, int* data2)
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

int RandomInRange(int start, int end)
{
	if (start < end)
	{
		srand(time(NULL));
		return start + rand() % (end + 1 - start);
	}
	return start;
}


void GetLeastNumber2(const vector<int>& data, inSet& leastNumbers, int k)
{
	leastNumbers.clear();
	if (data.size() <= 0 || k <= 0)
		return;

	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter)
	{
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else 
		{
			setIterator iterGreatest = leastNumbers.begin();
			if (*iter < *iterGreatest)
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

void Test(const char* testname, int* numbers, int length, int k,bool HasResult)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	vector<int> numbers2;//方法2的原始容器
	if (numbers != nullptr)
	{
		for (int i = 0; i < length; ++i)
			numbers2.push_back(numbers[i]);
	}

	inSet leastNumbers;
	
	printf("Solution1:\n");
	if (HasResult)
	{
		int* output = new int[k];
		GetLeastNumbers1(numbers, output, k, length);
		for (int i = 0; i < k; ++i)
		{
			printf("%d\t", output[i]);
		}
		printf("\n");
		delete[] output;
	}
	else
	{
		int* output = new int[k];
		GetLeastNumbers1(numbers, output, k, length);
		delete[] output;
		printf("We dont except any result.\n");
	}

	printf("Solution2:\n");
	if (HasResult)
	{
		GetLeastNumber2(numbers2, leastNumbers, k);
		for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
			printf("%d\t", *iter);
		printf("\n");
	}
	else
	{
		GetLeastNumber2(numbers2, leastNumbers, k);
		printf("We dont except any result.\n");
	}

}

void test1()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), 4, true);
}

void test2()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("test2", numbers, sizeof(numbers) / sizeof(int), 8, true);
}

void test3()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("test3", numbers, sizeof(numbers) / sizeof(int), 9, false);
}

void test4()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("test4", numbers, sizeof(numbers) / sizeof(int), 1, true);
}

void test5()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Test("test5", numbers, sizeof(numbers) / sizeof(int), 0, false);
}

void test6()
{
	int numbers[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
	Test("test6", numbers, sizeof(numbers) / sizeof(int), 2, true);
}

void test7()
{
	Test("test7", nullptr, 0, 0, false);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}