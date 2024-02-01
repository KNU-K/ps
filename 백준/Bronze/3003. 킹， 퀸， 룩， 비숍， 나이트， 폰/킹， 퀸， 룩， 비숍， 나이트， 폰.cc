#include <iostream>
using namespace std;

int main() {
	int arr[6];
	for (int i = 0; i < 6;i++) {
		cin >> arr[i];
		switch (i) {
		case 0:
			arr[i] = 1 - arr[i];
			break;
		case 1:
			arr[i] = 1 - arr[i];
			break;
		case 2:
			arr[i] = 2 - arr[i];
			break;
		case 3:
			arr[i] = 2 - arr[i];
			break;
		case 4:
			arr[i] = 2 - arr[i];
			break;
		case 5:
			arr[i] = 8 - arr[i];
			break;
		}
	}
	for (int i = 0; i < 6;i++) {
		cout << arr[i] << " ";
	}

}