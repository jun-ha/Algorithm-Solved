#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	if (!K) {
		cout << 1;
		return 0;
	}
	int mul1 = 1;
	int mul2 = 1;
	int a = K;
	for (int i = 0; i < a; i++) {
		mul1*= (N--);
		mul2*= (K--);
	}
	cout << mul1 / mul2;
	return 0;
}