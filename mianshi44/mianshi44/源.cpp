#include<cstdio>

using namespace std;

int PowerBase10(int n);

int theNumberOfN(int n)
{
	if (n < 0)
		return -1;
	if (n < 10)
		return n;

	int length = 2;
	int forward = 10;
	int Current = 9 + 9 * PowerBase10(length - 1)*length;
	while (n > Current)
	{
		forward += 9 * PowerBase10(length - 1)*length;
		++length;
		Current += 9 * PowerBase10(length - 1)*length;
	}
	//现在  forward<=n<=Current,并且length已知

	int aimNum = PowerBase10(length - 1) + (n-forward)/length;//当前n所指向的int的值
	char* strN = new char[length+1];//别忘了+1，好留给'\0'！！！
	//char strN[50];//浪费空间，不用这个
	sprintf_s(strN, length+1, "%u", aimNum);//同样，别忽略+1；将aimNum转换为字符串，这样好操作一点儿
	char result = *(strN + (n - forward) % length);//找到n所指向的0~9的具体值
	int result_Num;
	sscanf_s(&result, "%u", &result_Num);//将该值从char转换回int；注意！result是char，需要输入的是指针地址，所以参数为&result

	delete[] strN;//别忘了
	return result_Num;
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

void test(const char* testname, int n, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = theNumberOfN(n);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0

	return 0;
}