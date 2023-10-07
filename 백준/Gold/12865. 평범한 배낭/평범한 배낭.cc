#include <iostream>
using namespace std;
typedef struct {
	int w, v;
}info;
int dp[102][100002] = { 0, };
info cur[102];
/*
4 7

6 13
4 8
3 6
5 12
*/
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cur[i].w >> cur[i].v;
		for (int j = 1; j <= k; j++) {
			if (cur[i].w > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-cur[i].w]+cur[i].v);
			}
		}
	}
	cout << dp[n][k];
}