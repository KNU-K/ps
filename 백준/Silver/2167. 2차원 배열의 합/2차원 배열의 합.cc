#include <iostream>
using namespace std;
int arr[302][302] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << arr[x][y] - arr[i - 1][y] - arr[x][j - 1] + arr[i - 1][j- 1]<<"\n";
	}
}