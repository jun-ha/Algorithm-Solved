#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;


int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, N; cin >> K >> N;
	vector<int>lines(K, 0);
	for (int i = 0; i < K; i++) cin >> lines[i];
	sort(lines.begin(), lines.end());
	ll minRange = 1;
	ll maxRange = lines.back();
	int answer = 0;
	while (minRange <= maxRange) {
		ll mid = (minRange + maxRange) / 2;
		int sum = 0;
		for (int len : lines) {
			sum += len / mid;
		}
		if (sum >= N) {
			answer = mid;
			minRange = mid + 1;
		}
		else {
			maxRange = mid - 1;
		}
	}
	cout << answer;

	return 0;
}