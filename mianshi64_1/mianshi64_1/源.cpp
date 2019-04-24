//构造函数法
#include<cstdio>
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		N++;
		Sum += N;
	}
	static void Reset()
	{
		N = 0;
		Sum = 0;
	}
	static unsigned int GetSum()
	{
		return Sum;
	}
	~A() 
	{
	}
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int A::N = 0;
unsigned int A::Sum = 0;

unsigned int Sum_solution(unsigned int n)
{
	A::Reset();
	A* num = new A[n];

	delete []num;
	num = nullptr;

	return A::GetSum();
}

int main()
{
	unsigned int n;
	while (cin >> n)
	{
		cout << Sum_solution(n) << endl;
	}
	return 0;
}