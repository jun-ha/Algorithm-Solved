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
	int T; cin >> T;
	vector<int>fib(42);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 41; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while (T--) {
		int num;
		cin >> num;
		if (!num) {
			cout << "1 0" << ENDL;
		}
		else if (num == 1) {
			cout << "0 1" << ENDL;
		}
		else {
			cout << fib[num - 2] << ' ' << fib[num - 1] << ENDL;
		}
	}


	return 0;
}