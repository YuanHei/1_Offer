#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

void Push_back(ListNode** head, int value)
{
	ListNode *s = new ListNode();
	s->data = value;
	s->next = NULL;
	if (*head == NULL)
	{
		*head = s;
	}
	else
	{
		ListNode* p = *head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void Show(ListNode** head)
{
	if (*head == NULL)
	{
		return;
	}
	ListNode* p = *head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//·ÇµÝ¹é,½èÖúÕ»ÊµÏÖ
void ReverseShow_(ListNode** head)
{
	stack<ListNode*> st;
	ListNode* p = *head;
	if (*head == NULL)
	{
		return;
	}
	while (p != NULL)
	{
		st.push(p);
		p = p->next;
	}
	while (!st.empty())
	{
		p = st.top();
		cout << p->data << " ";
		st.pop();
	}
	cout << endl;
}

//µÝ¹é
void ReverseShow(ListNode** head)
{
	ListNode* p = *head;
	if (*head == NULL)
	{
		return;
	}
	else
	{
		if (p->next != NULL)
		{
			ReverseShow(&p->next);
		}
		cout << p->data << " ";
	}
}

int main()
{
	ListNode *lt;
	lt = NULL;
	for (int i = 0; i < 5; ++i)
	{
		Push_back(&lt, i);
	}
	Show(&lt);
	ReverseShow(&lt);
	cout << endl;
	ReverseShow_(&lt);
	return 0;
}