#include <iostream>
#include <algorithm>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int>up(n);
		vector<int>down(n);
		for (int i = 0; i < n; i++) {
			cin >> up[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> down[i];
		}

		vector<int>accumulatedSum(n, 0);
		accumulatedSum[0] = up[0]; //choose up
		accumulatedSum[1] = down[0]; //choose down
		accumulatedSum[2] = 0; //choose nothing
		for (int i = 1; i < n; i++) {
			int tmpUp, tmpDown, tmpX;
			tmpUp = max(accumulatedSum[1], accumulatedSum[2]) + up[i];
			tmpDown = max(accumulatedSum[0], accumulatedSum[2]) + down[i];
			tmpX = max({ accumulatedSum[0], accumulatedSum[1], accumulatedSum[2] });
			accumulatedSum[0] = tmpUp;
			accumulatedSum[1] = tmpDown;
			accumulatedSum[2] = tmpX;
		}
		cout << max({ accumulatedSum[0], accumulatedSum[1], accumulatedSum[2] }) << ENDL;
	}


	return 0;
}