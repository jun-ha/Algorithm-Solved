#include <iostream>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

bool isPrimeNumber(int num);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>primeNumbers;
	primeNumbers.reserve(N);
	primeNumbers.push_back(2);
	for (int num = 3; num <= N; num+=2) {
		if (isPrimeNumber(num)) {
			primeNumbers.push_back(num);
		}
	}
	int sum = 0, count = 0, front = 0, back = 0;
	while (back != primeNumbers.size()) {
		if (primeNumbers[back] > N) break;
		sum += primeNumbers[back];
		if (sum == N) count++;
		else if (sum > N) {
			while (sum > N && front <= back) {
				sum -= primeNumbers[front++];
			}
			if (sum == N) count++;
		}
		back++;
	}
	cout << count;
	return 0;
}
bool isPrimeNumber(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}