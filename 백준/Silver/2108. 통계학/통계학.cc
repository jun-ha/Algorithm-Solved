#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;

	vector<int>nums(N, 0);
	vector<int>numCount(8001, 0);
	double sum = 0;
	int maxCount = 0;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		numCount[num+4000]++;
		sum += num;
		if (numCount[num+4000] > maxCount) maxCount = numCount[num+4000];
		nums[i] = num;
	}
	sort(nums.begin(), nums.end());

	int secondMode = 0;
	bool second = false;
	for (int i = 0; i <= 8000; i++) {
		if (numCount[i] == maxCount) {
			secondMode = i - 4000;
			if (second) break;
			second = true;
		}
	}

	double avg = fabs(sum / N);
	int answer_avg = avg * 10 + 5;
	answer_avg /= 10;
	if (sum < 0) answer_avg *= -1;
	cout << answer_avg << ENDL << nums[N/2] << ENDL << secondMode << ENDL << nums.back() - nums.front();

	return 0;
}