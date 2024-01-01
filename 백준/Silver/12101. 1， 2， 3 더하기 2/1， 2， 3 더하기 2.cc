#include <iostream>
#include <vector>
using namespace std;
int num[3] = { 1,2,3 };
int visited[4] = { 0, };
vector<int> v;
int n, k;
int cnt = 0;
bool isCan = false;
void dfs(int sum) {
	if (sum == n) {
		cnt = cnt + 1;
		if (cnt == k) {
			isCan = true;
			for (int i = 0; i < v.size();i++) {
				if (i == v.size() - 1) {
					cout << v[i];
				}
				else {
					cout << v[i]<<"+";
				}
			}
		}
	}
	for (int i = 0; i < 3;i++ ) {
		if (sum + num[i] <= n) {
			v.push_back(num[i]);
			dfs(sum + num[i]);
			v.pop_back();
		}
	}
}
int main() {
	cin >> n >> k;
	dfs(0);
	if (!isCan) {
		cout << -1 << "\n";
	}
	return 0;
}