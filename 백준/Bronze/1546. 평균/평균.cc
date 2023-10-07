#include <iostream>
#include <cstdio>
int scores[1001] = { 0, };
int main() {
	int t;
	double avg = 0;
	int maxNum = -1;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> scores[i];
		if (maxNum < scores[i]) {
			maxNum = scores[i];
		}
	}
	for (int i = 0; i < t; i++) {
		avg += ((scores[i] / (double)maxNum) * 100);
	}
	
	printf("%.4lf", avg / (double)t);
}