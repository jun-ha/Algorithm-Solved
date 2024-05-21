#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int>temperature(N, 0);
	cin >> temperature[0];
	for (int i = 1; i < N; i++) {
		int temp; cin >> temp;
		temperature[i] = temp + temperature[i - 1];
	}
	int maxValue = temperature[K-1];
	for (int i = K; i < N; i++) {
		maxValue = max(maxValue, temperature[i] - temperature[i - K]);
	}
	cout << maxValue;

	return 0;
}