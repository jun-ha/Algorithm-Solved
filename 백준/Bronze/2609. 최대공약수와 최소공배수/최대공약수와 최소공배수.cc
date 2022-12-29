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
	int a, b;
	cin >> a >> b;
	int min = a;
	if (a > b) min = b;

	int n1, n2;
	for (int i = 1; i <= min; i++) {
		if (!(a % i)&&!(b%i)) n1 = i;
	}
	cout << n1 << ENDL << b / n1 * a;


	return 0;
}