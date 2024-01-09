#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

ll modulo(ll base, ll exp, ll mod);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll A, B, C;
	cin >> A >> B >> C;
	cout << modulo(A, B, C);



	return 0;
}
ll modulo(ll base, ll exp, ll mod) {
	if (exp == 0) return 1;
	if (exp == 1) return base%mod;
	if (exp % 2 == 0) return (modulo(base, exp / 2, mod) * modulo(base, exp / 2, mod)) % mod;
	if (exp % 2 == 1) return (modulo(base, exp / 2, mod) * modulo(base, (exp / 2)+1, mod)) % mod;

}