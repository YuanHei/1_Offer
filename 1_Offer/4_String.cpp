#include <iostream>
#include <string>
using namespace std;

//重新开辟空间
char* ReplaceString(char *str)
{
	if (str == NULL)
	{
		return NULL;
	}
	int len = strlen(str);
	int count = 0;
	char* p = str;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			count++;
		}
		p++;
	}
	int newLen = len + count * 2;
	char *newstr = (char*)malloc(newLen);
	for (int i = newLen, j = len; j >= 0; --i, --j)
	{
		if (str[j] != ' ')
		{
			newstr[i] = str[j];
		}
		else
		{
			newstr[i] = '0';
			i--;
			newstr[i] = '2';
			i--;
			newstr[i] = '%';
		}
	}
	return newstr;
}
//不需开辟新的空间
char* ReplaceString_(char *str)
{
	if (str == NULL)
	{
		return NULL;
	}
	int len = strlen(str);
	int count = 0;
	char* p = str;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			count++;
		}
		p++;
	}
	int newLen = len + count * 2;
	int i = len;
	int j = newLen;
	while (i >= 0 && j > i)
	{
		if (str[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else
		{
			str[j--] = str[i];
		}
		--i;
	}
	return str;
}
int main()
{
	char a[] = "We are happy.";
	cout << ReplaceString(a) << endl;
	cout << ReplaceString_(a) << endl;
	return 0;
}