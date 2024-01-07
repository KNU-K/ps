#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	while (1) {
		char cmd[101];
		stack<char> s;
		cin.getline(cmd, 101);
		bool isNop = false;
		if (strcmp(cmd,".") ==0) {
			break;
		}
		for (int i = 0; i < strlen(cmd);i++) {
			if (cmd[i] == '(') {
				s.push(cmd[i]);
			}
			else if (cmd[i] == ')') {
				if (!(!s.empty() && s.top() == '(')) {
					isNop = true;
					break;
				}
				s.pop();
			}
			else if (cmd[i] == '[') {
				s.push('[');
			}
			else if (cmd[i] == ']')
			{
				if (!(!s.empty() && s.top() == '[')) {
					isNop = true;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()|| isNop == true) {
			cout << "no" << "\n";
		}
		else {
			cout << "yes" << "\n";
		}
	}
}