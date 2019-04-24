#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<exception>

using namespace std;//exception也是需要std的，还有vector
                            //大根堆、最大堆就是一个东西
template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		int Size = max.size() + min.size();
		if ((Size & 1) == 0)//==优先级在&之上！
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);//将数据插入最大堆,插入到末尾
				push_heap(max.begin(), max.end(), less<T>());//要先在容器中加入数据，再调用push_heap ()//重新调整堆序
				num = max[0];//获取最大堆根节点的值
				pop_heap(max.begin(), max.end(), less<T>());//要先调用pop_heap()再在容器中删除数据//取出堆顶元素，放到vector末尾
				max.pop_back();//将末尾元素删除
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else
		{
			if (min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian()
	{
		if ((min.size() + max.size()) == 0)
			throw exception("No number are available\n");
		else if (((min.size() + max.size()) & 1) == 0)
			return (max[0] + min[0]) / 2;
		else
			return min[0];
	}
	//使用vector模拟大顶堆和小顶堆
private:
	vector<T> min;
	vector<T> max;
};

void Test(const char* testname, DynamicArray<double>& numbers, double expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	if (abs(numbers.GetMedian() - expected) < 0.0000001)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	DynamicArray<double> numbers;
	try
	{
		Test("test1", numbers, 0);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");//catch到异常后执行，执行完毕继续执行后面代码，并不调回控制台
	}

	numbers.Insert(5);
	try
	{
		Test("test2", numbers, 5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(2);
	try
	{
		Test("test3", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(3);
	try
	{
		Test("test4", numbers, 3);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(4);
	try
	{
		Test("test5", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(1);
	try
	{
		Test("test6", numbers, 3);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(6);
	try
	{
		Test("test7", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(7);
	try
	{
		Test("test8", numbers, 4);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(0);
	try
	{
		Test("test9", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(8);
	try
	{
		Test("test9", numbers, 4);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	return 0;
}