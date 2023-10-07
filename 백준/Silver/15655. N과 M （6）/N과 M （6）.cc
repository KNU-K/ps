#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int visited[9] = { 0, };
int arr[9];
int result[9];
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] <<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			result[cnt] = arr[i];
			dfs(i +1,cnt + 1);
			visited[i] = 0;
		}
	}

}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0,0);
}