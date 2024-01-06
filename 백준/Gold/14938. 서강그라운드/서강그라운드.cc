#include <iostream>
#include <queue>
#include <vector>
#define INF 2140000000
using namespace std;
int dist[101];
int items[101];
vector<pair<int, int>> v[101];
int n, m, r;
void dijkstra(int sv) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,sv });
	dist[sv] = 0;
	while (!pq.empty()) {
		int cv = pq.top().second;
		int cw = pq.top().first;
		pq.pop();

		for (auto next: v[cv]) {
			int nv = next.first;
			int nw = next.second + cw;
			if (nw > m) continue;
			if (dist[nv] > nw) {
				dist[nv] = nw;
				pq.push({ dist[nv], nv });
			}
		}
	}
}
int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n;i++) {
		cin >> items[i];
		dist[i] = INF;
	}

	for (int i = 0; i < r;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
	int rs = -1;
	int ans = 0;
	for (int i = 1; i <= n;i++) {
		dijkstra(i);
		
		for (int j = 1; j <= n; j++) {
			if (dist[j] != INF) {
				ans += items[j];
				dist[j] = INF;
			}
		}
		rs = (rs < ans ? ans : rs);

		ans = 0;
	}
	cout << rs;
}