#include <iostream>
#include <vector>
#include <queue>
#define UPPER_INF 1000000
#define LOWER_INF 1
using namespace std;

int building_visited[UPPER_INF + 1] = {0,};
int	f, s, g, u, d;
queue<int> q;

int bfs_search(int cur) {
	int nex;
	q.push(cur);
	building_visited[cur] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur == g) {
			return building_visited[cur];
		}
		nex = cur + u;
		if (nex <= f && building_visited[nex] == 0) {
			building_visited[nex] = building_visited[cur] + 1;
			q.push(nex);
		}

		nex = cur - d;
		if (LOWER_INF <= nex && building_visited[nex] == 0) {
			building_visited[nex] = building_visited[cur] + 1;
			q.push(nex);
		}
		
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	int rs = bfs_search(s);
	if (rs == -1) {
		cout << "use the stairs\n";
	}
	else {
		cout << rs-1 << "\n";
	}
	return 0;
}