#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef struct POINT {
	int x, y;
}p;
p dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int visited[26][26] = {0,};
int map[26][26] = { 0, };
int n;
bool isMapLimited(p pivot) {
	return (0 <= pivot.x && pivot.x < n) && (0 <= pivot.y && pivot.y < n);
}
int bfsSearch(p point) {
	queue<p> q;
	q.push(point);
	visited[point.x][point.y] = 1;
	int rtn = 1;
	while (!q.empty()) {
		p cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			p next = { cur.x + dir[i].x, cur.y + dir[i].y };
			if (!isMapLimited(next)) continue;
			if (!visited[next.x][next.y] && map[next.x][next.y] == 1) {
				visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
				q.push(next);
				rtn++;
				
				
			}
		}
	}
	return rtn;


}
int main() {
	vector<int> apartments;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1&&!visited[i][j]) {
				cnt++;
				apartments.push_back(bfsSearch({i, j}));
			}
		}
	}
	cout << cnt << "\n";
	sort(apartments.begin(), apartments.end());
	for (int apartment : apartments) {
		cout << apartment << "\n";
	}
}