#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int numOfTrees, needLen; cin >> numOfTrees >> needLen;

	vector<int>trees(numOfTrees);
	for (int i = 0; i < numOfTrees; i++) cin >> trees[i];
	sort(trees.begin(), trees.end());

	ll minRange = 0;
	ll maxRange = trees.back();
	int answer = 0;

	while (minRange <= maxRange) {
		ll mid = (minRange + maxRange) / 2;
		int biggerIdx = upper_bound(trees.begin(), trees.end(), mid) - trees.begin();
		ll sum = 0;
		for (biggerIdx; biggerIdx < numOfTrees; biggerIdx++) {
			sum += trees[biggerIdx] - mid;
		}
		if (sum >= needLen) {
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