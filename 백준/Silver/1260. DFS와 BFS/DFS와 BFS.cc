#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, v;
vector<int> nodeRelations[1001];
bool visited[1001];
void dfsSearch(int curVertax) {
	cout << curVertax << " ";
	visited[curVertax] = true;
	for (int nextVertax : nodeRelations[curVertax]) {
		if (!visited[nextVertax]) {
			dfsSearch(nextVertax);
		}
	}
}
void bfsSearch(int curVertax) {
	queue<int> q;
	q.push(curVertax);
	visited[curVertax] = true;
	while (!q.empty()) {
		int curVertax = q.front();
		cout << curVertax << " ";
		q.pop();
		for (int nextVertax : nodeRelations[curVertax]) {
			if (!visited[nextVertax]) {
				q.push(nextVertax);
				visited[nextVertax] = true;
			}
		}
	}

}
void initializeVisited() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		nodeRelations[v1].push_back(v2);
		nodeRelations[v2].push_back(v1);
	}
	for (int i = 1; i <= n;i++) {
		sort(nodeRelations[i].begin(), nodeRelations[i].end());
	}
	dfsSearch(v);
	cout << "\n";
	initializeVisited();
	bfsSearch(v);
}