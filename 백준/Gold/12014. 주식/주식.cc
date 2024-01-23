#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int arr[10001];
int lis[10001];
int main() {
	int t;
	cin >> t;
	int iiii = 1;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		lis[1] = arr[1];
		int k = 1;
		for (int i = 2; i <= n; i++) {
			if (lis[k] < arr[i]) {
				lis[++k] = arr[i];
			}
			else {
				auto it = lower_bound(lis, lis + k, arr[i]);
				(*it) = arr[i];
			}
		}
		cout << "Case #" << iiii++ << "\n";
		cout << (k >= m ? 1 : 0) << "\n";
	}
}
//4 5 3 2 1
//5 4 3 1 2