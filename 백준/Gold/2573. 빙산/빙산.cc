#include <iostream>
#include <queue>
#define INF 301
using namespace std;

/*
예제 입력 
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

예제 출력 
2
*/
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
int n, m;
int map[INF][INF];
int mapOfTotalZero[INF][INF];
int visited[INF][INF] = { 0, };
bool isMapLimited(int nx, int ny) {
	return (0 <= nx && nx < n) && (0 <= ny && ny <= m);
}
void bfs_search(int cx, int cy) {
	queue<POINT> q;
	int nx, ny;
	q.push({ cx,cy });
	visited[cx][cy] = 1;
	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();

		int totalSizeOfZero = 0;
		for (int i = 0; i < 4;i++) {
			nx = cx + dir[i].x;
			ny = cy + dir[i].y;
			if (!isMapLimited(nx, ny))continue;
			if (visited[nx][ny] != 0) continue;
			if (map[nx][ny] != 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
			else {
				totalSizeOfZero++;

			}
		}
		mapOfTotalZero[cx][cy] = totalSizeOfZero;
		
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int a = 0; ;a++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] != 0) {
					bfs_search(i, j);
					cnt++;
				}
				if (cnt >= 2) {
					cout << a << "\n";
					return 0;
				}
			}
		}
		if (cnt == 0) {
			cout << 0 << "\n";
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int tmp = map[i][j] - mapOfTotalZero[i][j];
				if (tmp <= 0) map[i][j] = 0;
				else map[i][j] = tmp;
			}
		}
	}


}