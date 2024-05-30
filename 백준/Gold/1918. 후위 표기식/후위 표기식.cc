#include <iostream>
#include <string>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

int precedence(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	stack<char>s;
	for (char c : str) {
		if (isalpha(c)) {
			cout << c;
			continue;
		}

		if (c == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		if (c == '(') {
			s.push(c);
			continue;
		}

		while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
			cout << s.top();
			s.pop();
		}

		s.push(c);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}


	return 0;
}