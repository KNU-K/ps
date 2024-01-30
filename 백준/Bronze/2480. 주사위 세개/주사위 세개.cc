#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;

	if (x == y && y == z) {
		cout << 10000 + y * 1000;
		return 0;
	}
	else if(x!=y && y!=z && x !=z){
		int c = max(x, max( y, z));
		cout << c * 100;
		return 0;
	}
	else {
		if (x == y) {
			cout <<1000 + x * 100;
			return 0;
		}
		else if (y == z) {

			cout << 1000 + y * 100;
			return 0;
		}
		else {
			cout << 1000 + z * 100;
			return 0;

		}
	}
}