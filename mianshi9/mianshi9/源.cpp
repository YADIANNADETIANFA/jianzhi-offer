#include"Queue.h"

void Test(char actual,CQueue<char>& test)//类这里要引用，不然拷贝的东西是无法对类对象本身进行操作的
{
	try
	{
		char head = test.deleteHead();
		if (actual == head)
		{
			printf("Test sucess.\n");
		}
		else
		{
			printf("Test fail.\n");
		}
	}
	catch (exception& e)
	{
		printf("queue is empty.\n");
	}
}

int main()
{
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	//char head = queue.deleteHead();
	Test('a', queue);

	//head = queue.deleteHead();
	Test('b', queue);

	queue.appendTail('d');
	//head = queue.deleteHead();
	Test('c', queue);

	queue.appendTail('e');
	//head = queue.deleteHead();
	Test('d', queue);

	//head = queue.deleteHead();
	Test('e', queue);

	//head = queue.deleteHead();
	Test('f', queue);
	return 0;
}