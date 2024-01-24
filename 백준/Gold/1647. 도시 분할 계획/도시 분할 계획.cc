#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int c;
	int v, u;
}EDGE;
vector<EDGE> edge;
int parent[100001];
int _find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = _find(parent[x]);
}
void _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
bool cmp(EDGE& e1, EDGE& e2) {
	return e1.c < e2.c;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m;i++) {
		int v, u, c;
		cin >> v >> u >> c;
		edge.push_back({ c,v,u });
	}
	sort(edge.begin(), edge.end(), cmp);
	int sum = 0;
	int cnt = 0;
	for (auto e:edge) {
		if (n - 2 == cnt) break;
		if (_find(e.v) != _find(e.u)) {
			_union(e.v, e.u);
			sum += e.c;
			cnt++;
		}
	}
	cout << sum;
}