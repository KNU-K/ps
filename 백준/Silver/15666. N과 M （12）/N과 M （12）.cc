#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int visited[9] = { 0, };
int arr[9];
int result[9];
int printResult[9][9];
int dfsCnt = 0;
void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i]<<" ";
		}
		cout << "\n";
		return;
	}
	int x = 0;
	for (int i = num; i < n; i++) {
		if (!visited[i] && arr[i] !=x) {
			result[cnt] = arr[i];
			x = result[cnt];
			dfs(i, cnt + 1);
		}
	}

}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0,0);
}