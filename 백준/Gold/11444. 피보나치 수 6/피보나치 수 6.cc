#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

#define MOD 1000000007

vector<vector<ll>> multiplyMatrix(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2) {
	int N = mat1.size();
	vector<vector<ll>>answer(N, vector<ll>(N, 0));
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			for (int idx = 0; idx < N; idx++) {
				ll tmp = ((mat1[row][idx] % MOD) * (mat2[idx][col] % MOD)) % MOD;
				answer[row][col] = (answer[row][col] % MOD + tmp % MOD) % MOD;
			}
		}
	}
	return answer;
}

vector<vector<ll>> power(vector<vector<ll>> matrix, ll n) {
	if (n == 0 || n == 1) {
		return matrix;
	}
	
	vector<vector<ll>>half(matrix.size(), vector<ll>(matrix.size(), 0));
	if (n % 2 == 0) {
		half = power(matrix, n / 2);
		return multiplyMatrix(half, half);
	}
	else {
		half = power(matrix, (n - 1) / 2);
		vector<vector<ll>>halfMul = multiplyMatrix(half, half);
		return multiplyMatrix(halfMul, matrix);
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<ll>>matrix = { {1, 1}, {1, 0} };
	ll N; cin >> N;
	
	cout << power(matrix, N - 1)[0][0];
	return 0;
}