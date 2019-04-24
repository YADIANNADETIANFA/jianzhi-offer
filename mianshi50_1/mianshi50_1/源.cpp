#include<cstdio>

char FirstShowExistOne(const char* pstring)//ָ����ָ�룬��ָ����Ա仯������ָ��ı������ܱ䣬��Ȼ�ˣ������const�����Ǳ����
{
	if (pstring == nullptr)
		return '\0';

	const int ListSize = 256;
	int* phashlist = new int[ListSize];
	for (int i = 0; i < ListSize; ++i)
		phashlist[i] = 0;

	const char* phashkey = pstring;
	while (*phashkey != '\0')
		phashlist[*(phashkey++)]++;//���ã������ֵط������ǿ���ʹ��++��

	//��ʼ����ɨ����ַ���
	phashkey = pstring;
	while (*phashkey != '\0')
	{
		if (phashlist[*phashkey] == 1)
			return *phashkey;
		else
			phashkey++;
	}
	return '\0';
}

void Test(const char* testname, const char* pstring, char expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);
	char result = FirstShowExistOne(pstring);
	if (result == expected)//��������char����ʹ��==,�Ƚϵ���ASCIIֵ
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	Test("test1", "google", 'l');
	Test("test2", "aabccdbd", '\0');
	Test("test3", "abcdefg", 'a');
	Test("test4", nullptr, '\0');

	return 0;
}