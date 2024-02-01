#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string temp;
	cin >> temp;
	string reverse_temp = temp;
	reverse(reverse_temp.begin(), reverse_temp.end());

	if (temp == reverse_temp) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}