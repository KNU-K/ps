#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
queue<int> q;
int mat[100001] = { 0, };
int visit[100001] = { 0, };
int cycle[100001] = { 0, };
int n;
int cnt = 0;
void search(int v) {
	visit[v] = 1;
	int v1 = mat[v];

	if (visit[v1] == 0) {
		search(v1);
	}
	else if (cycle[v1] == 0) {
		for (int i = v1; i != v; i = mat[i]) {
			cnt++;
		}
		cnt++;
	}
	cycle[v] = 1;
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mat[i];
	}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) search(i);
		}
		cout << n - cnt << "\n";
		cnt = 0;
        
		memset(visit, 0, sizeof(visit));
		memset(cycle, 0, sizeof(cycle));
	}

}