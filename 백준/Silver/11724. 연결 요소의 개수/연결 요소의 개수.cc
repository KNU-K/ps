#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> map[1001];
int visited[1001] = { 0, };
void bfsSearch(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nv:map[cur]) {
			if (!visited[nv]) {
				visited[nv] = 1;
				q.push(nv);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m;i++) {
		int x, y;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}
	int cnt = 0;
	for (int i = 1; i <= n;i++) {
		if (!visited[i]) {
			bfsSearch(i);
			cnt++;
		}
	}
	cout << cnt;
}