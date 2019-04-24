#include<cstdio>
#include<queue>
#include<exception>

using namespace std;

template<typename T>class QueueWithMax
{
public:
	QueueWithMax() :currentIndex(0)
	{

	}

	void push_back(T number)
	{
		while (!maxIndex.empty() && maxIndex.back().num <= number)
			maxIndex.pop_back();
		InternalData internalData{ number, currentIndex };
		maxIndex.push_back(internalData);
		data.push_back(internalData);
		++currentIndex;
	}

	void pop_front()
	{
		if (data.empty())
			throw exception("queue is empty.");
		if (data.front().index == maxIndex.front().index)
			maxIndex.pop_front();
		data.pop_front();
	}

	T max()
	{
		if (maxIndex.empty())
			throw exception("queue is empty.");
		return maxIndex.front().num;
	}

private:
	struct InternalData//结构体学习一下
	{
		T num;
		int index;
	};
	deque<InternalData>data;
	deque<InternalData>maxIndex;
	int currentIndex;
};

void Test(const char* testname, QueueWithMax<int>& queue, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	if (queue.max() == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	QueueWithMax<int> queue;
	queue.push_back(2);
	Test("test1", queue, 2);

	queue.push_back(3);
	Test("test2", queue, 3);

	queue.push_back(4);
	Test("test3", queue, 4);

	queue.push_back(2);
	Test("test4", queue, 4);

	queue.pop_front();
	Test("test5", queue, 4);

	queue.pop_front();
	Test("test6", queue, 4);

	queue.pop_front();
	Test("test7", queue, 2);

	queue.push_back(6);
	Test("test8", queue, 6);

	queue.push_back(2);
	Test("test9", queue, 6);

	queue.push_back(5);
	Test("test10", queue, 6);

	queue.push_back(5);
	Test("test11", queue, 6);

	queue.pop_front();
	Test("test12", queue, 6);

	queue.pop_front();
	Test("test13", queue, 5);

	queue.push_back(1);
	Test("test14", queue, 5);

	return 0;
}