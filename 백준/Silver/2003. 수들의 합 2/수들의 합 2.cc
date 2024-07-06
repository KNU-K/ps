#include <iostream>
using namespace std;
int arr[10001] = { 0, };
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int cnt = 0;
	for (int i = 0; i <= n-1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((arr[j] - arr[i]) == m) {
				cnt++;
			}
		}
	}
	cout << cnt;
}