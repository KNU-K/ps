#include <iostream>
#include <queue>
#define MAX_SZ 51
using namespace std;
int map[MAX_SZ][MAX_SZ];
int visited[MAX_SZ][MAX_SZ] = { 0, };
int x, y;
typedef struct {
	int x, y;
}POINT;
POINT dirs[8] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
	{1,1},
	{-1,-1},
	{1,-1},
	{-1,1}
};
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < y) && (0 <= p.y && p.y < x);
}
void bfsSearch(POINT p) {
	queue<POINT> q;
	q.push(p);
	visited[p.x][p.y] = 1;
	while (!q.empty()) {
		POINT cur = q.front();
		q.pop();
		for (auto dir : dirs) {
			POINT next = { cur.x + dir.x, cur.y + dir.y };
			if (!isMapLimited(next)) continue;
			if (visited[next.x][next.y] == 1) continue;
			if (map[next.x][next.y] != 1) continue;
			visited[next.x][next.y] = 1;
			q.push(next);
		}
	}
}
int main() {
	while (1) {
		cin >> x >> y;
		if (x == 0 && y == 0)break;
		for (int i = 0; i < y;i++) {
			for (int j = 0; j < x;j++) {
				visited[i][j] = { 0, };
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {

					cnt++;
					bfsSearch({i,j});
				}
			}
		}
		cout << cnt << "\n";

	}
}