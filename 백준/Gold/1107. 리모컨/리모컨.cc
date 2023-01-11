#include <iostream>
#include <vector>
#define ENDL '\n'
using namespace std;

int findSmallerCount(int N, vector<int>v);
int findBiggerCount(int N, vector<int>v);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int hundredCount = N - 100;
	if (hundredCount < 0) hundredCount *= -1;
	int broken; cin >> broken;
	vector<int>brokenNums(10, 0);
	vector<int>possibleNums;
	for (int i = 0; i < broken; i++) {
		int num; cin >> num;
		brokenNums[num]++;
	}
	if (broken == 10) {
		cout << hundredCount;
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (!brokenNums[i]) {
			possibleNums.push_back(i);
		}
	}
	int LCount = findSmallerCount(N, possibleNums);
	int BCount = findBiggerCount(N, possibleNums);
	if (LCount < 0) LCount = 99999999;
	if (BCount < 0) BCount = 99999999;
	if (N % 10 == N && possibleNums.front() > N) {
		cout << BCount;
		return 0;
	}
	int minButtonPush = LCount;
	if (LCount > BCount) {
		minButtonPush = BCount;
	}
	if (minButtonPush > hundredCount) {
		minButtonPush = hundredCount;
	}
	cout << minButtonPush;
	return 0;
}
vector<int> makeNumVector(int N) {
	int k = 10;
	vector<int>nums;
	while (N / k) {
		k *= 10;
	}
	k /= 10;
	while (k >= 1) {
		nums.push_back(N / k);
		N %= k;
		k /= 10;
	}
	return nums;
}
vector<int> makeSmallerVector(vector<int> nums, vector<int> possibleNums) {
	vector<int>smaller(nums.size());
	vector<int>less(nums.size(), -1);
	less[0] = 0;
	for (int i = 0; i < nums.size(); i++) {
		int tmp = -1;
		for (auto j = possibleNums.begin(); j != possibleNums.end(); j++) {
			if (*j <= nums[i]) {
				tmp = *j;
				if (*j > possibleNums[0]) {
					less[i] = *(j - 1);
				}
			}
			else break;
		}
		if (tmp == -1) {
			for (i; i >= 0; i--) {
				if (less[i] >= 0) {
					smaller[i] = less[i];
					break;
				}
			}
			for (++i; i < nums.size(); i++) {
				smaller[i] = *(possibleNums.end() - 1);
			}
		}
		else {
			smaller[i] = tmp;
			if (tmp < nums[i]) {
				for (++i; i < nums.size(); i++) {
					smaller[i] = *(possibleNums.end() - 1);
				}
				break;
			}
		}
	}
	return smaller;
}
vector<int> makeBiggerVector(vector<int> nums, vector<int> possibleNums) {
	vector<int>bigger(nums.size());
	vector<int>more(nums.size(), -1);
	for (int i = 0; i < nums.size(); i++) {
		int tmp = -1;
		for (auto j = possibleNums.rbegin(); j != possibleNums.rend(); j++) {
			if (*j >= nums[i]) {
				tmp = *j;
				if (*j < possibleNums.back()) {
					more[i] = *(j - 1);
				}
			}
			else break;
		}
		if (tmp == -1) {
			for (i; i >= 0; i--) {
				if (more[i] >= 0) {
					bigger[i] = more[i];
					break;
				}
			}
			for (++i; i < nums.size(); i++) {
				bigger[i] = possibleNums.front();
			}
		}
		else {
			bigger[i] = tmp;
			if (tmp > nums[i]) {
				for (++i; i < nums.size(); i++) {
					bigger[i] = possibleNums.front();
				}
				break;
			}
		}
	}
	return bigger;
}
int changeVectorToNum(vector<int>v) {
	int num = 0;
	int k = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (!i && !v[i])break;
		num += v[i] * k;
		k *= 10;
	}
	return num;
}
int findSmallerCount(int N, vector<int>possibleNums) {
	int SCount = 0;
	vector<int>nums = makeNumVector(N);
	vector<int>smaller = makeSmallerVector(nums, possibleNums);
	SCount += smaller.size();
	for (auto x : smaller) {
		if (x == 0)SCount--;
		else break;
	}
	if (SCount <= 0) SCount = 1;
	int smaller_num = changeVectorToNum(smaller);
	SCount += N - smaller_num;
	return SCount;
}
int findBiggerCount(int N, vector<int>possibleNums) {
	int BCount = 0;
	vector<int>nums = makeNumVector(N);
	if (possibleNums.back() < nums.front()) {
		vector<int>nums2(nums.size() + 1, 0);
		nums2[0] = 1;
		if (possibleNums.back() < nums2.front())return 99999999;
		nums = nums2;
	}
	vector<int>bigger = makeBiggerVector(nums, possibleNums);
	BCount += bigger.size();
	for (auto x : bigger) {
		if (x == 0)BCount--;
		else break;
	}
	if (BCount <= 0) BCount = 1;
	int bigger_num = changeVectorToNum(bigger);
	BCount += bigger_num - N;
	return BCount;
}