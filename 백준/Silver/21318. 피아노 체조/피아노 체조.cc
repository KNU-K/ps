#include <iostream>
#include <vector>
using namespace std;
int mat[100002] = { 0, };
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n - 1; i++) {
		if (v[i] > v[i + 1]) {
			mat[i + 1] = 1;
		}
		mat[i + 1] += mat[i];
	}

	int q;
	cin >> q;


	for (int i = 0; i < q; i++) {
		int s, e;
		cin >> s >> e;
		cout << mat[e-1] - mat[s - 1] << "\n";
	}



}