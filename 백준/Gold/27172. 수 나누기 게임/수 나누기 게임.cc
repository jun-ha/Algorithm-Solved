#include <iostream>
#include <vector>
#include <map>
#define ENDL '\n'

using namespace std;
using ll = long long;
#define MAX_NUM 1000000

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;

	vector<int>nums;
	map<int, int>answer;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		nums.push_back(num);
		answer.insert({ num, 0 });
	}

	for (int num : nums) {
		int k = 2;
		while (num * k <= MAX_NUM) {
			if (answer.find(num * k) != answer.end()) {
				answer[num]++;
				answer[num * k]--;
			}
			k++;
		}
	}

	for (int num : nums) {
		cout << answer[num] << " ";
	}
	return 0;
}