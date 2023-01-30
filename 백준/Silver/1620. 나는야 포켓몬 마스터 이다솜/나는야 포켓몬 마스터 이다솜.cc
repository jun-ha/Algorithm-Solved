#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<string>pocketmon1;
	pocketmon1.push_back("");
	map<string, int>pocketmon2;
	for (int i = 0; i < N; i++) {
		string name; cin >> name;
		pocketmon1.push_back(name);
		pocketmon2.insert(make_pair(name, i+1));
	}
	for (int i = 0; i < M; i++) {
		string question; cin >> question;
		if (isdigit(question[0])) {
			cout << pocketmon1[stoi(question)] << ENDL;
		}
		else {
			cout << pocketmon2.find(question)->second << ENDL;
		}

	}





	return 0;
}