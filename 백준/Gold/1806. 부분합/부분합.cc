#include <iostream>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, S;
	cin >> N >> S;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int sum = 0;
	int front = 0, back = 0;
	int minCount = 999999999;
	while (back != N) {
		sum += nums[back];
		if (sum >= S) {
			while (sum >= S) sum -= nums[front++];
			front--;
			sum+=nums[front];
			if (minCount > back-front+1) minCount = back-front+1;
		}
		back++;
	}
	if (minCount == 999999999) cout << 0;
	else cout << minCount;

	return 0;
}