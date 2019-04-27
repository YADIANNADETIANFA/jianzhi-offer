// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
#include<cstdio>
#include<vector>

using namespace std;
//我们用vector容器，可以更好地增减数据；
//我们还做了一些修改，将最大数组打印了出来；
int FindGreatestSumOfSubArray(const vector<int>& numbers, vector<int>::const_iterator& ihead, vector<int>::const_iterator& itail)//注意一下，迭代器也是可以引用的
{                                                                       //ihead和itail分别是最大数组的前后两迭代器指针      
	if (numbers.size() <= 0)
		throw exception("Invalid Input\n");

	int CurSum = 0;//当前加和
	int CurMax = 0;//当前最大值
	vector<int>::const_iterator iter = numbers.begin();

	for (; iter != numbers.end(); ++iter)
	{
		if ((*iter + CurSum) < (*iter) && (CurMax < *iter))//以一值之力大于前面一大组值的和，则修正CurSum与CurMax，ihead与itail，并放弃前面的那一大组值
		{
			CurSum = *iter;
			CurMax = *iter;
			ihead = iter;
			(itail-1) = iter;
			continue;
		}

		CurSum = *iter + CurSum;
		if (CurSum > CurMax)
		{
			CurMax = CurSum;
			(itail-1) = iter;//正常的去定位itail
		}
	}

	if (CurMax == 0)//这里说明一下，FindGreatestSumOfSubArray未对ihead和itail进行赋值只有两种情况，一个是输入数组为空，这个不用管，直接throw出去了，没有后续的执行；另一个就是输入数组为全负，
		ihead = numbers.end();//在第二种情况，既然已知了数组全负，那直接就把ihead = numbers.end()，即特殊考虑这个情况即可

	return CurMax;
}

void Test(const char* testname, const vector<int> numbers, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	try
	{
		vector<int>::const_iterator ihead = numbers.begin();//如果FindGreatestSumOfSubArray未对这两个迭代器进行成功赋值，那么他俩总要有个初始的指向
		vector<int>::const_iterator itail = numbers.end();

		int result = FindGreatestSumOfSubArray(numbers,ihead,itail);//并且这里面迭代器也必须要引用，否则出了这个函数以后，ihead和itail依旧是最初的赋值状态
		printf("The Max_value is:%d\n", result);                    //最简单的C++规则，因为非引用操作的是ihead和itail的拷贝，出了函数体该拷贝被丢弃，所以必用引用
		printf("The Max Array is:\n");
		vector<int>::const_iterator iter2 = ihead;
		for (; iter2 != itail ; ++iter2)
		{
			printf("%d\t", *iter2);
		}
		printf("\n");
	}
	catch (exception& e)
	{
		printf("Invalid Input.\n");
	}
}

void test1()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(-2);
	numbers.push_back(3);
	numbers.push_back(10);
	numbers.push_back(-4);
	numbers.push_back(7);
	numbers.push_back(2);
	numbers.push_back(-5);

	Test("test1", numbers, 18);
}

void test2()
{
	vector<int> numbers;
	numbers.push_back(-2);
	numbers.push_back(-8);
	numbers.push_back(-1);
	numbers.push_back(-5);
	numbers.push_back(-9);

	Test("test2", numbers, 0);
}

void test3()
{
	vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(9);

	Test("test3", numbers, 25);
}

void test4()
{
	vector<int> numbers;

	Test("test4", numbers, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
