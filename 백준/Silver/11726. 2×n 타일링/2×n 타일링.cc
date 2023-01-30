#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int>a(1001);
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		a[i] = (a[i - 1] + a[i - 2])%10007;
	}
	cout << a[n];
	return 0;
}