#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#define ll long long
using namespace std;

int main() {
	int arr[] = {
		25,10,5, 1
	};
	int sizeOfArr = sizeof(arr) / sizeof(int);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 0; i < sizeOfArr;i++) {
			cout << (int)(x / arr[i]) << " ";
			x %= arr[i];
		}
		cout << "\n";
	}
}