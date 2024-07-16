#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long univ[2001][2001];
long long ans[2001][2001];
int N, M;

void printMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
}

void solve() {
	
	int r = M / 2;
	int start = r;
	int end = N - r;
	             
	for (int i = start; i < end; i++) {
		for (int j = start; j < end; j++) {
			ans[i][j] = univ[i - r][j - r];
			if (i - r - 1 >= 0) 
				ans[i][j] -= univ[i - r - 1][j - r];
			if (j - r - 1 >= 0) 
				ans[i][j] -= univ[i - r][j - r - 1];
			if (i - r - 1 >= 0 && j - r - 1 >= 0) 
				ans[i][j] += univ[i - r - 1][j - r - 1];
			if (i - M >= 0)
				ans[i][j] += ans[i - M][j];
			if (j - M >= 0)
				ans[i][j] += ans[i][j - M];
			if (i - M >= 0 && j - M >= 0)
				ans[i][j] -= ans[i - M][j - M];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long num; cin >> num;
			univ[i][j] = -1 * num;
		}
	}

	solve();
	printMap();
}