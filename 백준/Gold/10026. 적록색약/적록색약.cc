#include <iostream>
#include <queue>
using namespace std;

typedef struct POINT { int x, y; }p;
p dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int map[101][101] = { 0, };
int visitedNormal[101][101] = { 0, };
int visitedUnNormal[101][101] = { 0, };
int n;
bool isMapLimited(p point) {
	return (0 <= point.x && point.x < n) && (0 <= point.y && point.y < n);
}
void bfsSearchNormal(p sv) {
	queue<p> moves;
	moves.push(sv);
	visitedNormal[sv.x][sv.y] = 1;
	while (!moves.empty()) {
		p cur = moves.front();
		moves.pop();

		for (int i = 0; i < 4; i++) {
			p next = { cur.x + dir[i].x, cur.y + dir[i].y };
			if (!isMapLimited(next)) continue;
			if (map[next.x][next.y] == map[cur.x][cur.y] && !visitedNormal[next.x][next.y]) {
				moves.push(next);
				visitedNormal[next.x][next.y] = 1;
			}
		}
	}

}
void bfsSearchUnNormal(p sv, int curColor) {
	queue<p> moves;
	moves.push(sv);
	visitedUnNormal[sv.x][sv.y] = 1;
	while (!moves.empty()) {
		p cur = moves.front();
		curColor = map[cur.x][cur.y];
		moves.pop();

		for (int i = 0; i < 4;i++) {
			p next = { cur.x + dir[i].x, cur.y + dir[i].y };
			if (!isMapLimited(next)) continue;
			if (visitedUnNormal[next.x][next.y]) continue;
			if ((map[cur.x][cur.y] == 1 || map[cur.x][cur.y] == 2) && (map[next.x][next.y] == 1 || map[next.x][next.y] == 2)) {
				moves.push(next);
				visitedUnNormal[next.x][next.y] = 1;
			}
			else if (map[cur.x][cur.y] == 3 && map[cur.x][cur.y] == map[next.x][next.y]) {
				moves.push(next);
				visitedUnNormal[next.x][next.y] = 1;
			}
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string txt;
		cin >> txt;
		for (int j = 0; j < txt.length(); j++) {
			if (txt[j] == 'R') map[i][j] = 1;
			else if (txt[j] == 'G') map[i][j] = 2;
			else if (txt[j] == 'B') map[i][j] = 3;
		}
	}
	int cntNormal = 0;
	int cntUnNormal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visitedNormal[i][j]) {
				bfsSearchNormal({ i, j });
				cntNormal++;
			}
			if (!visitedUnNormal[i][j]) {
				bfsSearchUnNormal({ i, j }, map[i][j]);
				cntUnNormal++;
			}
		}
	}
	cout << cntNormal<<" "<<cntUnNormal;
}