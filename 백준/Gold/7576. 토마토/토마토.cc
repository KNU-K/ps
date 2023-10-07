#include <iostream>
#include <queue>
using namespace std;
typedef struct POINT {
    int x;
    int y;
};
POINT dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int m, n;
int mat[1001][1001] = { 0, };
queue<pair<int, int>> tomatos;
bool mapLimited(int nx, int ny) {
    return (0 <= nx && nx < n) && (0 <= ny && ny < m);
}
void bfsSearch() {
    while (!tomatos.empty()) {
        int x = tomatos.front().first;
        int y = tomatos.front().second;
        tomatos.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i].x;
            int ny = y + dir[i].y;

            if (mapLimited(nx, ny) && mat[nx][ny] == 0) {
                mat[nx][ny] = mat[x][y] + 1;
                tomatos.push({ nx,ny });
            }
        }
    }
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                tomatos.push({ i,j });
            }
        }
    }

    bfsSearch();
    int maxResult = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            else if (mat[i][j] != -1) {
                if (maxResult < mat[i][j]) {
                    maxResult = mat[i][j];
                }
            }
        }
    }
    cout << maxResult-1;
}