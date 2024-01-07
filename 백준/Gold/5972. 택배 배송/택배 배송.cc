#include <iostream>
#include <vector>
#include <queue>
#define INF 2140000000
using namespace std;

vector<pair<int, int>> graph[50001];
int dist[50002];
int n, m;

void dijkstra(int sv, int ev) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,sv });
	dist[sv] = 0;

	while (!pq.empty()) {
		int cw = pq.top().first;
		int cv = pq.top().second;
		pq.pop();
		
		for (auto next : graph[cv]) {
			int nw = dist[cv] + next.second;
			int nv = next.first;
			if (dist[nv] > nw) {
				dist[nv] = nw;
				pq.push({ dist[nv], nv });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({ y,w });
		graph[y].push_back({ x,w });
	}
	
	for (int i = 1; i <= n;i++) {
		dist[i] = INF;
	}
	
	dijkstra(1,n);
	cout << dist[n];
}