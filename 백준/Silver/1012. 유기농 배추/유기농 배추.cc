#include <iostream>
#include <queue>
using namespace std;
typedef struct POINT{
	int x, y;
}p;
p dir[4] = { {0,1},
			{0,-1},
			{1,0},
			{-1,0} };
int m, n, k;
int mat[51][51] = { 0, };
int visited[51][51] = { 0, };
bool isMapLimitChecked(p point) {
	return (0 <= point.x && point.x < m) && (0 <= point.y && point.y < n);
}
void bfsSearch(int x, int y) {
	queue<p> q;
	q.push({x,y});
	while (!q.empty()) {
		p cur = q.front();
		q.pop();
		for (int i = 0; i < 4;i++) {
			p next = { cur.x + dir[i].x, cur.y + dir[i].y };
			if (!isMapLimitChecked(next))continue;
			if (mat[next.x][next.y] == 1 && !visited[next.x][next.y]) {
				visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		
		cin >> m >> n >> k;
		for (int i = 0; i < 51;i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = 0;
				mat[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			mat[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1 && !visited[i][j]) {
					bfsSearch(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}