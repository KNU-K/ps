#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> nodeRelations[101];
int visited[101] = { 0, };
int bfsSearch(int curVertax) {
	int cnt = 1;
	queue<int> q;
	q.push(curVertax);
	visited[curVertax] = 1;
	while (!q.empty()) {
		int curVertax = q.front();
		q.pop();
		for (int nextVertax : nodeRelations[curVertax]) {
			if (!visited[nextVertax]) {
				q.push(nextVertax);
				visited[nextVertax] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		nodeRelations[v1].push_back(v2);
		nodeRelations[v2].push_back(v1);
	}
	for (int i = 1; i <= n;i++) {
		sort(nodeRelations[i].begin(), nodeRelations[i].end());
	}
	cout<<bfsSearch(1)-1;
}