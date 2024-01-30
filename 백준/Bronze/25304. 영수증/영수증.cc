#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int x;
	cin >> x;
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		x -= (a * b);
	}
	cout << (x == 0 ? "Yes" : "No");
}