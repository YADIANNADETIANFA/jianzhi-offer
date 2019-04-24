#pragma once
#include<vector>//ʹ��˫�˶��о�û��������
#include<exception>
using namespace std;

template<typename T> class CStack
{
public:
	CStack();
	~CStack();

	void addToTail(const T& data);
	T deleteTail();
private:
	vector<T> vector1;
	vector<T> vector2;
};

template<typename T> CStack<T>::CStack()
{

}

template<typename T> CStack<T>::~CStack()
{

}

template<typename T> void CStack<T>::addToTail(const T& data)
{
	if (vector1.size() == 0 && vector2.size() == 0)
	{
		vector1.push_back(data);
	}
	else if (vector1.size() == 0)
	{
		vector2.push_back(data);
	}
	else
	{
		vector1.push_back(data);
	}//�����������������ǿյ����
}

template<typename T> T CStack<T>::deleteTail()
{
	if (vector1.size() == 0 && vector2.size() == 0)
	{
		throw exception("Stack is empty.\n");
	}
	else if (vector1.size() != 0)
	{
		while (vector1.begin() != (vector1.end()-1))
		{
			T data = *(vector1.begin());//���ǳ���һ�����ã������±��������at  //������9.1��һ���������T�ɲ�����&����
			vector1.erase(vector1.begin());
			vector2.push_back(data);
		}
		T Tail = *(vector1.end() - 1);
		vector1.erase(vector1.end() - 1);
		return Tail;
	}
	else
	{
		while (vector2.begin() != (vector2.end() - 1))
		{
			T data = *(vector2.begin());//ͬ��
			vector2.erase(vector2.begin());
			vector1.push_back(data);
		}
		T Tail = *(vector2.end() - 1);
		vector2.erase(vector2.end() - 1);
		return Tail;
	}
}