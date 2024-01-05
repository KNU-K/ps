#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int x;
	int y;
	int cost;
}edge;

vector<edge> v;
int parent[1001];

int _find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = _find(parent[x]);
}
void _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x > y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
bool cmp(edge &e1, edge& e2) {
	return e1.cost < e2.cost;
}
int main() {
	vector<pair<int,int>> ans;
	int n, m;
	int result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v.push_back({ x,y,c });
	}
	
	sort(v.begin(), v.end(), cmp);
	for (auto e: v) {
		if (_find(e.x) != _find(e.y)) {
			_union(e.x, e.y);
			result += e.cost;
		}
	}
	cout << result;

}