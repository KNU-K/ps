#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> f;
int parent[200001];
int rs[200001];

int _find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = _find(parent[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if (x != y) {
        if (rs[x] < rs[y]) swap(x, y);
        parent[y] = x;
        rs[x] += rs[y];
    }
}

int main() {
    int t;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        f.clear();
        f.resize(n * 2 + 1);
        unordered_map<string, int> index;

        for (int i = 0; i < 200001; i++) {
            parent[i] = i;
            rs[i] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string r1, r2;
            cin >> r1 >> r2;

            if (index.find(r1) == index.end()) {
                index[r1] = cnt;
                f[cnt++] = r1;
            }
            if (index.find(r2) == index.end()) {
                index[r2] = cnt;
                f[cnt++] = r2;
            }

            _union(index[r1], index[r2]);

            int root = _find(index[r1]);
            cout << rs[root] << "\n";
        }
    }

    return 0;
}
