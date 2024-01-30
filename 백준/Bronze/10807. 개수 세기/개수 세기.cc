#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}
	int k;
	cin >> k;
	sort(v.begin(), v.end());
	auto lower = lower_bound(v.begin(), v.end(), k);
	auto upper = upper_bound(v.begin(), v.end(), k);
	cout << (upper - v.begin()) - (lower - v.begin()) << "\n";
}