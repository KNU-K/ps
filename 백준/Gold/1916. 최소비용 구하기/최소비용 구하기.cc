#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2100000000
using namespace std;

vector<pair<int,int>> graphRelations[1001];
int costs[1001];
int startVertax, endVertax;

void dijkstra() {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,startVertax });
	costs[startVertax] = 0;

	while (!pq.empty()) {
		int curW = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		for (auto graphRelation : graphRelations[curV]) {
			int nextW = graphRelation.second + curW;
			int nextV = graphRelation.first;

			if (costs[nextV] > nextW) {
				costs[nextV] = nextW;
				pq.push({costs[nextV], nextV});
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graphRelations[v1].push_back({ v2,w });
	}
	for (int i = 1; i <= n; i++) {
		sort(graphRelations[i].begin(), graphRelations[i].end());
		costs[i] = INF;
	}
	cin >> startVertax >> endVertax;

	dijkstra();
	cout << costs[endVertax];
}