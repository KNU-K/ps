




#include <iostream>
#include <algorithm>
using namespace std;
int map[10][10];
typedef struct {
	int x, y;
}POINT;
int main() {
	int rs = -1;
	POINT p;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (rs < map[i][j]) {
				rs = map[i][j];
				p = { i,j };
			}
		}
	}
	cout << rs << "\n";
	cout << p.x+1 << " " << p.y+1;
}