#include <iostream>
using namespace std;

int fac(int x) {
	int result = 1;
	for (int i = 2; i <= x; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << fac(n) / (fac(k) * fac(n - k));
	
}