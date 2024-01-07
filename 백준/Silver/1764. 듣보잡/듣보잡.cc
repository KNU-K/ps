#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n, m;
	map<string,int> map;
	vector<string> v;
	cin >> n >> m;
	string name;
	for (int i = 0; i < n;i++) {
		cin >> name;
		map[name]++;
	}
	for (int i = 0; i < m;i++) {
		cin >> name;
		map[name]++;
		if (map[name] > 1) {
			v.push_back(name);
		}
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << "\n";
	}
}