#include <iostream>
using namespace std;
int n, m;
int visited[9] = {0,}; // 0 ~ 8
int arr[9];
void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m;i++) {
			cout<< arr[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[cnt] = i;
			dfs(i+1, cnt+1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	dfs(1,0);
}