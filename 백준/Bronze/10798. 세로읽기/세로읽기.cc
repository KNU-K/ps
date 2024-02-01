

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int main() {
	queue<char> a[5];
	for (int i = 0; i < 5; i++) {
		string x;
		cin >> x;
		for (auto e : x) {
			a[i].push(e);
		}
	}
	for (int d = 0; d < 15;d++) {
		for (int i = 0; i < 5; i++) {
			if (a[i].empty())continue;
			cout << a[i].front();
			a[i].pop();
		}
	}
}