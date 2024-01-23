#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[2001] = { 0, };
int lis[2001] = { 0, };
int rec[2001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[n-1];
	int k = 0;
	int j = 1;
	rec[0] = 0;
	for (int i = n-2; i >=0; i--) {
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
	cout << n-(k + 1)<<"\n";

}