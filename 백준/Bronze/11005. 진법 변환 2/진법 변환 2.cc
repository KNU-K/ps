#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#define ll long long
using namespace std;

int main() {
	stack<int> s;
	int n,x;
	cin >> n>>x;
	int rs = 0;
	while (n) {
		s.push(n % x);
		n = n / x;
	}

	while (!s.empty()) {
		if (s.top() >= 10) {

			cout << (char)(s.top() - 10 + 'A');
		}
		else {
			cout << s.top();
		}
		s.pop();
	}
}