#include <iostream>
using namespace std;
bool primeNum[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 2; i < 1001; i++) {
		primeNum[i] = true;
	}
	for (int i = 2; i < 1001; i++) {
		if (primeNum[i]) {
			for (int j = i * 2; j < 1001; j += i) {
				primeNum[j] = false;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (primeNum[x] == true) {
			cnt++;
		}
	}
	cout << cnt;
}