#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct {
	int x;
	int y;
}POINT;
string map[51];
int visited[51][51] = { 0, };
POINT dirs[4] = {
	{1,0},{-1,0},{0,1},{0,-1}
};
queue<POINT> animal;
queue<POINT> water;
int n, m;
bool isMapLimited(int nx, int ny) {
	return (0 <= nx && nx < n) && (0 <= ny && ny < m);
}
int bfs() {
	while (!animal.empty()) {
		int waterSize = water.size();
		for (int i = 0; i < waterSize;i++) {
			POINT cur = water.front();
			water.pop();
			for (auto dir:dirs) {
				POINT next = { cur.x + dir.x, cur.y + dir.y };
				if (!isMapLimited(next.x, next.y))continue;
				if (map[next.x][next.y] == '.') {
					map[next.x][next.y] = '*';
					water.push({ next.x,next.y });
				}
			}
		}
		int animalSize = animal.size();
		for (int i = 0; i < animalSize; i++) {
			POINT cur = animal.front();
			animal.pop();
			if (map[cur.x][cur.y] == 'D') return visited[cur.x][cur.y]-1;
			for (auto dir : dirs) {
				POINT next = { cur.x + dir.x, cur.y + dir.y };
				if (!isMapLimited(next.x, next.y)) continue;
				if (map[next.x][next.y] == 'X') continue;
				if (map[next.x][next.y] == '*') continue;
				if (visited[next.x][next.y] != 0) continue;
				if (map[next.x][next.y] == 'D' || map[next.x][next.y] == '.') {
					visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
					animal.push({ next.x, next.y });
				}
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		cin >> map[i];
		for (int j = 0; j < m;j++) {
			if (map[i][j] == 'S') {
				animal.push({ i,j });
				visited[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}
	int rs =bfs();
	if (rs == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << rs;
	}
	return 0;
}