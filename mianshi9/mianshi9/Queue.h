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
		throw exception("queue is empty.");//����throw new exception�ź�ʹ
	}
	if (stack2.size()>0)
	{
		T head = stack2.top();
		stack2.pop();
		return head;//1��
	}
	else
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();//��������ܳ���������9.2��������Ŀ��.top()���ص��ǿ�����������
			stack1.pop();
			stack2.push(data);
		}
		T head = stack2.top();
		stack2.pop();
		return head;//2��
	}
	//return head;//�߼�û���⣬�����޷�ͨ�����룬���Ի�����������return���ɹ�
}
/*template<typename T> T CQueue<T>::deleteHead()//Դ�𰸴���
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


