#include <iostream>
#include <queue>
#define MAX_MAP_SZ 51
using namespace std;


/*
(INPUT)
n m
r c d 로봇의 좌표 및 바라보는 방향
map
*/
typedef struct {
	int x;
	int y;
}POINT;

typedef struct {
	POINT p;
	int direct;
	/* 
	*  direct info
	   0 : 북, 위
	   1 : 동, 오른
	   2 : 남, 아래
	   3 : 서  왼
	   */

}ROBOT;
// 1, 0 3 2 1
// 0, 3 2 1 0
// 3, 2 1 0 3
// 2, 1 0 3 2
ROBOT robot;
POINT dirs[4] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int seqs[4][4] = {
	{3,2,1,0},
	{0,3,2,1},
	{1,0,3,2},
	{2,1,0,3}
};
int reverses[4] = {
	2,
	3,
	0,
	1
};
int map[MAX_MAP_SZ][MAX_MAP_SZ];

int n, m;
int cnt = 0;
bool isMapLimited(int nx,int ny) {
	return (0 <= nx && nx < n) && (0 <= ny && ny < m);
}
void bfs() {
	queue<POINT> q;
	q.push(robot.p);
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		bool isMovable = false;
		q.pop();
		if (map[cx][cy] == 0) {
			map[cx][cy] = 2;
		}
		//0, 1, 2, 3
		//1, 2, 3, 0
		
		for (auto seq: seqs[robot.direct]) {
			int nd = seq;
			int nx = dirs[nd].x + cx;
			int ny = dirs[nd].y + cy;
			if (map[nx][ny] == 0) {
				map[nx][ny] = 2;
				robot.direct = nd;
				q.push({ nx,ny });
				//backtracking 용
				isMovable = true;
				break;
			}
		}

		//사방이 막혔을 때
		if (isMovable == false) {
			//후진
			int bx = cx+dirs[reverses[robot.direct]].x;
			int by = cy+dirs[reverses[robot.direct]].y;
			if (map[bx][by]!=1 && isMapLimited(bx, by)) {
				q.push({ bx,by });
			}
			else {
				return;
			}
		}

		/*
		1.현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
			1.바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
			2.바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
		3.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
			1. 반시계 방향으로 90도 회전한다.
			2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			3. 1번으로 돌아간다.
		*/
	}
}
int main() {
	cin >> n >> m;
	cin >> robot.p.x >> robot.p.y >> robot.direct;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			// 0 : 청소가 안된 칸, 1: 청소가 된 칸
			cin >> map[i][j];
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 0 : 청소가 안된 칸, 1: 청소가 된 칸
			
			if (map[i][j] == 2)cnt++;
		}

	}

	cout << cnt << "\n";
}