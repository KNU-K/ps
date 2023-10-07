#include <iostream>
using namespace std;
int dp[10001] = { 0, };
int findSolution(int n) {
	if (n == 1) return 1;
	
	if (dp[n]) return dp[n];

	if (n % 2 == 0) {
		dp[n] = (findSolution(n - 1) * 2 + 1)%10007;
	}
	else {
		dp[n] = (findSolution(n - 1) * 2 - 1)%10007;
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << findSolution(n);
}