#include <iostream>
using namespace std;
int sleep[5005] = { 0, };
int mat[5005] = { 0, };
/*
N : 학생의 수
K : 졸고 있는 학생의 수
Q : 지환이가 출석 코드를 보낼 학생의 수
M : 구간의 수

졸고있는 학생 : 7
출석코드가 있는 학생 : 3 5 7

3 4 5 6 7 8 9 10 11 12

3 6 9 12
5 10
7 --> 졸고 있음

4 7 8 11 

*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, q, m;
	int s, e;
	cin >> n >> k >> q >> m;

	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		sleep[x] = 1;
	}


	for (int i = 1; i <= q; i++) {
		int x;
		cin >> x;
		if (!sleep[x]) {
			for (int j = x; j <= n + 2; j +=x) {
				if (!sleep[j]) {
					mat[j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <=n+2 ; i++) {
		mat[i] += mat[i - 1];
	}
	for (int i = 0; i < m;i++) {
		cin >> s >> e;
		cout << (e - s + 1) - (mat[e] - mat[s - 1]) <<"\n";
	}
	return 0;
}