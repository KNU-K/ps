#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			s.pop();
		}
		else {
			s.push(x);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}