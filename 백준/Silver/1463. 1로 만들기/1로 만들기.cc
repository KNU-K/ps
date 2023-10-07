#include <iostream>
#define min(a,b) (a>b? b: a)
using namespace std;
int dp[1000001] = { 0, };
int solved(int n) {
	if (n == 1) return 0;
	else if (dp[n]) return dp[n];
	int a= 1000001, b= 1000001, c= 1000001;
	if (n % 3 == 0) {
		a=solved(n / 3) +1;
	}
	if (n% 2 ==0) {
		b=solved(n / 2) +1;
	}
	c =solved(n - 1) +1;
	dp[n] = min(min(a, b), c);
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout<<solved(n);
}