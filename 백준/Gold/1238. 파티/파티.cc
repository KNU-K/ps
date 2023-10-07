#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2100000000
using namespace std;

int n, m, x;
int costs[1001];
int result;
vector<pair<int, int>> graphRelations[1001];
void dijkstra(int sv, int dv) {
	for (int i = 1; i <= n; i++) {
		costs[i] = INF;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, sv });
	costs[sv] = 0;
	while (!pq.empty()) {
		int curV = pq.top().second;
		int curW = pq.top().first;
		pq.pop();
		if (curV == dv) {
			result = costs[curV];
			break;
		}
		for (auto next : graphRelations[curV]) {
			int nextV = next.first;
			int nextW = next.second + curW;
 			if (costs[nextV] > nextW) {
				costs[nextV] = nextW;
				pq.push({ nextW, nextV });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graphRelations[v1].push_back({ v2,w });
	}
	for (int i = 1; i <= n; i++) {
		costs[i] = INF;
		sort(graphRelations[i].begin(), graphRelations[i].end());
	}
	int maxResult = -1;
	for (int i = 1; i <= n; i++) {
		dijkstra(i,x);
		int a = result;
		dijkstra(x,i);

		int b = result;
		int endResult = costs[i];
		if (maxResult < (a+b)) {
			maxResult = (a+b);
		}
	}
	cout << maxResult;
}