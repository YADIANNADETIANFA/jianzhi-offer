#pragma once
#include<stack>
#include<cassert>
using namespace std;

template<typename T> class StackWithMin//不得不说，用Tab模板来创建class，挺好使的
{
public:
	StackWithMin();
	~StackWithMin();

	const T& top()const;

	void push(const T& value);//push和pop还是进行改变的，所以后面不能加const

	void pop();

	const T& min() const;

	bool empty() const;

	size_t size() const;

private:
	stack<T> m_data;
	stack<T> m_min;
};

template<typename T> StackWithMin<T>::StackWithMin()
{
}

template<typename T> StackWithMin<T>::~StackWithMin()
{
}

template<typename T> const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template<typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<typename T> void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

template<typename T> const T& StackWithMin<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}

template<typename T> bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template<typename T> size_t StackWithMin<T>::size() const
{
	return m_data.size();
}
