#include <iostream>
#include <queue>
using namespace std;
vector<int> mat[32001];
int degree[32001];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		mat[x].push_back(y);
		degree[y]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int i = 0; i < mat[cur].size(); i++) {
			int nc = mat[cur][i];

			degree[nc]--;
			if (degree[nc] == 0) {
				pq.push(nc);
			}
		}
	}

}