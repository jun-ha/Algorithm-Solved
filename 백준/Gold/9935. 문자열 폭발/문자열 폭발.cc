#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str, bomb; cin >> str >> bomb;
	char lastWord = bomb.back();

	stack<char>s;
	for (char c : str) {
		s.push(c);
		if (c == lastWord) {
			stack<char>garbage;
			int idx = bomb.length() - 1;
			bool match = false;
			while (!s.empty()) {
				if (idx == -1) {
					match = true;
					break;
				}
				if (s.top() == bomb[idx]) {
					garbage.push(s.top());
					s.pop();
					idx--;
				}
				else {
					break;
				}
			}
			if (idx == -1) match = true;
			if (!match) {
				while (!garbage.empty()) {
					s.push(garbage.top());
					garbage.pop();
				}
			}
		}
	}
	stack<char>answer;
	while (!s.empty()) {
		answer.push(s.top());
		s.pop();
	}
	if (answer.size() == 0) cout << "FRULA";
	else {
		while (!answer.empty()) {
			cout << answer.top();
			answer.pop();
		}
	}


	return 0;
}