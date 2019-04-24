#include<cstring>
#include<cstdio>

void ChangeBlank(char str[], const int& length)//length�Ǹ��ַ����������������
{
	if (str == nullptr || length <= 0)
	{
		return;
	}
	int TheNumofBlank = 0;
	int OriginalLen = 0;
	int NewLen = 0;
	/*char* ch = str;//ָ�붼�ǵ�ַ��int*��char*������������ָ��ռ�ռ�õĴ�С��ͬ��int*ָ��ռ���Ҫ4���ֽڣ�char*ָ��ռ���Ҫ1���ֽ�
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
	while (OriginalLen >= 0 && NewLen > OriginalLen)//��Ҫ�ñ���������һ����ǰ���û�пո��ˣ���ǰ�治�ǰױ�����ô
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

void Test1()//�ո����м�
{
	const int length = 20;
	char string[length] = "We are happy.";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string,length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "We%20are%20happy.")==0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test2()//�ո���ǰ��
{
	const int length = 24;
	char string[length] = " We are happy.";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "%20We%20are%20happy.") == 0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test3()//�ո���ĩβ
{
	const int length = 24;
	char string[length] = "We are happy. ";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "We%20are%20happy.%20") == 0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test4()//��������ո�
{
	const int length = 32;
	char string[length] = "  We are happy. ";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "%20%20We%20are%20happy.%20") == 0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test5()//û�пո�
{
	const int length = 32;
	char string[length] = "Wearehappy.";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "Wearehappy.") == 0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}
void Test6()//�����ָ��
{
	const int length = 0;
	//char string[] = nullptr;//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(nullptr, length);//change��֮��string��ô����char[14]�أ���������
    printf("Pass!");
}

void Test7()//������ַ���,��""
{
	const int length = 20;
	char string[length] = "";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "") == 0)//��ȷ���0
	{
		printf("Pass!");
	}
	else
	{
		printf("Fail!");
	}
}

void Test8()//������һ���ո�
{
	const int length = 20;
	char string[length] = " ";//���ﲻ����char string[]����Ĭ�ϳ��ȣ��������Ļ���string���������͹̶�Ϊ14�ˣ���������������������������趨length
	ChangeBlank(string, length);//change��֮��string��ô����char[14]�أ���������
	if (strcmp(string, "%20") == 0)//��ȷ���0
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