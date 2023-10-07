#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;
vector<pair<int,int>> tree[10001];
int costs[10001];
void dijkstra(int s) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,s });
	costs[s] = 0;
	while (!pq.empty()) {
		int curW = pq.top().first;
		int curV = pq.top().second;
		pq.pop();


		for (auto next : tree[curV]) {
			int nextW = curW + next.second;
			int nextV = next.first;
			if (nextW < costs[nextV]) {
				costs[nextV] = nextW;
				pq.push({ nextW, nextV });
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		tree[v1].push_back({ v2,w });
		tree[v2].push_back({ v1,w });
	}
	for (int i = 1; i <= n; i++) {
		sort(tree[i].begin(), tree[i].end());
		costs[i] = INF;
	}
	dijkstra(1);
	int maxNum = costs[1];
	int maxNumIdx = 1;
	for (int i = 2; i <= n; i++) {
		if (costs[i] > maxNum) {
			maxNum = costs[i];
			maxNumIdx = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		costs[i] = INF;
	}
	dijkstra(maxNumIdx); 
	maxNum = costs[1];
	for (int i = 1; i <= n; i++) {
		if (costs[i] > maxNum) {
			maxNum = costs[i];
		}
	}
	cout << maxNum;

}