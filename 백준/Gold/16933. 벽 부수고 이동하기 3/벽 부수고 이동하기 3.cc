#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int x;
	int y;
}POINT;

POINT dir[4] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
int reverse_dir[4] = {
	1,0,3,2
};
typedef struct {
	POINT p;
	int crush;
	bool isMorning;
}MOVE;
string map[1001];	
int visited[2][11][1001][1001] = { 0, };
int n, m,k;
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < m);
}
int bfs(POINT p) {
	queue<MOVE> q;
	q.push({ p , 0, true});
	visited[0][0][p.x][p.y] = 1;
	while (!q.empty()) {
		MOVE cur = q.front();
		q.pop();
		if (cur.p.x == n-1 && cur.p.y == m-1) {
			return visited[(cur.isMorning ? 0 : 1)][cur.crush][cur.p.x][cur.p.y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.p.x + dir[i].x;
			int ny = cur.p.y + dir[i].y;
			if (!isMapLimited({ nx,ny }))continue;
			if (visited[(cur.isMorning ? 1 : 0)][cur.crush][nx][ny] != 0) continue;
			if (map[nx][ny] == '0') {
				if (visited[(cur.isMorning ? 1 : 0)][cur.crush][nx][ny] != 0) continue;

				visited[(cur.isMorning ? 1 : 0)][cur.crush][nx][ny] = visited[(cur.isMorning ? 0 : 1)][cur.crush][cur.p.x][cur.p.y] + 1;
				q.push({ { nx,ny }, cur.crush,  (cur.isMorning ? false : true)});
			}
			else {
				// 벽일 때,
				
				if (cur.crush == k) continue;
				
				if (cur.isMorning) {
					if (visited[(cur.isMorning ? 1 : 0)][cur.crush + 1][nx][ny] != 0) continue;

					visited[(cur.isMorning ? 1 : 0)][cur.crush + 1][nx][ny] = visited[(cur.isMorning ? 0 : 1)][cur.crush][cur.p.x][cur.p.y] + 1;
					q.push({ { nx,ny }, cur.crush + 1,(cur.isMorning ? false : true)});
				}
			}


		}
		if (!cur.isMorning) {
			if (visited[(cur.isMorning ? 1 : 0)][cur.crush][cur.p.x][cur.p.y] != 0) continue;

			visited[(cur.isMorning ? 1 : 0)][cur.crush][cur.p.x][cur.p.y] = visited[(cur.isMorning ? 0 : 1)][cur.crush][cur.p.x][cur.p.y] + 1;
			q.push({ cur.p, cur.crush,(cur.isMorning ? false : true) });
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m>>k;
	for (int i = 0;i<n;i++) {
		cin >> map[i];
	}
	
	
	cout << bfs({ 0,0 })<<"\n";

}