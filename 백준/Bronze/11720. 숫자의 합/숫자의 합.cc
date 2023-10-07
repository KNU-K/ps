#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int main() {
	int t;
	cin >> t;
	int sum = 0;
	string txt;
	cin >> txt;
	for (int i = 0; i < txt.length(); i++) {
		string operand = "";
		operand+= txt[i];
		sum += stoi(operand);
	}
	cout << sum;
}