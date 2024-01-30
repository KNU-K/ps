#include <iostream>
#include <algorithm>
using namespace std;
int dp[5001];

int main() {
	int n;
	cin >> n;
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	/*
	dp[6] = dp[3] + 1 = 2;
	dp[7] = -1;
	dp[8] = dp[3] + 1||dp[5] + 1 = 2;
	dp[9] 
	*/
	for (int i = 6; i <= n;i++) {
		
		dp[i] = ((dp[i - 3] == -1 && dp[i - 5] == -1) ? -1 :
			(dp[i - 3] == -1 ? dp[i - 5] + 1 :
				(dp[i - 5] == -1 ? dp[i - 3] + 1 :
					min(dp[i - 3] + 1, dp[i - 5] + 1))));
	}
	cout << dp[n];
}