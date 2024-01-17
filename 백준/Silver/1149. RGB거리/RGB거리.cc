#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int>accumulatedSum(3, 0);
	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		int tmpR, tmpG, tmpB;
		tmpR = min(accumulatedSum[1], accumulatedSum[2]) + r;
		tmpG = min(accumulatedSum[0], accumulatedSum[2]) + g;
		tmpB = min(accumulatedSum[0], accumulatedSum[1]) + b;
		accumulatedSum[0] = tmpR;
		accumulatedSum[1] = tmpG;
		accumulatedSum[2] = tmpB;
	}
	cout << min(accumulatedSum[0], min(accumulatedSum[1], accumulatedSum[2]));
	return 0;
}