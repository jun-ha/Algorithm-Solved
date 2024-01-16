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
	vector<int>nums(N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		nums[i] = num;
	}
	int sum = 0;
	int maxSum = -1001;
	for (int i = 0; i < N; i++) {
		sum += nums[i];
		if (sum > maxSum) maxSum = sum;
		if (sum < 0) sum = 0;
	}
	cout << maxSum;




	return 0;
}