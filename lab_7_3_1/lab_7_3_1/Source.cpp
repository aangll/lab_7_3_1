#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			y[i][j] = Low + rand() % (High - Low + 1);
}


void Print(int** y, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << y[i][j];
		cout << endl;
	}
	cout << endl;
}


pair<int, int> Max(int** y, const int n, int top) {

	int max = -123;
	pair<int, int> result = { 0, 0 };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (i < top && j == i)
				continue;
			if (y[i][j] > max) {
				max = y[i][j];
				result = { i,j };
			}
		}
	return result;
}


void Change(int** y, const int n) {

	for (int top = 0; top < n; top++) {

		pair<int, int> indexMax = Max(y, n, top);

		int tmp;
		tmp = y[indexMax.first][indexMax.second];
		y[indexMax.first][indexMax.second] = y[top][top];
		y[top][top] = tmp;
	}
}

int noPlus(int** y, const int n)
{
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n; j++) 
		{
			if (y[i][j] < 0)
				continue;
			else break;
		}
		if (j == n)
			return i + 1;
	}
	return -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -50;
	int High = 5;
	int n = 5;
	int** y = new int* [n];
	for (int i = 0; i < n; i++)
		y[i] = new int[n];
	Create(y, n, Low, High);
	Print(y, n);
	Change(y, n);
	Print(y, n);
	cout << noPlus(y, n)<< endl;
	for (int i = 0; i < n; i++)
		delete[] y[i];
	delete[] y;
	return 0;
}
