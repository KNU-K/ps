#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int sw[10001];
int arr[10001];
int arr2[10001];
int lis[10001];
int record[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr2[a] = i;
		sw[i] = a;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[arr2[a]] = i;

	}
	lis[1] = arr[1];
	int k = 1;
	record[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (lis[k] < arr[i]) {
			lis[++k] = arr[i];
			record[i] = k;
		}
		else {
			auto it = lower_bound(lis, lis + k, arr[i]);
			(*it) = arr[i];
			record[i] = it - lis;
		}
	}
	cout << k<<"\n";
	stack<int> ans;
	for (int i = n; i >= 1;i--) {
		if (record[i] == k) {
			ans.push(sw[i]);
			k--;
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	
}
//4 5 3 2 1
//5 4 3 1 2

//1 3 5 4 2

// 5 1 3 2 4
