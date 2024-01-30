#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin >> n>> m;
	vector<int> v(n,0);
	
	for (int i = 0; i < m;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		for (int j = x-1; j < y; j++) {
			v[j] = z;
		}
	}
	for (auto e : v) {
		cout << e << " " ;
	}
}