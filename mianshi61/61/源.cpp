#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	while (true)
	{
		vector<int> A(14, 0);
		bool jixu = true;
		for (int i = 0; i < 5; ++i)
		{
			int temp;
			cin >> temp;
			if (temp != 0 && A[temp] != 0)//һ�����ֳ�����2�μ����ϣ�ֱ�Ӳ�����˳��
			{
				jixu = false;
				cout << "false" << endl;
				break;
			}
			else if (temp == 0 && A[temp] >= 2)//���ܳ���3������
			{
				jixu = false;
				cout << "false" << endl;
				break;
			}
			else
			{
				++A[temp];
			}
		}
		if (jixu)
		{
			vector<int>::iterator iter1 = A.begin() + 1;
			vector<int>::iterator iter2 = A.end()-1;

			while (iter1!=A.end() && *iter1 == 0)//�ҳ��������⣬��С����ֵ
			{
				iter1++;
			}

			while (iter2 != A.begin() && *iter2 == 0)//��������ֵ
			{
				--iter2;
			}
			int dis = iter2 - iter1 + 1;//��С�����ֵ���Ƕ���
			if (dis==5)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
	}
	return 0;
}