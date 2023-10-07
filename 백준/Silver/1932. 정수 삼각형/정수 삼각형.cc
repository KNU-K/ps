#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[501][501] = { 0, };
int arr[501][501] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	if (n == 1) {
		cout << arr[1][1];
		return 0;
	}
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i) {
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(arr[i][j] + dp[i - 1][j], arr[i][j] + dp[i - 1][j - 1]);
			}
		}
	}
	int maxResult = -1;
	for (int i = 1; i <= n; i++) {
		maxResult = max(maxResult,dp[n][i]);
	}
	cout << maxResult;
}