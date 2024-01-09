#include <iostream>
using namespace std;
int parent[500001];
int _find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = _find(parent[x]);
}
void _union(int x, int y){
	x = _find(x);
	y = _find(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		parent[i] = i;
	}
	bool isCycle = false;
	int cnt = 0;
	for (int i = 0; i < m;i++) {
		int x, y;
		cin >> x >> y;
		if (!isCycle) {
			cnt++;
		}
		if (_find(x) == _find(y)) {
			isCycle = true;
		}
		else {
			_union(x, y);
		}
	}
	if (isCycle) {
		cout << cnt;
	}else {
		cout << 0;
	}
}