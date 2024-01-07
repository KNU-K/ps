#include <iostream>
#include <stack>
using namespace std;
int dp[1002][1002] = { 0, };
int map[1001][1001];
int main() {
	stack<char> s;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.length();i++) {
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				map[i][j] = 2;
			}
			else {
				dp[i + 1][j + 1] = (dp[i][j + 1] > dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j]);
				if (dp[i][j + 1] > dp[i + 1][j]) {
					map[i][j] = 1;
				}
				else {
					map[i][j] = 0; //왼
				}
			}
		}
	}
	int i=b.length()-1, j=a.length()-1;
	int rs = dp[b.length()][a.length()];

	cout << rs<<"\n";
	string result = "";
	while (1) {
		if (map[i][j] == 0) {
			j--;
			if (j < 0) break;
		}
		else if (map[i][j] == 1) {
			i--;
			if (i < 0)break;
		}
		else {
			result = b[i]+result;
			i--;
			j--;
			if (i < 0 || j < 0) break;
		}
	}
	cout << result;
	


}