#include <iostream>
using namespace std;
/*为了防止从类的外部调用构造函数，产生类的新的实例，
我们应该把该类的构造函数声明成protected或者private。
由于只能生成一个类的实例，我们可以考虑用静态成员函数
来记录，到底之前有没有构造过类的实例。如果没有构造过
，那么就构造一个新的实例。如果构造过，那么就把之前构
造的那个实例返回。为了保证之前构造的实例，在程序运行
期间一直存在，不被析构，我们只能把指向这个实例的指针
声明成静态变量，存放在静态存储区，把这个类的实例用
new来构造，并放在堆里。*/
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
	static void Release()   //必须，否则会导致内存泄露  
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