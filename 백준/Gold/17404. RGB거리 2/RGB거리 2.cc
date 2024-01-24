//R G B
//R G B
#include <iostream>
#define min(x,y) (x>y? y:x)
#define INF 1000001
using namespace std;
int dp[1001][4];
int color[1001][4];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		color[i][1] = r;
		color[i][2] = g;
		color[i][3] = b;
	}
	int ans = INF;
	for (int i = 1; i <= 3; i++) {

		for (int j = 1; j <= 3; j++) {
			if (i == j) dp[1][j] = color[1][j];
			else dp[1][j] = INF;
		}
		for (int j = 2; j <= n; j++) {
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + color[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + color[j][2];
			dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + color[j][3];
		}
		for (int j = 1; j <= 3; j++) {
			if (i == j) continue;
			ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
}