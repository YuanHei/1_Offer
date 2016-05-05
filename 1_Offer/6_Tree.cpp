#include <iostream>
using namespace std;

typedef int ElemType;

struct BinaryTreeNode
{
	int            m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void CreateBitTree(BinaryTreeNode** T, char* pre, char* in, int len)
{
	int k;
	char* temp;
	if (len <= 0)
	{
		*T = NULL;
		return;
	}
	*T = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	(*T)->m_nValue = *pre;
	for (temp = in; temp < in + len; ++temp)
	{
		if (*pre == *temp)
		{
			break;
		}
	}
	k = temp - in;
	CreateBitTree(&((*T)->m_pLeft), pre + 1, in, k);
	CreateBitTree(&((*T)->m_pRight), pre + 1 + k, temp + 1, len - 1 - k);
}

void PreOrderTraverse(BinaryTreeNode* T)
{
	if (T)
	{
		cout << T->m_nValue << " ";
		PreOrderTraverse(T->m_pLeft);
		PreOrderTraverse(T->m_pRight);
	}
}

void InOrderTraverse(BinaryTreeNode* T)
{
	if (T)
	{
		InOrderTraverse(T->m_pLeft);
		cout << T->m_nValue << " ";
		InOrderTraverse(T->m_pRight);
	}
}

void PostOrderTraverse(BinaryTreeNode* T)
{
	if (T)
	{
		PostOrderTraverse(T->m_pLeft);
		PostOrderTraverse(T->m_pRight);
		cout << T->m_nValue << " ";
	}
}

int main()
{
	BinaryTreeNode *bt;
	char pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	char in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	CreateBitTree(&bt, pre, in, 8);
	PreOrderTraverse(bt);
	cout << endl;
	InOrderTraverse(bt);
	cout << endl;
	PostOrderTraverse(bt);
	cout << endl;
	return 0;
}