#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001] = { 0, };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		arr[x] ++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) continue;
		for (int j = 0; j < arr[i];j++) {
			cout << i << "\n";
		}
	}
}