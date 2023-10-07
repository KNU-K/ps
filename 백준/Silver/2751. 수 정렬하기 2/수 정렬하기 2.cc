#include <iostream>
#include <algorithm>
using namespace std;
int* arr;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	arr = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + t);
	
	for (int i = 0; i < t; i++) {
		cout << arr[i] <<"\n";
	}

}