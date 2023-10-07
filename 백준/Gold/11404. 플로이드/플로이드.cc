#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int map[101][101] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		map[v1][v2] = min(map[v1][v2], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] > 0 && map[k][j] > 0) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF) {
				cout << 0 << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}