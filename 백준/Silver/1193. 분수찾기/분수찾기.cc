#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#define ll long long
using namespace std;

int main() {
	int i = 0, j = 0;
	int n;
	int total = 0;
	cin >> n;
	if (n == 1) {
		cout << i+1 << "/" << j+1 << "\n";
		return 0;
	}
	else {
		j = 1;
		total+=2;
	}
	if (total == n) {
		cout << i+1 << "/" << j+1 << "\n";
		return 0;
	}
	for (int x = 0;;x++) {
		if (i ==0) {
			while (j) {
				j--;
				i += 1;
				total++;
				if (total == n) {
					cout << i+1 << "/" << j+1 << "\n";
					return 0;
				}
			}

			i++;
			total++;
			if (total == n) {
				cout << i+1 << "/" << j+1 << "\n";
				return 0;
			}
		}
		else {
			while (i) {
				i--;
				j += 1;
				total++;
				if (total == n) {
					cout << i+1 << "/" << j+1 << "\n";
					return 0;
				}
 			}
			j++;
			total++;
			if (total == n) {
				cout << i+1 << "/" << j+1 << "\n";
				return 0;
			}
		}
	}
}
//0 0
//0 1
//1 0
//2 0
//1 1
//0 2
//0 3
//1 2
//2 1
//3 0
