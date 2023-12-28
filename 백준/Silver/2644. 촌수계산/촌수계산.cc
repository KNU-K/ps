#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int visited[104] = { 0, };
int n, m, x, y;

void dfs_search(int sv, int prev) {

    if (prev == -1) {
        visited[sv] = 1;
    }
    else {
        visited[sv] = visited[prev] + 1;
    }

    if (sv == y) {
        return;
    }

    for (auto cur : map[sv]) {
        if (visited[cur] == 0) {
            dfs_search(cur,sv);
        }
    }
}

int main() {
    int a, b;

    cin >> n;
    cin >> x >> y;
    cin >> m;
    map.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfs_search(x, -1);
    cout << visited[y]-1 << "\n";



}