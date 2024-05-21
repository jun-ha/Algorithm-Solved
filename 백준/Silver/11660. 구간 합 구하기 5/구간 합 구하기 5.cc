#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>>accumulated(N, vector<int>(N, 0));
	for (int row = 0; row < N; row++) {
		cin >> accumulated[row][0];
		for (int col = 1; col < N; col++) {
			int num; cin >> num;
			accumulated[row][col] = num + accumulated[row][col - 1];
		}
	}
	for (int row = 1; row < N; row++) {
		for (int col = 0; col < N; col++) {
			accumulated[row][col] += accumulated[row-1][col];
		}
	}

	while (M--) {
		int row1, row2, col1, col2;
		cin >> row1 >> col1 >> row2 >> col2;
		row1--; row2--; col1--; col2--;

		int square0, square1, square2, square3;
		square0 = accumulated[row2][col2];

		if (row1 == 0) square1 = 0;
		else square1 = accumulated[row1 - 1][col2];

		if (col1 == 0) square2 = 0;
		else square2 = accumulated[row2][col1 - 1];

		if (row1 != 0 && col1 != 0) square3 = accumulated[row1 - 1][col1 - 1];
		else square3 = 0;

		cout << square0 - square1 - square2 + square3 << ENDL;
	}

	return 0;
}