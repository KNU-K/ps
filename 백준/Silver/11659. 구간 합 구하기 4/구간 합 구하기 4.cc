#include <iostream>
using namespace std;
int arr[100001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		int x;
		cin >> x;
		arr[i] += arr[i - 1] +x;
	}
	for (int i = 0; i < m;i++) {
		int x, y;
		cin >> x >> y;
		cout << arr[y] - arr[x - 1]<<"\n";
	}
}