#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <climits>
#define ENDL '\n'

using namespace std;
using ll = long long;

void rotate_90_degree(vector<vector<int>>& original, vector<vector<int>>&rotated) {
	int N = original.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rotated[i][j] = original[N - 1 - j][i];
		}
	}
}

void printMatrix(vector<vector<int>>& rotate_90, vector<vector<int>>& rotate_180, vector<vector<int>>& rotate_270) {
	int N = rotate_90.size();
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) cout << rotate_90[row][col];
		cout << " ";
		for (int col = 0; col < N; col++) cout << rotate_180[row][col];
		cout << " ";
		for (int col = 0; col < N; col++) cout << rotate_270[row][col];
		cout << ENDL;
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int N; cin >> N;
		vector<vector<int>>matrix(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}
		vector<vector<int>>rotate_90(N, vector<int>(N, 0));
		vector<vector<int>>rotate_180(N, vector<int>(N, 0));
		vector<vector<int>>rotate_270(N, vector<int>(N, 0));

		rotate_90_degree(matrix, rotate_90);
		rotate_90_degree(rotate_90, rotate_180);
		rotate_90_degree(rotate_180, rotate_270);
		cout << "#" << count++ << ENDL;
		printMatrix(rotate_90, rotate_180, rotate_270);
	}

	return 0;
}