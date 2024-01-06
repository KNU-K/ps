#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int dist[10001];
vector<pair<int, int>> v[10001];
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
			if (dist[nv] > nw) {
				dist[nv] = nw;
				pq.push({ dist[nv], nv });
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> r;
		
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			v[y].push_back({ x,w });
		}
		for (int i = 1; i <= 10000; i++) {
			dist[i] = INF;
		}
		dijkstra(r);
		int maxrs = -1;
		int cntrs = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				cntrs++;
				maxrs = (maxrs < dist[i] ? dist[i] : maxrs);
			}
			v[i].clear();
		}
		cout << cntrs << " " << maxrs << "\n";
		
	}
}