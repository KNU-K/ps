#include <iostream>
#include <queue>
#define INF 2100000000
using namespace std;
typedef struct {
	int x, y;
}POINT;
POINT dirs[4] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};
string map[101];
int visited[101][101];
int m, n;
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < m);
}
void bfs(POINT sv) {
	queue<POINT> q;
	q.push(sv);
	visited[sv.x][sv.y] = 0;

	while (!q.empty()) {
		POINT cur = q.front();
		q.pop();
		for (auto dir:dirs) {
			POINT next = { cur.x + dir.x, cur.y + dir.y };
			if (!isMapLimited(next))continue;
			if (visited[next.x][next.y] > visited[cur.x][cur.y] + (int)(map[next.x][next.y] - '0')) {
				visited[next.x][next.y] = visited[cur.x][cur.y] + (int)(map[next.x][next.y] - '0');
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n;i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			visited[i][j] = INF;
		}
	}
	bfs({0,0});

	cout << visited[n-1][m-1];
}