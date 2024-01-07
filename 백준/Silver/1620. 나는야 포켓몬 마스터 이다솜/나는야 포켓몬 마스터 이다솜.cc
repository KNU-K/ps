#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	map<string, int> maps;
	map<int, string> maps2;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		string name;
		cin >> name;
		maps[name] = i;
		maps2[i] = name;
	}
	for (int i = 1; i <= m; i++) {
		string cmd;
		cin >> cmd;
		if ('0' <= cmd[0] && cmd[0] <= '9') {
			int a=stoi(cmd);
			cout <<maps2[a]<<"\n";
		}
		else {
			cout << maps[cmd] << "\n";
		}
	}
}