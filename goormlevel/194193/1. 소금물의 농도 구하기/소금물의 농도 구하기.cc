#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N, M; cin >> N >> M;
	double salt = N * 0.07;
	int nongDo = salt / (N+M) * 100 * 100;
	
	cout << nongDo/100 << "." << (nongDo/10)%10 << nongDo % 10;
	return 0;
}