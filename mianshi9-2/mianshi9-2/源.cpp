//用两个队列实现一个栈
#include"Stack.h"

void Test(char actual, CStack<char>& test)
{
	try
	{
		char Tail = test.deleteTail();
		if (actual == Tail)
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
		printf("Stack is empty.\n");
	}
}

int main()
{
	CStack<char> stack;
	stack.addToTail('a');
	stack.addToTail('b');
	stack.addToTail('c');

	Test('c', stack);
	Test('b', stack);

	stack.addToTail('d');
	Test('d', stack);

	stack.addToTail('e');
	Test('e', stack);

	Test('a', stack);

	Test('f', stack);
}
