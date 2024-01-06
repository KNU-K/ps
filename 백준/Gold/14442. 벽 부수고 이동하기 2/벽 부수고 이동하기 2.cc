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

typedef struct {
	POINT p;
	int crush;
}MOVE;
string map[1001];	
int visited[11][1001][1001] = { 0, };
int n, m,k;
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < m);
}
int bfs(POINT p) {
	queue<MOVE> q;
	q.push({ p , 0});
	visited[0][p.x][p.y] = 1;
	while (!q.empty()) {
		MOVE cur = q.front();
		q.pop();
		if (cur.p.x == 0 && cur.p.y == 0) {
			return visited[cur.crush][cur.p.x][cur.p.y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.p.x + dir[i].x;
			int ny = cur.p.y + dir[i].y;
			
			if (!isMapLimited({ nx,ny }))continue;
			if (visited[cur.crush][nx][ny] != 0) continue;
			if (map[nx][ny] == '0') {
	
				visited[cur.crush][nx][ny] = visited[cur.crush][cur.p.x][cur.p.y] + 1;
				q.push({ { nx,ny }, cur.crush });
			}
			else {
				// 벽일 때,
				if (cur.crush == k) continue;
				visited[cur.crush+1][nx][ny] = visited[cur.crush][cur.p.x][cur.p.y] + 1;
				q.push({ { nx,ny }, cur.crush +1});
			}

		}
	}
	return -1;
}
int main() {
	cin >> n >> m>>k;
	for (int i = 0;i<n;i++) {
		cin >> map[i];
	}

	cout << bfs({ n-1,m-1 });
	
}