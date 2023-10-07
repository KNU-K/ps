#include <iostream>
#define max(a,b) (a>b ? a : b)
using namespace std;
int arr[1001][1001] = { 0, };
int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i <= s1.length();i++) {
		for (int j = 0; j <= s2.length(); j++) {
			if (i == 0 || j == 0)
				arr[i][j] = 0;
		}
	}

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) ;

			}
		}
	}
	printf("%d", arr[s1.length()][s2.length()]);

}