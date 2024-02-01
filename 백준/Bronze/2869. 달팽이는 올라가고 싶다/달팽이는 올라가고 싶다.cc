#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//a b v
	/**
	snail will up as much as a meter at morning
	snail will down as much as b mter at evening
	하루
	a
	b
	v <= a*x+(-b)*x + a
	v <= a*x+ 
	1 <= (4)*0.25;
	0.25
	 

	**/
	double a, b, v;
	cin >> a >> b >> v;
	cout << (int)ceil(((((v - a) / (a - b)))) + 1);
}