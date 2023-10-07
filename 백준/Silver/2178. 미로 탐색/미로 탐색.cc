#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef struct POINT {
	int x, y;
}p;
p dir[4] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0} };
int n, m;
int map[101][101]={0, };
int visited[101][101] = { 0, };
bool isMapLimited(p vPoint) {
	return ((0 <= vPoint.x < n) && (0 <= vPoint.y < m));
}
int bfsSearch(int x,int y) {
	queue<p> movePoints;
	movePoints.push({ x,y });
	visited[x][y] = 1;
	while (!movePoints.empty()) {
		p cur = movePoints.front();
		movePoints.pop();
		if (cur.x == n - 1 && cur.y == m - 1) return visited[cur.x][cur.y];
		for (int i = 0; i < 4; i++) {
			p next = {cur.x+dir[i].x, cur.y + dir[i].y};
			if (!isMapLimited(next))continue;
			
			if (!visited[next.x][next.y] && map[next.x][next.y] == 1) {
				visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
				movePoints.push(next);
			}
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	cout << bfsSearch(0,0);


}