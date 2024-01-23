#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[1000001] = { 0, };
int lis[1000001] = { 0, };
int rec[1000001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[0];
	int k = 0;
	int j = 1;
	rec[0] = 0;
	for (int i = 1; i < n; i++) {
		if (lis[k]<arr[i]) {
			lis[++k] = arr[i];
			rec[i] = k;
		}
		else {
			int* idx = lower_bound(lis, lis + k+1, arr[i]);
			*idx = arr[i];
			
			rec[i] = idx - lis;
		}
	}
	cout << k + 1<<"\n";
	stack<int> ans;
	for (int i = n-1; i >=0; i--) {
		if (rec[i] == k) {
			ans.push(arr[i]);
			k--;
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

}