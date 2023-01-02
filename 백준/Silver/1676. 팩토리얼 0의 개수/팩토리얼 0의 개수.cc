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

int two = 0, five = 0;

void findZero(int N) {
	if (N <= 2)return;
	int a = N;
	int b = N;
	while (!(a % 2)) {
		two++;
		a /= 2;
	}
	while (!(b % 5)) {
		five++;
		b /= 5;
	}
	findZero(N - 1);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	findZero(N);
	if(two <= five)cout << two;
	else cout << five;


	return 0;
}