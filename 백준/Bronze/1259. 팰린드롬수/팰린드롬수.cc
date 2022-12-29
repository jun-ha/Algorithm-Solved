#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

bool palCheck(string num) {
	int len = num.length();
	for (int i = 0; i < len/2; i++) {
		if (num[i] != num[len - 1 - i]) return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string num;
	while (1) {
		cin >> num;
		if (num[0]=='0') return 0;
		if (palCheck(num)) cout << "yes" << ENDL;
		else cout << "no" << ENDL;
	}
}