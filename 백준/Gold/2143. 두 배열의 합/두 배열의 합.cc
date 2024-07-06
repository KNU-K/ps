#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long arr1[1002] = { 0, };
long long arr2[1002] = { 0, };
vector<long long> a;
vector<long long> b;
int main() {
	long long t;
	long long n, m;
	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
		arr1[i] += arr1[i - 1];
		for (int j = 0; j <= i - 1;j++) {
			a.push_back(arr1[i] - arr1[j]);
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr2[i];
		arr2[i] += arr2[i - 1];
		for (int j = 0; j <= i - 1; j++) {
			b.push_back(arr2[i] - arr2[j]);
		}
	}

	sort(b.begin(), b.end());
	long long cnt = 0;

	for (auto e: a) {
		int start = lower_bound(b.begin(), b.end(), t - e) - b.begin();
		int end = upper_bound(b.begin(), b.end(), t - e) - b.begin();
		cnt += end - start;
	}
	cout << cnt << "\n";
}