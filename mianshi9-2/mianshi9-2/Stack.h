#pragma once
#include<vector>//使用双端队列就没有意义了
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
	}//不存在两个容器均非空的情况
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
			T data = *(vector1.begin());//我们尝试一次引用，而非下标运算符和at  //和面试9.1不一样，这里的T可不能用&引用
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
			T data = *(vector2.begin());//同上
			vector2.erase(vector2.begin());
			vector1.push_back(data);
		}
		T Tail = *(vector2.end() - 1);
		vector2.erase(vector2.end() - 1);
		return Tail;
	}
}