#include <iostream>
using namespace std;
int main() {
	int h, m;
	int m2;
	cin >> h >> m;
	cin >> m2;
	m += m2;

	h += (m / 60);
	m %= 60;
	cout << (h % 24) << " " << m;
}