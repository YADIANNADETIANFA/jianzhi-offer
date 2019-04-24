#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<exception>

using namespace std;//exceptionҲ����Ҫstd�ģ�����vector
                            //����ѡ����Ѿ���һ������
template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		int Size = max.size() + min.size();
		if ((Size & 1) == 0)//==���ȼ���&֮�ϣ�
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);//�����ݲ�������,���뵽ĩβ
				push_heap(max.begin(), max.end(), less<T>());//Ҫ���������м������ݣ��ٵ���push_heap ()//���µ�������
				num = max[0];//��ȡ���Ѹ��ڵ��ֵ
				pop_heap(max.begin(), max.end(), less<T>());//Ҫ�ȵ���pop_heap()����������ɾ������//ȡ���Ѷ�Ԫ�أ��ŵ�vectorĩβ
				max.pop_back();//��ĩβԪ��ɾ��
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else
		{
			if (min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian()
	{
		if ((min.size() + max.size()) == 0)
			throw exception("No number are available\n");
		else if (((min.size() + max.size()) & 1) == 0)
			return (max[0] + min[0]) / 2;
		else
			return min[0];
	}
	//ʹ��vectorģ��󶥶Ѻ�С����
private:
	vector<T> min;
	vector<T> max;
};

void Test(const char* testname, DynamicArray<double>& numbers, double expected)
{
	if (testname != nullptr)
		printf("%s begin:\n", testname);

	if (abs(numbers.GetMedian() - expected) < 0.0000001)
		printf("Pass\n");
	else
		printf("Fail\n");
}

int main()
{
	DynamicArray<double> numbers;
	try
	{
		Test("test1", numbers, 0);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");//catch���쳣��ִ�У�ִ����ϼ���ִ�к�����룬�������ؿ���̨
	}

	numbers.Insert(5);
	try
	{
		Test("test2", numbers, 5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(2);
	try
	{
		Test("test3", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(3);
	try
	{
		Test("test4", numbers, 3);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(4);
	try
	{
		Test("test5", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(1);
	try
	{
		Test("test6", numbers, 3);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(6);
	try
	{
		Test("test7", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(7);
	try
	{
		Test("test8", numbers, 4);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(0);
	try
	{
		Test("test9", numbers, 3.5);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	numbers.Insert(8);
	try
	{
		Test("test9", numbers, 4);
	}
	catch (exception& e)
	{
		printf("No numbers are available\n");
	}

	return 0;
}