#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> POINT;

POINT dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<string>& map, int w, int h) {
    queue<POINT> fire;
    queue<POINT> man;
    
    vector<vector<int>> visited(h, vector<int>(w, -1));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '*') {
                fire.push({i, j});
            } else if (map[i][j] == '@') {
                man.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    while (!man.empty()) {
        int fireSz = fire.size();

        while (fireSz--) {
            POINT cur = fire.front();
            fire.pop();
            
            for (int i = 0; i < 4; i++) {
                POINT next = {cur.first + dir[i].first, cur.second + dir[i].second};
                if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w &&
                    map[next.first][next.second] == '.') {
                    map[next.first][next.second] = '*';
                    fire.push(next);
                }
            }
        }

        int manSz = man.size();
        while (manSz--) {
            POINT cur = man.front();
            man.pop();

            if (cur.first == 0 || cur.first == h - 1 || cur.second == 0 || cur.second == w - 1) {
                return visited[cur.first][cur.second] + 1;
            }

            for (int i = 0; i < 4; i++) {
                POINT next = {cur.first + dir[i].first, cur.second + dir[i].second};
                if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w &&
                    map[next.first][next.second] == '.' && visited[next.first][next.second] == -1) {
                    man.push(next);
                    visited[next.first][next.second] = visited[cur.first][cur.second] + 1;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        vector<string> map(h);
        for (int i = 0; i < h; i++) {
            cin >> map[i];
        }

        int result = bfs(map, w, h);
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << result << "\n";
        }
    }

    return 0;
}
