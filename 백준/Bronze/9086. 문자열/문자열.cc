#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string x;
		cin >> x;
		cout << x[0] << x[x.length() - 1]<<"\n";
	}
}