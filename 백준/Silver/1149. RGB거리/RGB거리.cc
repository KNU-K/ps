#include <iostream>
#define min(a,b) (a<b?a:b)
using namespace std;
typedef struct RGB {
	int r, g, b;
}rgb;

rgb homeArr[1001];
rgb dp[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> homeArr[i].r >> homeArr[i].g >> homeArr[i].b;
	}

	dp[1].r = homeArr[1].r;
	dp[1].g = homeArr[1].g;
	dp[1].b = homeArr[1].b;

	for (int i = 2; i <= n; i++) {
		dp[i].r = min(dp[i - 1].g + homeArr[i].r, dp[i - 1].b + homeArr[i].r);
		dp[i].g = min(dp[i - 1].r + homeArr[i].g, dp[i - 1].b + homeArr[i].g);
		dp[i].b = min(dp[i - 1].r + homeArr[i].b, dp[i - 1].g + homeArr[i].b);
	}
	cout << min(dp[n].r, min(dp[n].g,dp[n].b));
}