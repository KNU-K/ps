#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
bool binSearch(int s, int e, int target) {
	int mid = (s + e) / 2;
	if (s > e) return false;
	if (arr[mid] == target) {
		return true;
	}//왼
	else if(arr[mid] > target) {
		return binSearch(s, mid - 1, target);
	}//오
	else {
		return binSearch(mid+1, e, target);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		cout << binSearch(0,n-1,x)<<"\n";
	}

}