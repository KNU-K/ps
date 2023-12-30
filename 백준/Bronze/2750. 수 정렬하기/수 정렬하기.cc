#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool cmp(int& a, int& b) {
	return a < b;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for (auto e: v) {
		cout << e << "\n";
	}
}