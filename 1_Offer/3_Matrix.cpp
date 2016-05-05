#include <iostream>
using namespace std;
//二维数组传参方法一

bool Find(int a[][4], int rows, int cols, int index)
{
	if (a != NULL && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (a[row][row*cols + col] == index)
			{
				return true;
			}
			else if (a[row][row*cols + col] > index)
			{
				--col;
			}
			else
			{
				++row;
			}
		}
	}
	return false;
}

int main()
{
	int a[4][4] = {
		{ 1, 2, 8, 9 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 } };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int index;
	cin >> index;
	if (Find(a, 4, 4, index))
	{
		cout << "find it!" << endl;
	}
	else
	{
		cout << "not find it!" << endl;
	}

	return 0;
}

//二维数组传参方法二
#include <iostream>
using namespace std;

bool find(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

int main()
{
	int a[4][4] = { 
		{ 1, 2, 8, 9 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 } };
	cout << find(*a, 4, 4, 7) << endl;
	cout << find(*a, 4, 4, 3) << endl;
	return 0;
}