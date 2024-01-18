#include <iostream>
#include <algorithm>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>wines(n);
	for (int i = 0; i < n; i++) {
		cin >> wines[i];
	}
	vector<int>accumulatedSum(3, 0);
	//3번째 와인부터 진행.
	accumulatedSum[0] = wines[0]; //acc[0]은 직전에 와인을 안마신상태, 
	accumulatedSum[1] = wines[1]; //acc[1]은 직전에 와인을 마신 상태
	accumulatedSum[2] = wines[0] + wines[1]; //acc[2]는 직전 연속 두번 마신 상태
	for (int i = 2; i < n; i++) {
		int tmpNotDrink = max({ accumulatedSum[0], accumulatedSum[1], accumulatedSum[2] }); //와인을 이번에 안마신다면, 직전 모든 경우의 수 가능. max값 선정.
		int tmpDrinkOnce = accumulatedSum[0] + wines[i];
		int tmpDrinkTwice = accumulatedSum[1] + wines[i];
		accumulatedSum[0] = tmpNotDrink;
		accumulatedSum[1] = tmpDrinkOnce;
		accumulatedSum[2] = tmpDrinkTwice;
	}

	cout << max({ accumulatedSum[0], accumulatedSum[1], accumulatedSum[2] });

	return 0;
}