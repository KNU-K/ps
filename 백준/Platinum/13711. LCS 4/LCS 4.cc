#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int arr[100001];
int arr2[100001];
int lis[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr2[a] = i;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[arr2[a]] = i;
		
	}
	lis[1] = arr[1];
	int k = 1;
	for (int i = 2; i <= n;i++) {
		if (lis[k] < arr[i]) {
			lis[++k] = arr[i];
		}
		else {
			auto it = lower_bound(lis, lis + k , arr[i]);
			(*it) = arr[i];
		}
	}
	cout << k ;

}
//4 5 3 2 1
//5 4 3 1 2