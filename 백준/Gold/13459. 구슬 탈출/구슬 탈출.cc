





#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
}POINT;
typedef struct {
	POINT red;
	POINT blue;
	int count;
}STATE_BALL;
POINT dir[4] = {
	{1,0},{-1,0},{0,1},{0,-1}
};
POINT red_ball;
POINT blue_ball;
POINT goal;
int n, m;
string map[11];
int visited[11][11][11][11] = { 0, };
void move_ball(POINT &p, int& distance, int&i) {
	while (map[p.x + dir[i].x][p.y + dir[i].y] != '#' && map[p.x][p.y] != 'O') {
		p = { p.x + dir[i].x, p.y + dir[i].y };
		distance += 1;
	}
}
void bfs() {
	queue<STATE_BALL> q;
	q.push({ red_ball, blue_ball,0 });
	visited[red_ball.x][red_ball.y][red_ball.x][red_ball.y] = 1;
	while (!q.empty()) {
		STATE_BALL cur = q.front();
		q.pop();

		if (cur.count >= 10) break;
		for (int i = 0; i < 4; i++) {
			STATE_BALL next = { cur.red, cur.blue,cur.count+1 };
			int red_distance=0;
			int blue_distnance=0;
			move_ball(next.red, red_distance, i);
			move_ball(next.blue, blue_distnance, i);
			
			if (map[next.blue.x][next.blue.y] == 'O') continue;
			if (map[next.red.x][next.red.y] == 'O') {
				std::cout << 1;
				return;
			}
			
			if (next.red.x == next.blue.x && next.red.y == next.blue.y) {
				if (red_distance > blue_distnance) {
					next.red.x -= dir[i].x;
					next.red.y -= dir[i].y;
				}
				else {
					next.blue.x -= dir[i].x;
					next.blue.y -= dir[i].y;

				}
			}
			if (visited[next.red.x][next.red.y][next.blue.x][next.blue.y]) continue;
			visited[next.red.x][next.red.y][next.blue.x][next.blue.y] = 1;
			q.push({ next.red, next.blue, next.count });
		}
	}
	std::cout << 0 << "\n";
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				red_ball = { i,j } ;
			}
			else if (map[i][j] == 'B') {
				blue_ball = { i,j } ;
			}
		}
	}

	bfs();
}