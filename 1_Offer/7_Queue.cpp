#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;

class MyQueue
{
public:
	MyQueue()
	{}
	~MyQueue()
	{}
	void appendTail(const ElemType& value)
	{
		s1.push(value);
	}
	ElemType deleteHead()
	{
		if (s2.size() <= 0)
		{
			while (s1.size() > 0)
			{
				ElemType& data = s1.top();
				s1.pop();
				s2.push(data);
			}
		}
		if (s2.size() == 0)
		{
			cout << "queue is empty" << endl;
			return NULL;
		}
		ElemType head = s2.top();
		s2.pop();

		return head;
	}
private:
	stack<ElemType> s1;
	stack<ElemType> s2;
};

int main()
{
	MyQueue mq;
	mq.appendTail(1);
	mq.appendTail(2);
	cout << mq.deleteHead() << endl;
	cout << mq.deleteHead() << endl;
	mq.appendTail(3);
	cout << mq.deleteHead() << endl;
	return 0;
}