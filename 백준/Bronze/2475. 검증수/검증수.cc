#include <iostream>
using namespace std;
int cords[5];
int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> cords[i];
		cords[i] = cords[i] * cords[i];
		sum += cords[i];
	}
	sum %= 10;
	cout << sum;

}