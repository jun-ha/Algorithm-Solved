#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;
using ll = long long;
void divide(int**, int, int, int);
int white = 0, blue = 0;

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, k; 
	cin >> N;
	int** arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	divide(arr, 0, 0, N);
	cout << white << "\n" << blue;
	for (int i = 0; i < N; i++)
	{
		free(arr[i]);
	}
	free(arr);

	return 0;
}
void divide(int **arr, int start_row, int start_col, int end_index)
{
	int whiteOrBlue = arr[start_row][start_col];
	bool flag = false;
	for (int i = start_row; i < start_row + end_index; i++)
	{
		for (int j = start_col; j < start_col + end_index; j++)
		{
			if (arr[i][j] != whiteOrBlue)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (flag)
	{
		end_index /= 2;
		divide(arr, start_row, start_col, end_index);
		divide(arr, start_row, start_col + end_index, end_index);
		divide(arr, start_row + end_index, start_col, end_index);
		divide(arr, start_row + end_index, start_col + end_index, end_index);
	}
	else
	{
		if (whiteOrBlue)
		{
			blue++;
		}
		else
		{
			white++;
		}
	}
	
}
