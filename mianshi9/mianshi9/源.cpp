// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
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
