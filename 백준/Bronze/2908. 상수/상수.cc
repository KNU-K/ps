#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
	string operand1, operand2;
	cin >> operand1 >> operand2;
	reverse(operand1.begin(), operand1.end());
	reverse(operand2.begin(), operand2.end());

	int a = stoi(operand1);
	int b = stoi(operand2);
	cout << (a > b ? a : b);
}
