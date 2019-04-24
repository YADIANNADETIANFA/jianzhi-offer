#include<cstdio>
#include<limits>

using namespace std;

class CharOperation
{
public:
	CharOperation() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			charIndex[i] = -1;
	}

	void Insert(char ch)
	{
		if (charIndex[ch] == -1)
			charIndex[ch] = index;
		else if (charIndex[ch] >= 0)
			charIndex[ch] = -2;

		++index;
	}

	char FindFirstShow()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();//��Ҫlimits��ͷ�� 
		                                          //numeric_limits<double>::max () �Ǻ��������ر���������� double ���� ���ֵ��
			                                      //���Ƶ� numeric_limits<int>::max()  ���� ����������� int ���� ���ֵ��
			                                      //�����ͷ�ļ�  #include <limits>
		for (int i = 0; i < 256; ++i)
		{
			if (charIndex[i] >= 0 && charIndex[i] <= minIndex)
			{
				ch = (char)i;
				minIndex = charIndex[i];
			}
		}
		return ch;
	}
private:
	int index;
	int charIndex[256];
};

void Test(const char* testname, CharOperation Charstream, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	char result = Charstream.FindFirstShow();
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	CharOperation Charstream;

	Charstream.Insert('g');
	Test("test1", Charstream,  'g');

	Charstream.Insert('o');
	Test("test2", Charstream,  'g');

	Charstream.Insert('o');
	Test("test3", Charstream,  'g');

	Charstream.Insert('g');
	Test("test4", Charstream,  '\0');

	Charstream.Insert('l');
	Test("test5", Charstream,  'l');

	Charstream.Insert('e');
	Test("test6", Charstream,  'l');

	return 0;
}

/*void Test(const char* testname, CharOperation Charstream,char input, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

    Charstream.Insert(input);

	char result = Charstream.FindFirstShow();
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()//��Test����ʵ��Insert�������Ķ�����Charstream�Ŀ���������Test������ÿ�����ʧ��ԭCharstream��δ�����ı䣬����������Զֻ����һ���ַ���
{
	CharOperation Charstream;

	
	Test("test1", Charstream,'g', 'g');

	
	Test("test2", Charstream,'o', 'g');

	
	Test("test3", Charstream,'o', 'g');

	
	Test("test4", Charstream,'g', '\0');

	
	Test("test5", Charstream,'l', 'l');

	
	Test("test6", Charstream,'e', 'l');

	return 0;
}*/