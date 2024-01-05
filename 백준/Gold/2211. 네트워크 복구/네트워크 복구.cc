#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147000000
using namespace std;
typedef struct {
	int x;
	int y;
	int cost;
}edge;

//vector<edge> v;

vector<pair<int, int>> v[1001];
int dist[1001];
int pv[1001];
//int parent[1001];

//int _find(int x) {
//	if (parent[x] == x) return x;
//	return parent[x] = _find(parent[x]);
//}
//void _union(int x, int y) {
//	x = _find(x);
//	y = _find(y);
//	if (x > y) {
//		parent[y] = x;
//	}
//	else {
//		parent[x] = y;
//	}
//}
//bool cmp(edge &e1, edge& e2) {
//	return e1.cost < e2.cost;
//}
void dijkstra(int sv) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,sv });
	dist[sv] = 0;
	while (!pq.empty()) {
		int cc = pq.top().first;
		int cv = pq.top().second;
		pq.pop();
		
		for (auto e : v[cv]) {
			if (dist[e.first] > dist[cv] + e.second) {
				dist[e.first] = dist[cv] + e.second;
				pq.push({ dist[e.first], e.first });
				pv[e.first] = cv;
			}
		}
	}
}
int main() {
	vector<pair<int,int>> ans;
	int n, m;
	cin >> n >> m;
	/*for (int i = 1; i <= n;i++) {
		parent[i] = i;
	}*/
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
		v[y].push_back({ x,c });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		pv[i] = i;
	}

	dijkstra(1);
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << pv[i] << " " << i<<"\n";
	}

	//
	//sort(v.begin(), v.end(), cmp);
	//for (auto e: v) {
	//	if (_find(e.x) != _find(e.y)) {
	//		_union(e.x, e.y);
	//		ans.push_back({ e.x, e.y });
	//	}
	//}
	//cout << ans.size() << "\n";
	//for (auto r : ans) {
	//	cout << r.first << " " << r.second << "\n";
	//}
}