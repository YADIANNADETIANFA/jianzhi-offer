#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (n < 1 || m < 1)
		{
			cout << -1 << endl;//����Ҫдcout<<-1<<endl;  Ҫ��return -1�Ļ���������whileѭ���ˣ�cin��û����
			continue;
		}
		int last = 0;
		
		for (int i = 2; i <= n; ++i)
			last = (last + m) % i;
		cout << last << endl;
	}
	return 0;
}