#include <iostream>
using namespace std;
int dp[12];
int solve(int x) {
	if (x == 1)return 1;
	else if (x == 2)return 2;
	else if (x == 3)return 4;
	else {
		if (dp[x] != -1) return dp[x];
		else {
			dp[x] = solve(x-1) + solve(x - 2) + solve(x - 3);
			return dp[x];
		}
	}
}
int main() {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int n;
	cin >> n;
	for (int i = 0; i < 12;i++) {
		dp[i] = -1;
	}
	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;
		cout <<solve(x)<<"\n";
		
	}
}