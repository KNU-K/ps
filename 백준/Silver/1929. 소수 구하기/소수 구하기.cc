#include <iostream>
using namespace std;

bool primeNumber[1000001];

int main() {
	//false;
	for (int i = 2; i <= 1000000; i++) {
		primeNumber[i] = true;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (primeNumber[i]) {
			for (int j = i * 2; j <= 1000000; j = j+i) {
				primeNumber[j] = false;
			}
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m;i++) {
		if (primeNumber[i]) {
			cout << i<<"\n";
		}

	}
}