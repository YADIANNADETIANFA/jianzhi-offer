//��������list���������Test("Test6", 4000, 997, 1027);����Ҫ���Լ���������Ҫ���ö࣬������erase��ԭ��
#include<cstdio>
#include<iostream>
#include<list>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		list<int> List;
		for (int i = 0; i < n ; ++i)
		{
			List.push_back(i);
		}

		list<int>::iterator iter= List.begin();

		while (List.size() != 1)
		{
			for (int i = 1; i < m; ++i)
			{
				iter++;
				if (iter == List.end())
					iter = List.begin();

			}
			iter=List.erase(iter);//�����Ķ���Ҫ�ض��������
			if (iter == List.end())//�����ˣ����ָ��end��Ҫ����һ��
				iter = List.begin();
		}
		cout << *(List.begin()) << endl;
	}
	return 0;
}