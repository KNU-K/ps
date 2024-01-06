#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> operands;
	string inorderFix;
	cin >> inorderFix;

	for (auto e : inorderFix) {
		if (('A' <= e && e <= 'Z') || ('a' <= e && e <= 'z')){
			cout << e;
			continue;
		}
		
		if (e == '+' || e == '-') {
			if (operands.empty()) {
				operands.push(e);
				continue;
			}
			if (operands.top() == '*' || operands.top() == '/') {
				while (!operands.empty() && operands.top() != '(') {
					cout << operands.top();
					operands.pop();
				}
				operands.push(e);
			}
			else {
				if (!operands.empty() && (operands.top() == '+' || operands.top() == '-')) {
					cout << operands.top();
					operands.pop();
				}
				operands.push(e);
			}
		}
		else if(e=='*'|| e=='/') {
			if (operands.empty()) {
				operands.push(e);
				continue;
			}
			while (!operands.empty()&& (operands.top() == '*' || operands.top() == '/')) {
				cout << operands.top();
				operands.pop();
			}
			operands.push(e);

		}else if(e=='('){
			operands.push('(');
		}
		else if (e == ')') {
			while (operands.top() != '(') {
				cout << operands.top();
				operands.pop();
			}
			operands.pop();

		}
	}


	while (!operands.empty()) {
		cout << operands.top();
		operands.pop();
	}
}