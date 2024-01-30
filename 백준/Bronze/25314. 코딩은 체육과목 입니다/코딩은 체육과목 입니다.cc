#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n!=4) {
		cout << "long ";
		n -= 4;
	}
	cout << "long int";
}