#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[502];
int visited[502] = { 0, };
int v, e;
int cnt = 0;
void bfs(int sv) {
	queue<int> q;
	visited[sv] = 1;
	q.push(sv);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited[cur] == 3) return;
		for (auto next : graph[cur]) {
			if (visited[next] != 0) continue;
			cnt++;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
}
int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs(1);
	cout << cnt;
}