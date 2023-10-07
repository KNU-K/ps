#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
int arr[301] = { 0, };
int dp[301] = { 0, };
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) cin >> arr[i];
	
	dp[1] = arr[1];
	dp[2] = max(dp[1], dp[1] + arr[2]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= t; i++) {
		dp[i] = max(dp[i-2] + arr[i], dp[i-3]+arr[i-1]+arr[i]);
	}
	cout << dp[t];
	
}