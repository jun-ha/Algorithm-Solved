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
	int N;
	cin >> N;
	vector<int>arr(N+1);
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 1] % 15746 + arr[i - 2] % 15746) % 15746;
	}
	cout << arr[N];


	return 0;
}