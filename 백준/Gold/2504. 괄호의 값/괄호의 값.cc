#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
		stack<pair<int, char>>s;

		string cmd;
		cin >> cmd;
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == '(') {
				s.push({ -1, cmd[i] });
			}
			else if (cmd[i] == ')') {
				if (s.empty()) {
					cout << 0;
					return 0;
				}
				if (s.top().first == -1) {

					if (s.empty()) {
						cout << 0;
						return 0;
					}
					if (s.top().second != '(') {
						cout << 0;
						return 0;
					}
					s.pop();
					s.push({ 2,'-' });
				}
				else {
					int sum = 0;
					while (!s.empty() && s.top().first != -1) {
						sum += s.top().first;
						s.pop();
					}
					if (s.empty()) {
						cout << 0;
						return 0;
					}
					if (s.top().second != '(') {
						cout << 0;
						return 0;
					}
					s.pop();
					s.push({ sum * 2, '-' });
				}
			}
			else if (cmd[i] == '[') {
				s.push({ -1, cmd[i] });
			}
			else {
				if (s.empty()) {
					cout << 0;
					return 0;
				}
				if (s.top().first == -1) {

					if (s.empty()) {
						cout << 0;
						return 0;
					}
					if (s.top().second != '[') {
						cout << 0;
						return 0;
					}
					s.pop();
					s.push({ 3,'-' });
				}
				else {
					int sum = 0;
					while (!s.empty() && s.top().first != -1) {
						sum += s.top().first;
						s.pop();
					}
					if (s.empty()) {
						cout << 0;
						return 0;
					}
					if (s.top().second != '[') {
						cout << 0;
						return 0;
					}
					s.pop();
					s.push({ sum * 3, '-' });
				}
			}
		}
		int sum = 0;
		while (!s.empty()) {
			if (s.top().second != '-') {
				cout << 0 << "\n";
				return 0;
			}
			sum += s.top().first;
			s.pop();
		}
		cout << sum;
}