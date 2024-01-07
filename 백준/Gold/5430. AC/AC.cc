#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
deque<int> dq;
int k = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	int n;
	cin >> t;
	while (t--) {
		string cmd;
		string input;
		bool isError = false;
		int rvs = 1;
		cin >> cmd;
		cin >> n;
		cin >> input;
		input = input.substr(1,input.length()-2);
		
		string tmp = "";
		for (int i = 0; i < input.length();i++) {
			if ('0' <= input[i] && input[i] <= '9') {
				tmp += input[i];
			}
			else {
				dq.push_back(stoi(tmp));
				tmp = "";
			}
		}
		if(tmp != "")
			dq.push_back(stoi(tmp));
		for (int i = 0; i < cmd.length();i++) {
			if (cmd[i] == 'R') {
				rvs = (rvs == 0 ? 1 : 0);
			}
			else if (cmd[i] == 'D') {
				if (!dq.empty()) {
					if (rvs) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
				else {
					isError = true;
					break;
				}
			}
		}
		if (isError) {
			cout << "error" << "\n";
			continue;
		}

		if (dq.empty()) {
			cout << "[]" << "\n";
			continue;
		}
		int dqSize = dq.size();
		cout << "[";
		for (int i = 0; i < dqSize;i++) {
			if (i == dqSize - 1) {

				if (rvs) {
					cout <<dq.front();
				}
				else {
					cout <<dq.back();
				}
			}
			else {

				if (rvs) {
					cout << dq.front()<<",";
				}
				else {
					cout << dq.back()<<",";
				}
			}

				if (rvs) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
		}
		cout << "]\n";

	}
}