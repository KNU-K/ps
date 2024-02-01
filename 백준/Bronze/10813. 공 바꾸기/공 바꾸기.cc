#include <iostream>
#include <vector>
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
		int temp = vec[x];
		vec[x] = vec[y];
		vec[y] = temp;
	}

	for (int i = 1; i <= n;i++) {
		cout << vec[i] << " ";
	}
}