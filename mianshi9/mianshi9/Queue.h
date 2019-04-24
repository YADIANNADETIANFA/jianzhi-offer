#pragma once
#include<stack>
#include<exception>
using namespace std;

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(void)
{

}

template<typename T> CQueue<T>::~CQueue(void)
{

}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack1.size() == 0 && stack2.size() == 0)
	{
		throw exception("queue is empty.");//不用throw new exception才好使
	}
	if (stack2.size()>0)
	{
		T head = stack2.top();
		stack2.pop();
		return head;//1个
	}
	else
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();//这个引用能成立，但是9.2不成立，目测.top()返回的是拷贝而非引用
			stack1.pop();
			stack2.push(data);
		}
		T head = stack2.top();
		stack2.pop();
		return head;//2个
	}
	//return head;//逻辑没问题，但是无法通过编译，所以换成上面两个return，成功
}
/*template<typename T> T CQueue<T>::deleteHead()//源答案代码
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}*/


