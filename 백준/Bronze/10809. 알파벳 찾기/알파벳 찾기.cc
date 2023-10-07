#include <iostream>
int alpha[28];
using namespace std;

int main() {
	string txt;
	cin >> txt;	
	for (int i = 0; i <= 'z' - 'a'; i++) {
		alpha[i] = -1;
	}
	for (int i = 0; i < txt.length(); i++) {
		if(alpha[txt[i] -'a'] == -1)
			alpha[txt[i] - 'a'] = i;
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		cout << alpha[i]<<" ";
	}
}