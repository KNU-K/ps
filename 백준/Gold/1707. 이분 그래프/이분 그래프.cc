#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[20001];
int visited[20001] = { 0, };
void bfs(int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = 1;
	while (!q.empty()) {
		int curx = q.front();
		q.pop();

		for (auto nx : graph[curx]) {
			if (visited[nx] != 0) continue;
			
			visited[nx] = (visited[curx] == 1 ? 2 : 1);
			q.push(nx);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		bool isNop = false;
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= v; i++) {
			if(!visited[i])
				bfs(i);
		}


		for (int i = 1; i <= v; i++) {
			for (auto g : graph[i]) {
				if (visited[i] == visited[g]) {
					isNop = true;
					break;
				}
				else {
					isNop = false;
				}
			}
			if (isNop)break;
		}
		if (isNop)cout << "NO\n";
		else cout << "YES\n";

		for (int i = 1; i <= v; i++) {
			visited[i] = 0;
			graph[i].clear();
		}
	}
}