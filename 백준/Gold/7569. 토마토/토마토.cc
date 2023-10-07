#include <iostream>
#include <queue>
using namespace std;
typedef struct POINT {
	int z,x, y;
}p;
//정수 1 : 익은 토마토 (pivot)
//정수 0 : 익지 않은 토마토
//정수 -1 : 토마토가 들어있지않은칸
int box[101][101][101] = { 0, };
int y, x, boxCount;
queue<p> ripedTomatos;
p dir[6] = {
	{0,0,1},
	{0,0,-1},
	{0,1,0},
	{0,-1,0},
	{1,0,0},
	{-1,0,0}};
bool isMapLimited(p v) {
	return (0 <= v.z && v.z < boxCount) && (0 <= v.x && v.x < x) && (0 <= v.y && v.y < y);
}
void bfsSearch() {
	while (!ripedTomatos.empty()) {
		p cur = ripedTomatos.front();
		ripedTomatos.pop();

		for (int i = 0; i < 6; i++) {
			p next = { cur.z + dir[i].z,cur.x + dir[i].x ,cur.y + dir[i].y};
			if (!isMapLimited(next)) continue;
			if (box[next.z][next.x][next.y] == 0) {
				box[next.z][next.x][next.y] = box[cur.z][cur.x][cur.y] + 1;
				ripedTomatos.push(next);
			}
		}
	}
}
int main() {

	cin >> y >> x >> boxCount;
	for (int k = 0; k < boxCount; k++) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) ripedTomatos.push({ k,i,j });
			}
		}
	}
	bfsSearch();
	int maxResult = -1;
	for (int k = 0; k < boxCount; k++) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (box[k][i][j] == 0) {
					cout << "-1";
					return 0 ;
				}
				else if (box[k][i][j] == -1) {
					continue;
				}
				else {
					if (maxResult < box[k][i][j]) {
						maxResult = box[k][i][j];
					}
				}
			}
		}
	}
	cout << maxResult-1;
}