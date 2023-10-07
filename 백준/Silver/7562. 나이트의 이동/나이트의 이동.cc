#include <iostream>
#include <queue>
#define endl "\n"
#define directionMaxCount 8
using namespace std;

typedef struct POINT {
    int x;
    int y;
}point;
point dir[8] = {
    {1,2},
    {1,-2},
    {-1,2},
    {-1,-2},
    {2,1},
    {2,-1},
    {-2,1},
    {-2,-1}
};
int visitCount[301][301] = { 0, };
int t;
int n;
bool isBeyondMap(point knightPostion) {
    return (0 <= knightPostion.x && knightPostion.x < n) && (0 <= knightPostion.y && knightPostion.y < n);
}
int fullSearchChessBoard(point knightCurrentPostion, point knightGoalPostion) {
    queue<point> knightPositions;
    knightPositions.push(knightCurrentPostion);
    visitCount[knightPositions.front().x][knightPositions.front().y] = 1;

    while (!knightPositions.empty()) {
        knightCurrentPostion = knightPositions.front();
        knightPositions.pop();

        if (knightCurrentPostion.x == knightGoalPostion.x && knightCurrentPostion.y == knightGoalPostion.y) {
            return visitCount[knightCurrentPostion.x][knightCurrentPostion.y];
        }
        for (int i = 0; i < directionMaxCount; i++) {
            point knightNextPosition = { dir[i].x + knightCurrentPostion.x, dir[i].y + knightCurrentPostion.y };
            if (isBeyondMap(knightNextPosition) && visitCount[knightNextPosition.x][knightNextPosition.y] == 0) {
                visitCount[knightNextPosition.x][knightNextPosition.y] = visitCount[knightCurrentPostion.x][knightCurrentPostion.y] + 1;
                knightPositions.push(knightNextPosition);
            }
        }
    }
    return -1;
}
void initialSetting() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visitCount[i][j] = 0;
        }
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        point knightCurrentPostion;
        point knightGoalPostion;
        initialSetting();
        cin >> knightCurrentPostion.x >> knightCurrentPostion.y;
        cin >> knightGoalPostion.x >> knightGoalPostion.y;
        cout << fullSearchChessBoard(knightCurrentPostion, knightGoalPostion)-1 << endl;

    }
}