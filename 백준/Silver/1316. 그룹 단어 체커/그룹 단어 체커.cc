
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int t;
	cin >> t;
	int rs = 0;
	while (t--) {
		string txt;
		cin >> txt;
		bool isCheck = false;

		for (int i = 0; i < txt.length()-1;i++) {
			if (txt[i] != txt[i + 1]) {
				for (int j = i + 1; j < txt.length(); j++) {
					if (txt[i] == txt[j]) {
						isCheck = true;
						break;
					}
				}
			}
		}

		if (!isCheck) {
			rs++;
		}
		else {
			isCheck = false;
		}
	}
	cout << rs;
}

