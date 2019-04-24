#include<cstdio>

using namespace std;

int PowerBase10(int n);

int theNumberOfN(int n)
{
	if (n < 0)
		return -1;
	if (n < 10)
		return n;

	int length = 2;
	int forward = 10;
	int Current = 9 + 9 * PowerBase10(length - 1)*length;
	while (n > Current)
	{
		forward += 9 * PowerBase10(length - 1)*length;
		++length;
		Current += 9 * PowerBase10(length - 1)*length;
	}
	//����  forward<=n<=Current,����length��֪

	int aimNum = PowerBase10(length - 1) + (n-forward)/length;//��ǰn��ָ���int��ֵ
	char* strN = new char[length+1];//������+1��������'\0'������
	//char strN[50];//�˷ѿռ䣬�������
	sprintf_s(strN, length+1, "%u", aimNum);//ͬ���������+1����aimNumת��Ϊ�ַ����������ò���һ���
	char result = *(strN + (n - forward) % length);//�ҵ�n��ָ���0~9�ľ���ֵ
	int result_Num;
	sscanf_s(&result, "%u", &result_Num);//����ֵ��charת����int��ע�⣡result��char����Ҫ�������ָ���ַ�����Բ���Ϊ&result

	delete[] strN;//������
	return result_Num;
}

int PowerBase10(int n)
{
	int result = 1;
	while (n >= 1)
	{
		result *= 10;
		--n;
	}
	return result;
}

void test(const char* testname, int n, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	int result = theNumberOfN(n);
	if (result == expected)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // ����99�����һλ��9
	test("Test6", 190, 1);  // ����100�ĵ�һλ��1
	test("Test7", 1000, 3); // ����370�ĵ�һλ��3
	test("Test8", 1001, 7); // ����370�ĵڶ�λ��7
	test("Test9", 1002, 0); // ����370�ĵ���λ��0

	return 0;
}