#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int visited[9] = { 0, };
int arr[9];
int result[9];
int printResult[9][9];
int dfsCnt = 0;
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i]<<" ";
		}
		cout << "\n";
		return;
	}
	int xx = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && arr[i] !=xx) {
			visited[i] = 1;
			result[cnt] = arr[i];
			xx = result[cnt];
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}

}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);
}