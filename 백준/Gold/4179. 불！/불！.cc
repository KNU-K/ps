#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int x, y;
}pos;
pos dir[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
int map[1002][1002] = { 0, };
int visited[1002][1002] = { 0, };
int fireVisited[1002][1002] = { 0, };
queue<pair<int, int>> jihoon;
queue<pair<int, int>> fire;
int r, c;
int isMapLimited(int nx, int ny) {
    return (0 <= nx && nx < r) && (0 <= ny && ny < c);
}
int bfsSearch() {
    while (!jihoon.empty()) {
        if (!fire.empty()) {
            int curFireSize = fire.size();
            for (int j = 0; j < curFireSize; j++) {
                pair<int, int> curF = fire.front();
                fire.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = curF.first + dir[i].x;
                    int ny = curF.second + dir[i].y;
                    if (!isMapLimited(nx, ny)) continue;
                    if (map[nx][ny] == 0 && !fireVisited[nx][ny]) {
                        map[nx][ny] = 1;
                        fireVisited[nx][ny] = 1;
                        fire.push({ nx,ny });
                    }
                }
            }
        }
        int curJHSize = jihoon.size();
        for (int j = 0; j < curJHSize; j++) {
            pair<int, int> curJH = jihoon.front();
            jihoon.pop();
            if (curJH.first == 0 || curJH.second == 0 || curJH.first == r - 1 || curJH.second == c - 1) {
                return visited[curJH.first][curJH.second];
            }
            for (int i = 0; i < 4; i++) {
                int nx = curJH.first + dir[i].x;
                int ny = curJH.second + dir[i].y;
                if (!isMapLimited(nx, ny)) continue;
                if (!visited[nx][ny] && map[nx][ny] == 0 && !fireVisited[nx][ny]) {
                    visited[nx][ny] = visited[curJH.first][curJH.second] + 1;
                    jihoon.push({ nx,ny });
                }
            }
        }
    }
    return 0;
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            switch (c)
            {
            case '#':
                map[i][j] = 1;
                break;

            case '.':
                map[i][j] = 0;
                break;

            case 'J':
                jihoon.push({ i,j });
                visited[i][j] = 1;
                break;

            case 'F':
                map[i][j] = 1;
                fire.push({ i,j });
                fireVisited[i][j] = 1;
                break;

            default:
                break;
            }
        }
    }
    int result = bfsSearch();
    if (result) {
        printf("%d", result);
    }
    else{
        printf("IMPOSSIBLE");
    }

}