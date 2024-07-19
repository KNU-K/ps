#include <iostream>
#include <vector>

using namespace std;
int mat[501] = { 0, };
int main() {
	int h, w;
	cin >> h >> w;
	int s = 0;
	int e = w;
	for (int i = 0; i < w;i++) {
		cin >> mat[i];
	}
	int rtn = 0;
	
	while (1) {
		for (int i = s; i < e; i++) {
			if (mat[i] == 0) {
				s = i+1;
			}
			else {
				break;
			}
		}
		for (int i = e - 1; i >= s; i--) {
			if (mat[i] == 0) {
				e = i;
			}
			else {
				break;
			}
		}
		if (s == e) break;
		for (int i = s; i < e;i++) {
			if(mat[i] !=0)
				mat[i]--;
			else {
				rtn++;
			}
		}
		
	}
	cout << rtn << "\n";

}