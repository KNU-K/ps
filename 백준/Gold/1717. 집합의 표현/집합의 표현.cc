#include <iostream>
using namespace std;
int parent[1000001];
int _find(int x) {
	if (parent[x] == x) {
		return parent[x];
	}
	return parent[x] = _find(parent[x]);
}
void _union(int a, int b) {
	a = _find(a);
	b = _find(b);

	if (a != b) {
		parent[a] = b;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, a, b;
		cin >> x;
		cin >> a >> b;
		if (x == 0) {
			_union(a,b);
		}
		else {
			if (_find(a) == _find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}