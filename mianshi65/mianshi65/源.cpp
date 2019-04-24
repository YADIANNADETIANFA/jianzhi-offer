//λ����
#include<cstdio>
#include<iostream>
using namespace std;

int GetSum(int num1, int num2)//������������0������
{
	int sum_without_jinwei = 0;
	int jinwei = 0;
	do
	{
		sum_without_jinwei = num1 ^ num2;
		jinwei = (num1&num2) << 1;
		num1 = sum_without_jinwei;
		num2 = jinwei;
	} while (num2 != 0);//�зֺ�

	return sum_without_jinwei;
}

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		cout << GetSum(num1, num2) << endl;
	}
	return 0;
}