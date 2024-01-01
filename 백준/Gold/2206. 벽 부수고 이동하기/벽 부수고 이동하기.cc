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
	bool isJump;
}MOVE;
string map[1001];
int visited[2][1001][1001] = { 0, };

int n, m;
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < m);
}
int bfs(POINT p) {
	queue<MOVE> q;
	q.push({ p , false});
	visited[0][p.x][p.y] = 1;
	while (!q.empty()) {
		MOVE cur = q.front();
		q.pop();
		if (cur.p.x == 0 && cur.p.y == 0) {
			return visited[cur.isJump][cur.p.x][cur.p.y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.p.x + dir[i].x;
			int ny = cur.p.y + dir[i].y;
			
			if (!isMapLimited({ nx,ny }))continue;
			if (visited[cur.isJump][nx][ny] != 0) continue;
			if (map[nx][ny] == '0') {
	
				visited[cur.isJump][nx][ny] = visited[cur.isJump][cur.p.x][cur.p.y] + 1;
				q.push({ { nx,ny }, cur.isJump });
			}
			else {
				// 벽일 때,
				if (cur.isJump) continue;
				visited[1][nx][ny] = visited[0][cur.p.x][cur.p.y] + 1;
				q.push({ { nx,ny }, true });
			}

		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0;i<n;i++) {
		cin >> map[i];
	}

	cout << bfs({ n-1,m-1 });
	
}