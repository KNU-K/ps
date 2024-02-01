#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#define ll long long
using namespace std;

int main() {
	/*
	0 : 4 - 0
	1 : overraped
	2 : overraped 4
	3 : overraped 20
	5*4-4
	
	*/
	int n;
	cin >> n;
	int a = 2;
	//24
	/**
	3*3 =9
	5*5 = 25
	7*7 = 49

	**/
	for (int i = 1; i <= n; i++) {
		a = a*2-1;
	}
	cout << a*a;
}
