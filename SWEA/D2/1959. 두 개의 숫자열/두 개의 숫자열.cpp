#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int N, M; cin >> N >> M;

		vector<int>v1(N, 0);
		vector<int>v2(M, 0);
		for (int i = 0; i < N; i++) cin >> v1[i];
		for (int i = 0; i < M; i++) cin >> v2[i];

		
		int longer = max(N, M);
		int shorter = min(N, M);
		vector<int>longVec;
		vector<int>shortVec;
		if (longer == N) {
			longVec = v1;
			shortVec = v2;
		}
		else {
			longVec = v2;
			shortVec = v1;
		}
		
		int maxValue = -1;
		for (int longStartIdx = 0; longStartIdx <= longer - shorter; longStartIdx++) {
			int sum = 0;
			for (int i = 0; i < shorter; i++) {
				sum += shortVec[i] * longVec[longStartIdx+i];
			}
			maxValue = max(maxValue, sum);
		}

		cout << "#" << count++ << " " << maxValue << ENDL;
	}


	return 0;
}