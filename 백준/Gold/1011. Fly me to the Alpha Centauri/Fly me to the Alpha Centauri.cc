#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		int n = y - x;
		int m = ((int)sqrt(n));
		if (m < sqrt(n)) {
			if (m * m + m < n) {
				cout << (m + 1) * 2 - 1 << "\n";
			}
			else{
				cout << m * 2 << "\n";
			}
		}
		else{
			cout << m * 2 - 1 << "\n";
		}
}
}