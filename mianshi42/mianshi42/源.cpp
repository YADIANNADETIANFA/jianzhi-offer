#include<cstdio>
#include<vector>

using namespace std;
//������vector���������Ը��õ��������ݣ�
//���ǻ�����һЩ�޸ģ�����������ӡ�˳�����
int FindGreatestSumOfSubArray(const vector<int>& numbers, vector<int>::const_iterator& ihead, vector<int>::const_iterator& itail)//ע��һ�£�������Ҳ�ǿ������õ�
{                                                                       //ihead��itail�ֱ�����������ǰ����������ָ��      
	if (numbers.size() <= 0)
		throw exception("Invalid Input\n");

	int CurSum = 0;//��ǰ�Ӻ�
	int CurMax = 0;//��ǰ���ֵ
	vector<int>::const_iterator iter = numbers.begin();

	for (; iter != numbers.end(); ++iter)
	{
		if ((*iter + CurSum) < (*iter) && (CurMax < *iter))//��һֵ֮������ǰ��һ����ֵ�ĺͣ�������CurSum��CurMax��ihead��itail��������ǰ�����һ����ֵ
		{
			CurSum = *iter;
			CurMax = *iter;
			ihead = iter;
			(itail-1) = iter;
			continue;
		}

		CurSum = *iter + CurSum;
		if (CurSum > CurMax)
		{
			CurMax = CurSum;
			(itail-1) = iter;//������ȥ��λitail
		}
	}

	if (CurMax == 0)//����˵��һ�£�FindGreatestSumOfSubArrayδ��ihead��itail���и�ֵֻ�����������һ������������Ϊ�գ�������ùܣ�ֱ��throw��ȥ�ˣ�û�к�����ִ�У���һ��������������Ϊȫ����
		ihead = numbers.end();//�ڵڶ����������Ȼ��֪������ȫ������ֱ�ӾͰ�ihead = numbers.end()�������⿼������������

	return CurMax;
}

void Test(const char* testname, const vector<int> numbers, int expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	try
	{
		vector<int>::const_iterator ihead = numbers.begin();//���FindGreatestSumOfSubArrayδ�����������������гɹ���ֵ����ô������Ҫ�и���ʼ��ָ��
		vector<int>::const_iterator itail = numbers.end();

		int result = FindGreatestSumOfSubArray(numbers,ihead,itail);//���������������Ҳ����Ҫ���ã����������������Ժ�ihead��itail����������ĸ�ֵ״̬
		printf("The Max_value is:%d\n", result);                    //��򵥵�C++������Ϊ�����ò�������ihead��itail�Ŀ��������˺�����ÿ��������������Ա�������
		printf("The Max Array is:\n");
		vector<int>::const_iterator iter2 = ihead;
		for (; iter2 != itail ; ++iter2)
		{
			printf("%d\t", *iter2);
		}
		printf("\n");
	}
	catch (exception& e)
	{
		printf("Invalid Input.\n");
	}
}

void test1()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(-2);
	numbers.push_back(3);
	numbers.push_back(10);
	numbers.push_back(-4);
	numbers.push_back(7);
	numbers.push_back(2);
	numbers.push_back(-5);

	Test("test1", numbers, 18);
}

void test2()
{
	vector<int> numbers;
	numbers.push_back(-2);
	numbers.push_back(-8);
	numbers.push_back(-1);
	numbers.push_back(-5);
	numbers.push_back(-9);

	Test("test2", numbers, 0);
}

void test3()
{
	vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(9);

	Test("test3", numbers, 25);
}

void test4()
{
	vector<int> numbers;

	Test("test4", numbers, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}