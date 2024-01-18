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

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int accumulatedSumNoDelete = 0;
	int accumulatedSumDeleted = 0;
	int maxValueOfNoDelete = -1001;
	int maxValueOfDeleted = -1001;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		if (nums[i] < 0) { //음수라면 한 번 지워볼까..?
			if (accumulatedSumDeleted  + nums[i] < accumulatedSumNoDelete) {
				accumulatedSumDeleted = accumulatedSumNoDelete;
				flag = false;
			}
		}
		accumulatedSumNoDelete += nums[i];
		if (maxValueOfNoDelete < accumulatedSumNoDelete) maxValueOfNoDelete = accumulatedSumNoDelete;
		if (accumulatedSumNoDelete < 0) accumulatedSumNoDelete = 0;
		
		if (flag) {
			accumulatedSumDeleted += nums[i];
			if (maxValueOfDeleted < accumulatedSumDeleted) maxValueOfDeleted = accumulatedSumDeleted;
			if (accumulatedSumDeleted < 0) accumulatedSumDeleted = 0;
		}
	}


	cout << max(maxValueOfDeleted, maxValueOfNoDelete);
	return 0;
}