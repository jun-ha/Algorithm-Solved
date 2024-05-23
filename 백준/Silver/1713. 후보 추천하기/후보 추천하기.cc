#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

bool cmp1(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	if (get<0>(a) == get<0>(b)) {
		return get<1>(a) < get<1>(b);
	}
	return get<0>(a) < get<0>(b);
}

bool cmp2(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	return get<2>(a) < get<2>(b);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int numOfFrames; cin >> numOfFrames;
	int numOfRecommend; cin >> numOfRecommend;
	vector<int>recommendInfo(numOfRecommend);
	vector<tuple<int, int, int>>frames;
	for (int i = 0; i < numOfRecommend; i++) {
		cin >> recommendInfo[i];
	}

	for (int time = 0; time < numOfRecommend; time++) {
		int studentNum = recommendInfo[time];
		bool notFound = true;
		for (int i = 0; i < frames.size(); i++) {
			if (get<2>(frames[i]) == studentNum) {
				auto [cnt, firstTime, studentNum] = frames[i];
				frames[i] = { cnt + 1, firstTime, studentNum };
				notFound = false;
				break;
			}
		}
		if (notFound) {
			if (frames.size() < numOfFrames) frames.push_back({1, time, studentNum});
			else {
				frames[0] = { 1, time, studentNum };
			}
		}
		sort(frames.begin(), frames.end(), cmp1);
	}
	sort(frames.begin(), frames.end(), cmp2);
	for (auto [cnt, time, studentNum] : frames) {
		cout << studentNum << " ";
	}

	return 0;
}