#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

vector<pair<int, int>> graphRelations[1001];
int parent[1001] = { 0, };
int n, m;
int costs[1001];
int start, dest;
void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	costs[start] = 0;
	while (!pq.empty()) {
		int curW = pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		for (auto next : graphRelations[curV]) {
			int nextW = next.second + curW;
			int nextV = next.first;

			if (costs[nextV] > nextW) {
				costs[nextV] = nextW;
				parent[nextV] = curV;
				pq.push({ nextW, nextV });
			}

		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graphRelations[v1].push_back({ v2,w });
	}
	cin >> start >> dest;
	for (int i = 1; i <= n;i++) {
		costs[i] = INF;
		sort(graphRelations[i].begin(), graphRelations[i].end());
	}
	dijkstra();
	vector<int> result;
	cout << costs[dest] << "\n";

	int temp = dest;
	while (temp) {
		result.push_back(temp);
		temp = parent[temp];
	}

	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	
	
}