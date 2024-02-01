

#include <iostream>
using namespace std;
int main() {
	string alpha;
	cin >> alpha;

	/*
	ljes=njak
	6
	*/
	int word_cnt = 0;
	int total_cnt = 0;
	for (int i = 1; i < alpha.length();i++) {
		if (alpha[i] == '=') {
			if (alpha[i - 1] == 'c' || alpha[i - 1] == 's' || alpha[i - 1] == 'd' || alpha[i - 1] == 'z') {
				if (i-2>=0&&(alpha[i - 1] == 'z'&& alpha[i - 2] == 'd')) {
					word_cnt++;
					total_cnt += 3;
				}
				else {
					word_cnt++;
					total_cnt += 2;
				}
			}
		}
		else if (alpha[i] == 'j') {
			if (alpha[i - 1] == 'l' || alpha[i - 1] == 'n' )
			{
				word_cnt++;
				total_cnt+=2;
			}

		}
		else if(alpha[i] == '-') {
			if (alpha[i - 1] == 'c' || alpha[i - 1] == 'd')
			{
				word_cnt++;
				total_cnt += 2;
			}
		}
	}
	cout << word_cnt+(alpha.length() - total_cnt);
}

