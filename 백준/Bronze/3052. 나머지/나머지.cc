#include <iostream>
using namespace std;
int remainder1[42] = { 0, };
int main() {
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		remainder1[x % 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42;i++) {
		if (remainder1[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;
}
