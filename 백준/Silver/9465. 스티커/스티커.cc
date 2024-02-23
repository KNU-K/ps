#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][100002] = { 0, };
int arr[2][100002] = { 0, };
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int x = 0; x < 2;x++) {
			for (int i = 2; i <= n+1; i++) {
				cin >> arr[x][i];
			}
		}
		
		for (int i = 2; i <= n+1;i++) {
			arr[0][i] += max(arr[1][i - 1], arr[1][i - 2]);
			arr[1][i] += max(arr[0][i - 1], arr[0][i - 2]);
		}
		cout << max(arr[0][n+1], arr[1][n+1])<<"\n";
	}
}