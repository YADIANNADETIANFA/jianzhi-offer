//�����麯��
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
	virtual unsigned int Sum(int n)//�麯��Ҫ���������������ͣ�������������������ͬ���������Բ���A����virtual unsigned int Sum(int n)����B����virtual unsigned int Sum(unsigned int n),�����Ļ�������ֶ�̬���ˣ�ֻ��һֱִ��A��
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