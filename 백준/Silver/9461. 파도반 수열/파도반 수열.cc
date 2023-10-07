#include <iostream>
using namespace std;
long long dp[101] = { 0, };
long long seq(int n) {
	if (n == 1 || n == 2 || n == 3) return 1;
	else{
		if (dp[n] != 0) return dp[n];
		dp[n] = seq(n - 2) + seq(n - 3);
		return dp[n];
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << seq(n) << "\n";
	}
}