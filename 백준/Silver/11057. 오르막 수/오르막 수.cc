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
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<vector<int>>nums(N + 1, vector<int>(10, 0));
	for (int i = 0; i <= 9; i++) {
		nums[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		int accumulatedSum = 0;
		for (int j = 0; j <= 9; j++) {
			nums[i][j] = ((accumulatedSum % 10007)+ (nums[i - 1][j]%10007))%10007;
			accumulatedSum = ((accumulatedSum%10007) + (nums[i - 1][j]%10007))%10007;
		}
	}

	int sum = 0;
	for (auto x : nums[N]) {
		sum = ((sum % 10007) + (x % 10007)) % 10007;
	}
	cout << sum;


	return 0;
}