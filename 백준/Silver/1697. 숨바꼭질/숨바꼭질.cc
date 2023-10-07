#include <iostream>
#include <queue>
using namespace std;
typedef struct POINT {
    int x;
    int time;
}point;
bool visited[100001] = { 0, };
bool isBeyondRange(int x) {
    return 0 <= x && x <= 100000;
}
void probingPoint(queue<point> &q, int nextX, int nextTime) {
    if (isBeyondRange(nextX) && !visited[nextX]) {
        visited[nextX] = true;
        q.push({ nextX,nextTime });
    }
}
int bfsSearch(int n, int k) {
    queue<point> q;
    q.push({ n,0 });
    visited[n] = true;
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        if (cur.x == k) {
            return cur.time;
        }
        probingPoint(q, cur.x + 1, cur.time + 1);
        probingPoint(q, cur.x - 1, cur.time + 1);
        probingPoint(q, cur.x * 2, cur.time + 1);
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfsSearch(n, k);
}