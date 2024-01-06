#include <iostream>
#include <queue>
#define INF 2100000000
using namespace std;
int map[127][127];
int visited[127][127];
int n;
typedef struct {
	int x, y;
}POINT;
POINT dirs[4] = { {1,0},{-1,0},{0,1},{0,-1} };
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < n);
}
void dijkstra(POINT sv) {
	priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
	pq.push({ map[sv.x][sv.y], {sv.x,sv.y} });
	visited[sv.x][sv.y] = map[sv.x][sv.y];
	while (!pq.empty()) {
		int cw = pq.top().first;
		POINT cv = { pq.top().second.first, pq.top().second.second};
		pq.pop();

		for (auto dir : dirs) {
			POINT nv = { cv.x + dir.x , cv.y + dir.y };
			if (!isMapLimited(nv)) continue;
			int nw = map[nv.x][nv.y] + cw;
			if (visited[nv.x][nv.y] > nw) {
				visited[nv.x][nv.y] = nw;
				pq.push({ visited[nv.x][nv.y],{nv.x,nv.y} });
			}
		}
		
	}
}
int main() {
	int step = 0;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visited[i][j] = INF;
			}
		}

		dijkstra({0,0});
		cout << "Problem "<<++step<<": "<<visited[n - 1][n - 1] << "\n";
	}
}