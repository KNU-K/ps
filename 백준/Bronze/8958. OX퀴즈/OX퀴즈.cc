#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string scoreCase;
		cin >> scoreCase;
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < scoreCase.length(); i++) {
			if (scoreCase[i] == 'O') {
				sum += ++cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << sum << "\n";
	}
}