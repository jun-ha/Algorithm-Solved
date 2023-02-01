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
int how_many = 0;
void recursive(int N, int row, int col);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, row, col; cin >> N >> row >> col;
	recursive(pow(2, N), row, col);
	cout << how_many;
	return 0;
}
void recursive(int N, int row, int col) {
	// 1 2
	// 3 4
	if (N == 0) return;
	if (row >= N / 2) {
		if (col >= N / 2) { //4
			how_many += pow(N / 2, 2) * 3;
			row -= N / 2;
			col -= N / 2;
		}
		else { //3
			how_many += pow(N / 2, 2) * 2;
			row -= N / 2;
		}
	}
	else {
		if (col >= N / 2) { //2 
			how_many += pow(N / 2, 2);
			col -= N / 2;
		}
	}
	recursive(N / 2, row, col);
}