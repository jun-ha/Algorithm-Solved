#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

void recursive(vector<string>v, int row, int col, int n);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v[i] = str;
	}
	recursive(v, 0, 0, n);


	return 0;
}
void recursive(vector<string>v, int row, int col, int n) {
	char check = v[row][col];
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (v[i][j] != check) {
				cout << '(';
				recursive(v, row, col, n / 2);
				recursive(v, row, col + (n / 2), n / 2);
				recursive(v, row + (n / 2), col, n / 2);
				recursive(v, row + (n / 2), col + (n / 2), n / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << check;
}


