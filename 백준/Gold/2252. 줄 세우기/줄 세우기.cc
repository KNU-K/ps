#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> vec[32001];
deque<int> result;
int visited[32001] = { 0, };
int degree[32001] = { 0, };
void dfs(int sv) {
	visited[sv] = 1;

	result.push_back(sv);
	for (auto nv : vec[sv]) {
		degree[nv]--;
		if (!visited[nv] && degree[nv] == 0) {
			dfs(nv);
		}
	}
	//fin
}
int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		degree[v2] ++;
	}
//	while () {
	while (result.size() != v) {
		for (int i = 1; i <= v; i++) {
			if (degree[i] == 0 && !visited[i]) {
				dfs(i);
			}

		}
	}
//	}
	while (!result.empty()) {
		printf("%d ", result.front());
		result.pop_front();
	}
}