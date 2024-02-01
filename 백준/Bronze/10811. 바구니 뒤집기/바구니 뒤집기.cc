#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++) {

		vec[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		reverse(vec.begin() + x, vec.begin() + y+1);
	}

	for (int i = 1; i <= n; i++) {
		cout << vec[i] << " ";
	}
}