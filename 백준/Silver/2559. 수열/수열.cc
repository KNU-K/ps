#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001] = { 0, };
int ret = -10000001;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = k; i <= n; i++) {
		ret = max(ret, arr[i] - arr[i - k ]);
	}
	cout << ret;

	
}              