#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

void makeW(vector<vector<vector<int>>>& w, int a, int b, int c);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<vector<int>>>w(21, vector<vector<int>>(21, vector<int>(21, 0)));
	for (int a = 0; a <= 20; a++) {
		for (int b = 0; b <= 20; b++) {
			for (int c = 0; c <= 20; c++) {
				makeW(w, a, b, c);
			}
		}
	}

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)return 0;
		else if (a <= 0 || b <= 0 || c <= 0) cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << ENDL;
		else if (a > 20 || b > 20 || c > 20) cout << "w(" << a << ", " << b << ", " << c << ") = " << 1048576 << ENDL;
		else cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << ENDL;
	}



	return 0;
}
int findW(int a, int b, int c) {
	return 0;
}
void makeW(vector<vector<vector<int>>>& w, int a, int b, int c) {
	if (!a || !b || !c) {
		w[a][b][c] = 1;
	}
	else if (a < b && b < c) {
		w[a][b][c] = w[a][b][c - 1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
	}
	else {
		w[a][b][c] = w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];
	}
}