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
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (!a) return 0;
		int max, n1, n2;
		if (a >= b && a >= c) {
			max = a; n1 = b; n2 = c;
		}
		else if (b >= a && b >= c) {
			max = b; n1 = a; n2 = c;
		}
		else {
			max = c; n1 = a; n2 = b;
		}
		if (pow(n1, 2) + pow(n2, 2) == pow(max, 2)) cout << "right" << ENDL;
		else cout << "wrong" << ENDL;
	}
	


	return 0;
}