#include <iostream>
#include <queue>
#include <vector>
#define INF 2100000000
using namespace std;
vector<pair<int, int>> v[801];
int dist[801];

void dijkstra(int sv, int ev) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, sv });
	dist[sv] = 0;
	while (!pq.empty()) {
		int cv = pq.top().second;
		int cw = pq.top().first;
		pq.pop();
		if (cv == ev) return;
		for (auto next:v[cv]) {
			int nv = next.first;
			int nw = next.second;
			if (dist[nv] > dist[cv] + nw) {
				dist[nv] = dist[cv] + nw;
				pq.push({ dist[nv], nv });
			}
		}
	}

}
int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}

	int a, b;
	cin >> a >> b;
	
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	//1 ~ a b~n
	//1 ~ b a~n
	int first = 0;
	dijkstra(1, a);
	if (dist[a] == INF) {
		cout << "-1";
		return 0;
	}
	first += dist[a];

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(a, b);
	if (dist[b] == INF) {
		cout << "-1";
		return 0;
	}
	first += dist[b];


	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(b, n);
	if (dist[n] == INF) {
		cout << "-1";
		return 0;
	}
	first+= dist[n];


	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	//1 ~ a b~n
	//1 ~ b a~n
	int sec = 0;
	dijkstra(1, b);
	if (dist[b] == INF) {
		cout << "-1";
		return 0;
	}
	sec += dist[b];

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(b, a);
	if (dist[a] == INF) {
		cout << "-1";
		return 0;
	}
	sec += dist[a];


	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(a, n);
	if (dist[n] == INF) {
		cout << "-1";
		return 0;
	}
	sec += dist[n];
	cout << (first > sec ? sec : first);
}