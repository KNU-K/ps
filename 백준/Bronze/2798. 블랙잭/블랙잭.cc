#include <iostream>
#define abs(a) (a<0?a*-1: a)
using namespace std;
int cards[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		cin >> cards[i];
	}
	int resultSum = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				int sumCards = (cards[i] + cards[j] + cards[k]);
				if (abs(m - resultSum) > abs(m - sumCards)) {
					resultSum = sumCards;
				}

			}
		}
	}
	cout << resultSum;
}
