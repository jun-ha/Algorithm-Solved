#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <tuple>
#define ENDL '\n'

using namespace std;
using ll = long long;

ll llabs(ll val) {
	if (val < 0) val *= -1;
	return val;
}

tuple<int, int, int> sortTuple(tuple<int,int,int> tup) {
	int arr[3];
	auto [a, b, c] = tup;
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr, arr + 3);
	return make_tuple(arr[0], arr[1], arr[2]);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> acid;
	vector<int> alk;

	for (int i = 0; i < N; i++) {
		int value; cin >> value;
		if (value > 0) acid.push_back(value);
		else alk.push_back(value);
	}
	sort(acid.begin(), acid.end());
	sort(alk.begin(), alk.end());

	ll minValue = LLONG_MAX;
	tuple<int, int, int>answer;

	if (acid.size() >= 3) {
		if (minValue > acid[0] + acid[1] + acid[2]) {
			minValue = acid[0] + acid[1] + acid[2];
			answer = { acid[0], acid[1], acid[2] };
		}
	}
	if (alk.size() >= 3) {
		ll tmp = llabs(alk[alk.size() - 1] + alk[alk.size() - 2] + alk[alk.size() - 3]);
		if (minValue > tmp) {
			minValue = tmp;
			answer = { alk[alk.size() - 3], alk[alk.size() - 2], alk[alk.size() - 1] };
		}
	}

	if (acid.empty() || alk.empty()) {
		auto [first, second, third] = answer;
		cout << first << " " << second << " " << third;
		return 0;
	}

	for (int acidVal : acid) {
		for (int alkVal : alk) {
			ll sum = acidVal + alkVal;

			if (sum > 0) {
				if (acidVal != acid[0]) {
					ll tmpMin = sum + acid[0];
					if (minValue > tmpMin) {
						minValue = tmpMin;
						answer = { alkVal, acid[0], acidVal };
					}
				}

				ll find = -sum;
				int idx = lower_bound(alk.begin(), alk.end(), find) - alk.begin();

				if (idx == 0) {
					if (alk[idx] == alkVal) idx++;

					ll tmpMin = sum + alk[idx];
					if (minValue > llabs(tmpMin)) {
						minValue = llabs(tmpMin);
						answer = { alk[idx], alkVal, acidVal };
					}
				}
				else if (idx == alk.size()) {
					idx--;
					if (alk[idx] == alkVal) idx--;

					ll tmpMin = sum + alk[idx];
					if (minValue > llabs(tmpMin)) {
						minValue = llabs(tmpMin);
						answer = { alkVal, alk[idx], acidVal };
					}
				}
				else {
					int biggerIdx = idx;
					int smallerIdx = idx - 1;

					if (alk[biggerIdx] == alkVal) biggerIdx++;
					if (alk[smallerIdx] == alkVal) smallerIdx--;

					if (biggerIdx != alk.size()) {
						ll tmpMin = sum + alk[biggerIdx];
						if (minValue > llabs(tmpMin)) {
							minValue = llabs(tmpMin);
							answer = { alkVal, alk[biggerIdx], acidVal };
						}
					}
					if (smallerIdx != -1) {
						ll tmpMin = sum + alk[smallerIdx];
						if (minValue > llabs(tmpMin)) {
							minValue = llabs(tmpMin);
							answer = { alkVal, alk[smallerIdx], acidVal };
						}
					}
				}
			}
			else if (sum < 0) {
				if (alkVal != alk.back()) {
					ll tmpMin = sum + alk.back();
					if (minValue > llabs(tmpMin)) {
						minValue = llabs(tmpMin);
						answer = { alkVal, alk.back(), acidVal };
					}
				}

				ll find = -sum;
				int idx = lower_bound(acid.begin(), acid.end(), find) - acid.begin();

				if (idx == 0) {
					if (acid[idx] == acidVal) idx++;

					ll tmpMin = sum + acid[idx];
					if (minValue > llabs(tmpMin)) {
						minValue = llabs(tmpMin);
						answer = { alkVal, acid[idx], acidVal };
					}
				}
				else if (idx == acid.size()) {
					idx--;
					if (acid[idx] == acidVal) idx--;

					ll tmpMin = sum + acid[idx];
					if (minValue > llabs(tmpMin)) {
						minValue = llabs(tmpMin);
						answer = { alkVal, acid[idx], acidVal };
					}
				}
				else {
					int biggerIdx = idx;
					int smallerIdx = idx - 1;

					if (acid[biggerIdx] == acidVal) biggerIdx++;
					if (acid[smallerIdx] == acidVal) smallerIdx--;

					if (biggerIdx != acid.size()) {
						ll tmpMin = sum + acid[biggerIdx];
						if (minValue > llabs(tmpMin)) {
							minValue = llabs(tmpMin);
							answer = { alkVal, acid[biggerIdx], acidVal };
						}
					}
					if (smallerIdx != -1) {
						ll tmpMin = sum + acid[smallerIdx];
						if (minValue > llabs(tmpMin)) {
							minValue = llabs(tmpMin);
							answer = { alkVal, acid[smallerIdx], acidVal };
						}
					}
				}
			}
			else { //sum == 0
				int acidIdx = 0;
				int alkIdx = alk.size() - 1;
				if (acid[acidIdx] == acidVal) acidIdx++;
				if (alk[alkIdx] == alkVal) alkIdx--;

				ll tmpMin1 = sum + acid[acidIdx];
				if (minValue > llabs(tmpMin1)) {
					if (minValue > llabs(tmpMin1)) {
						minValue = llabs(tmpMin1);
						answer = { alkVal, acid[acidIdx], acidVal };
					}
				}

				ll tmpMin2 = sum + alk[alkIdx];
				if (minValue > llabs(tmpMin2)) {
					if (minValue > llabs(tmpMin2)) {
						minValue = llabs(tmpMin2);
						answer = { alkVal, alk[alkIdx], acidVal };
					}
				}
			}
		}
	}

	auto [first, second, third] = sortTuple(answer);
	cout << first << " " << second << " " << third;
	


	return 0;
}