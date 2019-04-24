//循环从右到左实现，没有重复的翻译
#include<cstdio>
#include<string>//头是没有c的

using namespace std;

int NumOfTranslation(const string& numTostr);

int GetTrans(int number)
{
	if (number < 0)
		return 0;
	string numTostr = to_string(number);
	return NumOfTranslation(numTostr);
}

int NumOfTranslation(const string& numTostr)
{
	int count = 0;
	int length = numTostr.size();
	int* counts = new int[length];
	for (int i = length - 1; i >= 0; --i)
	{
		if (i == length - 1)
			count = 1;
		else
			count = counts[i + 1];//不管两个元素能否结合，他俩都有不结合的权力，也就是说基础值为counts[i + 1]，要是能结合就再额外加

		if (i < length - 1)
		{
			if (i == length - 2)
			{
				if ((numTostr[i] - '0') * 10 + (numTostr[i + 1] - '0') <= 25 && (numTostr[i] - '0') != 0)
					count += 1;//额外加的
			}
			else if ((numTostr[i] - '0') * 10 + (numTostr[i + 1] - '0') <= 25 && (numTostr[i] - '0') != 0)
				count += counts[i + 2];//额外加的
		}
		counts[i] = count;//集中对counts[]的每一个元素赋值
	}
	count = counts[0];
	delete[] counts;
	return count;
}

void Test(const char* testname, int number, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	int result = GetTrans(number);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1", 0, 1);
	Test("test2", 10, 2);
	Test("test3", 125, 3);
	Test("test4", 126, 2);
	Test("test5", 426, 1);
	Test("test6", 100, 2);
	Test("test7", 101, 2);
	Test("test8", 12258, 5);
	Test("test9", -100, 0);

	return 0;
}