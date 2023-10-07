#include <iostream>
using namespace std;
void findPalindrome(string num) {
	for (int i = 0; i < num.length(); i++) {
		if (num[i] != num[num.length() - 1 - i]) {
			cout << "no\n";
			return;
		}
	}
	cout << "yes\n";
}
int main() {
	while (1) {
		string num;
		cin >> num;
		if (num == "0") return 0;
		findPalindrome(num);
	}
}