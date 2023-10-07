#include <iostream>
using namespace std;
int coins[10];
int main() {

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) cin >> coins[i];
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= coins[i]) {
			cnt += k / coins[i];
			k = k - (coins[i] * (k / coins[i]));
		}
	}
	cout << cnt;
}
