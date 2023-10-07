#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	int minRes = 1000001;
	int maxRes = -1000001;
	while (t--) {
		int x;
		cin >> x;
		if (minRes > x) {
			minRes = x;
		}
		if (maxRes < x) {
			maxRes = x;
		}
	}
	cout << minRes << " " << maxRes;
}