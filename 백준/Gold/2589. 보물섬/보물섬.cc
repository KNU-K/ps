#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct {
	int x, y;
}POINT;
POINT dirs[4] = {
	{1,0},{-1,0},{0,1},{0,-1}
};
int l, w;

string map[51];
int visited[51][51] = { 0, };
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x <l) && (0 <= p.y && p.y < w);
}
int bfsSearch(POINT cur) {
	int max_rs = 1;
	for (int i = 0; i < l;i++) {
		for (int j = 0; j < w; j++) {
			visited[i][j] = 0;
		}
	}
	queue<POINT> q;
	q.push(cur);
	visited[cur.x][cur.y] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (auto dir : dirs) {
			POINT next = { cur.x + dir.x, cur.y + dir.y };
			if (!isMapLimited(next)) continue;
			if (visited[next.x][next.y] != 0) continue;
			if (map[next.x][next.y] != 'L') continue;
			q.push(next);
			visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
			max_rs = max(max_rs, visited[next.x][next.y]);

		}
	}
	return max_rs-1;
}
int main() {
	cin >> l >> w;
	for (int i = 0; i < l; i++) {
		cin >> map[i];
	}
	int rs = -1;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'L') {
				rs = max( rs,bfsSearch({ i,j }) );
			}
		}
	}
	
	cout << rs;
}