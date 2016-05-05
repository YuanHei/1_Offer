#include <iostream>
using namespace std;
/*Ϊ�˷�ֹ������ⲿ���ù��캯������������µ�ʵ����
����Ӧ�ðѸ���Ĺ��캯��������protected����private��
����ֻ������һ�����ʵ�������ǿ��Կ����þ�̬��Ա����
����¼������֮ǰ��û�й�������ʵ�������û�й����
����ô�͹���һ���µ�ʵ����������������ô�Ͱ�֮ǰ��
����Ǹ�ʵ�����ء�Ϊ�˱�֤֮ǰ�����ʵ�����ڳ�������
�ڼ�һֱ���ڣ���������������ֻ�ܰ�ָ�����ʵ����ָ��
�����ɾ�̬����������ھ�̬�洢������������ʵ����
new�����죬�����ڶ��*/
class CSingleton
{
public:
	static CSingleton * GetInstance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = new CSingleton();
		}
		return m_pInstance;
	}
	static void Release()   //���룬����ᵼ���ڴ�й¶  
	{
		if (NULL != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

protected:
	CSingleton()
	{
		cout << "CSingleton" << endl;
	};
	static CSingleton * m_pInstance;
};

CSingleton* CSingleton::m_pInstance = NULL;

int main()
{
	CSingleton* m;
	m->GetInstance();
	m->Release();
	CSingleton* p;
	p->GetInstance();
	return 0;
}