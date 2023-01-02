#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	int coin = 0;
	vector<int>price(N);
	for (int i = 0; i < N; i++) {
		int p; cin >> p;
		price[i] = p;
	}
	int j = N-1;
	while (K > 0) {
		if (price[j] > K) {
			j--;
			continue;
		}
		if (K % price[j]) {
			coin += K / price[j];
			K %= price[j];
			if (K == 1) {
				coin++;
				break;
			}
		}
		else {
			coin += K / price[j];
			break;
		}
		j--;
	}
	cout << coin;
	return 0;
}