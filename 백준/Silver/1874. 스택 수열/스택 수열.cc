#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int cnt = 1;
int main() {
	int n;
	stack<int> s;
	vector<char> ans;
	cin >> n;
	for (int i=0;i<n;i++ ) {
		int x;
		cin >> x;
		while (cnt <= x&& cnt <=n) {
			s.push(cnt++);
			ans.push_back('+');
		}
		if (!s.empty() && s.top() == x) {
			ans.push_back('-');
			s.pop();
		}
		else {
			cout << "NO\n";
			return 0;

		}
	}
	if (!s.empty()) {
		cout << "NO\n";
		return 0;
	}
	for (auto e : ans) {
		cout << e << "\n";
	}
}