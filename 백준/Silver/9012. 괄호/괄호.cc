#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
void isFind(string txt) {
	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] == '(')s.push(txt[i]);
		else if (txt[i] == ')')
		{
			if (s.empty() || s.top() != '(') {
				cout << "NO\n";
				return;
			}
			else {
				s.pop();
			}
		}
	}
	if (!s.empty()) {
		cout << "NO\n";
		return;
	}
	else {
		cout << "YES\n";
		return;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		while (!s.empty())s.pop();
		string txt;
		cin >> txt;
		isFind(txt);

	}
}