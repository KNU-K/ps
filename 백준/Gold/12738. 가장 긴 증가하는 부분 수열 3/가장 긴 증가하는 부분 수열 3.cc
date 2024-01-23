#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001] = { 0, };
int lis[1000001] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[0];
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (lis[k]<arr[i]) {
			lis[++k] = arr[i];
		}
		else {
			int* idx = lower_bound(lis, lis + k+1, arr[i]);
			*idx = arr[i];
		}
	}
	cout << k + 1;

}