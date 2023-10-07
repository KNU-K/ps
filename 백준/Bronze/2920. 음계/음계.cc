#include <iostream>
#define M 8
using namespace std;
int main() {
	bool asc = false, desending = false, mixed = false;
	for (int i = 1; i <= M; i++) {
		int x;
		cin >> x;
		if (x == i) {
			if (desending) {
				mixed = true;
				break;
			}
			asc = true;
		}
		else if (x == M - i + 1) {
			if (asc) {
				mixed = true;
				break;
			}
			desending = true;
		}
		else {
			mixed = true;
			break;
		}
	}
	if (mixed) cout << "mixed\n";
	else if (asc) cout << "ascending\n";
	else if (desending) cout << "descending\n";
}