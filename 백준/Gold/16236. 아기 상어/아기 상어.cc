#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
}POINT;
POINT dirs[4] = {
	{-1,0},{0,-1},{0,1},{1,0}
};
typedef struct {
	POINT p;
	int dist;
}STATE;
STATE cur_state;
int map[21][21];
int visited[21][21] = { 0, };
int n;
int fishSize = 2; // 즉 먹어야하는 수
int eatCnt = 0;
bool isMapLimited(POINT p) {
	return (0 <= p.x && p.x < n) && (0 <= p.y && p.y < n);
}
// isExist 먹이
bool cmp(STATE& s1, STATE& s2) {
	if (s1.dist == s2.dist) {
		return (s1.p.x == s2.p.x) ?
			(s1.p.y < s2.p.y) : (s1.p.x < s2.p.x);
	}
	else {
		return s1.dist < s2.dist;
	}
}

bool isExistFish() {
	queue<POINT> baby_shark;
	vector<STATE> tryEat;
	baby_shark.push({ cur_state.p.x, cur_state.p.y });
	visited[cur_state.p.x][cur_state.p.y] = 1;
	int minDist = 999999;
	while (!baby_shark.empty()) {
		POINT cur = baby_shark.front();
		baby_shark.pop();
		if (map[cur.x][cur.y] != 0 && map[cur.x][cur.y] < fishSize) {
			if (minDist >= visited[cur.x][cur.y]) {
				tryEat.push_back({ { cur.x, cur.y }, visited[cur.x][cur.y] - 1 });
				minDist = visited[cur.x][cur.y];
			}
			else {
				continue;
			}
			//eatCnt++;
			//cur_state = { {cur.x, cur.y}, visited[cur.x][cur.y] -1};
		}
		for (auto dir : dirs) {
			POINT next = { cur.x + dir.x, cur.y + dir.y };
			if (!isMapLimited(next)) continue;
			if (visited[next.x][next.y] != 0) continue;
			if (map[next.x][next.y] > fishSize) continue;
			baby_shark.push(next);
			visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
		}
	}
	if (tryEat.empty())
		return false;
	else {
		sort(tryEat.begin(), tryEat.end(), cmp);
		map[tryEat[0].p.x][tryEat[0].p.y] = 0;
		eatCnt++;
		cur_state = { {tryEat[0].p.x, tryEat[0].p.y}, visited[tryEat[0].p.x][tryEat[0].p.y] - 1};
		return true;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				cur_state = { {i,j} ,0 };
			}
		}
	}
	int rs=0;
	while (isExistFish()) {
		rs += cur_state.dist;
		if (eatCnt == fishSize) {
			fishSize++;
			eatCnt = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				visited[i][j] = 0;
			}
			//system("pause");'
		}
	}
	cout << rs << "\n";

	
}