// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
#include<cstring>
#include<cstdio>

void ChangeBlank(char str[], const int& length)//length是该字符串数组的总容量！
{
	if (str == nullptr || length <= 0)
	{
		return;
	}
	int TheNumofBlank = 0;
	int OriginalLen = 0;
	int NewLen = 0;
	/*char* ch = str;//指针都是地址，int*与char*的区别在于所指向空间占用的大小不同，int*指向空间需要4个字节，char*指向空间需要1个字节
	while (*ch != '\0')
	{
		if (*ch == ' ')
		{
			++TheNumofBlank;
		}
		++ch;
	}*/
	while (str[OriginalLen] != '\0')
	{
		if (str[OriginalLen] == ' ')
		{
			++TheNumofBlank;
		}
		++OriginalLen;
	}
	++OriginalLen;
	NewLen = OriginalLen + 2 * TheNumofBlank;
	if (NewLen > length)
	{
		return;
	}
	while (OriginalLen >= 0 && NewLen > OriginalLen)//不要用遍历法，万一很早前面就没有空格了，那前面不是白遍历了么
	{
		if (str[OriginalLen] != ' ')
		{
			str[NewLen] = str[OriginalLen];
			--NewLen;
			--OriginalLen;
		}
		else
		{
			str[NewLen--] = '0';
			str[NewLen--] = '2';
			str[NewLen--] = '%';
			--OriginalLen;
		}
	}
	return;
}

void Test1()//空格在中间
{
	const int length = 20;
	char string[length] = "We are happy.";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string,length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "We%20are%20happy.")==0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test2()//空格在前端
{
	const int length = 24;
	char string[length] = " We are happy.";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "%20We%20are%20happy.") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test3()//空格在末尾
{
	const int length = 24;
	char string[length] = "We are happy. ";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "We%20are%20happy.%20") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test4()//连续多个空格
{
	const int length = 32;
	char string[length] = "  We are happy. ";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "%20%20We%20are%20happy.%20") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test5()//没有空格
{
	const int length = 32;
	char string[length] = "Wearehappy.";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "Wearehappy.") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}
void Test6()//输入空指针
{
	const int length = 0;
	//char string[] = nullptr;//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(nullptr, length);//change完之后，string怎么还是char[14]呢？！！！！
    printf("Pass!");
}

void Test7()//输入空字符串,即""
{
	const int length = 20;
	char string[length] = "";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test8()//仅输入一个空格
{
	const int length = 20;
	char string[length] = " ";//这里不能用char string[]这种默认长度，这样做的话，string的总容量就固定为14了，而不像我们想的那样可以重新设定length
	ChangeBlank(string, length);//change完之后，string怎么还是char[14]呢？！！！！
	if (strcmp(string, "%20") == 0)//相等返回0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	return 0;
}
