#include <iostream>
using namespace std;

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && b == 0) {
			return 0;
		}
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (b > c) {
			int temp = b;
			b = c;
			c = temp;
		}
		if (c * c == (a * a) + (b * b)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}