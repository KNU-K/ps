#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> vec[10001];
vector<int> vec2[10001];
stack<int> fin;
vector<int> result[10001];
int res = 0;
int visited[10001] = { 0, };
int visited2[10001] = { 0, };
void dfs(int cv) {
	visited[cv] = 1;
	for (auto nv : vec[cv]) {
		if (!visited[nv]) {
			dfs(nv);
		}
	}
	fin.push(cv);

}
void dfs2(int cv) {
	visited2[cv] = 1;
	result[res].push_back(cv);
	for (auto nv : vec2[cv]) {
		if (!visited2[nv]) {
			dfs2(nv);
		}
	}
}
bool cmp(vector<int>& vec1, vector<int>& vec2) {
	return vec1[0] < vec2[0];
}
int main() {
	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		vec2[v2].push_back(v1);
	}


	for (int i = 1; i <= v;i++) {
		if(!visited[i])
			dfs(i);
	}

	while (!fin.empty()) {
		int finv = fin.top();
		fin.pop();
		if (!visited2[finv]) {
		
			dfs2(finv);
			res++;
		}
	}
	cout << res<<"\n";
	for (int i = 0; i < res; i++) {
		sort(result[i].begin(), result[i].end());
	}
	sort(result, result+res,cmp);
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("-1\n");
	}


}
