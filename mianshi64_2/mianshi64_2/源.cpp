// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。
//利用虚函数
#include<cstdio>
#include<iostream>
using namespace std;

class A;
A*Array[2];

class A
{
public:
	virtual unsigned int Sum(int n)
	{
		return 0;
	}
};

class B:public A
{
public:
	virtual unsigned int Sum(int n)//虚函数要两个函数返回类型，函数名，参数类型相同。。。所以不能A中是virtual unsigned int Sum(int n)；而B中是virtual unsigned int Sum(unsigned int n),这样的话不会出现多态性了！只会一直执行A的
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

unsigned int Solution_2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	return Array[1]->Sum(n);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Solution_2(n) << endl;
	}
	return 0;
}
