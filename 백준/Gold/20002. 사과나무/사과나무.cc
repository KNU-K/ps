#include <iostream>
#include <algorithm>
using namespace std;
int mat[302][302] = {0,};
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
		}
	}
	int maxAns = -2100000000;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j ++) {
			int sizeLimit = min(n - i, n - j);
			for (int k = 0; k <= sizeLimit; k++) {
				maxAns = max(maxAns, mat[i+k][j+k]- mat[i-1][j+k] - mat[i+k][j-1] + mat[i-1][j-1]);
			}
		}
	}
	cout << maxAns << "\n";
}