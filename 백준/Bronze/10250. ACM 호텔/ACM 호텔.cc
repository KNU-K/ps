#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int findRoom(int h, int w, int n) {
	int cnt = 0;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cnt++;
			if (cnt == n) {
				cout << (j * 100) + i<<"\n";
				return 0;
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		double h, w, n;
		cin >> h >> w >> n;
		findRoom(h, w, n);
	}
}