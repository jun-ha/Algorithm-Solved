#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) cin >> nums[i];

	vector<vector<bool>>dp(N, vector<bool>(N, true));

	int colStartIdx = 1;

	for (colStartIdx; colStartIdx < N; colStartIdx++) {
		int row = 0;
		int col = colStartIdx;
		while (row < N && col < N) {
			if (nums[row] != nums[col]) dp[row][col] = false;
			else dp[row][col] = dp[row + 1][col - 1];

			row++; col++;
		}
	}

	int M; cin >> M;
	while (M-->0) {
		int start, end; cin >> start >> end;
		cout << dp[start - 1][end - 1] << ENDL;
	}

	return 0;
}