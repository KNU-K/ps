#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mat[100001];
int visited[100001] = {0,};
int results[100001];
void dfs(int s) {
	visited[s] = 1;
	for (auto nv : mat[s]) {
		if (!visited[nv]) {
			results[nv] = s;
			dfs(nv);
		}
	}
}
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n-1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		mat[v1].push_back(v2);
		mat[v2].push_back(v1);
	}
	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout << results[i] << "\n";
	}
}