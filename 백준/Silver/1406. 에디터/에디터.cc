#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	stack<char> s;
	stack<char> r;
	char cmd;
	cin >> str;
	for (int i = 0; i < str.length();i++) {
		s.push(str[i]);
	}
	int n;
	
	char a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		switch (cmd) {
		case 'P':
			cin >> a;
			s.push(a);
			break;
		case 'L':
			if (!s.empty()) {
				r.push(s.top());
				s.pop();
			}
			break;
		case 'D':
			if(!r.empty()){
				s.push(r.top());
				r.pop();
			}
			break;
		case 'B':
			if (!s.empty()) {
				s.pop();
			}
		}
	}
	while (!s.empty()) {
        r.push(s.top());
        s.pop();
    }

    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    cout << "\n";
}