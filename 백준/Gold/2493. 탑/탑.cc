#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	stack<pair<int,int>>s;
	cin >> n;
	int x;

	cin >> x;
	cout << "0" << " ";
	s.push({ 1,x });
	for (int i = 1; i < n;i++) {
		vector<int> tmp;
		cin >> x;
		while (!s.empty() && s.top().second < x) {
			s.pop();
		}
		if (s.empty()) cout << 0 << " ";
		else {
			cout << s.top().first << " ";
		}
		s.push({ i+1, x });
	}
}