#include <iostream>
#define ENDL '\n'
using namespace std;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int arr[11] = { 1,2,4,7,13,24,44,81,149,274,502 };
	while (T--) {
		int N;
		cin >>N;
		cout << arr[N - 1] << ENDL;
	}
	return 0;
}